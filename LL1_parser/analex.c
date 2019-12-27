#include <ctype.h>
#include <compiler.h>

#define MAXLEN 256
#define SIZE 64

char *keywords[] = {"PROGRAMA","FINPROG","SI","ENTONCES","SINO","FINSI","REPITE","VECES","FINREP","IMPRIME","LEE"};

int isoperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '>' || c == '<' || c == '#' || c == '=');
}

int is_blank(char c){
    return (c == ' ' || c == '\b' || c == '\n' || c == '\t' || c == '\r');
}

int ishexdec(char c){
    return (isdigit(c) || (c >= 65 && c <= 70) || (c >= 97 && c <= 102));
}
    
void pushtable(StackStr *p, char *src){
    if(!search(p->stack,src))
        pushStr(p,src);
}

int main(int argc, char **argv){
    int i, state, line = 1, linestr;
    char c, ulex[MAXLEN];
    FILE *fsrc = fopen(argv[1],"r"), *flex, *fsim, *flin;
    StackStr ids, val, txt;

    if(!fsrc){
        printf("\nNo file %s was found.\n\n",argv[1]);
        exit(-1);
    }    

    flex = fopen(getnom(argv[1],".lex"),"w");
    fsim = fopen(getnom(argv[1],".sim"),"w");
    flin = fopen(getnom(argv[1],".lin"),"w");
    initPila(&ids,SIZE,20);
    initPila(&val,SIZE,20);
    initPila(&txt,SIZE,MAXLEN);
    
    c = fgetc(fsrc);
    
    while(c != EOF){
        i = state = 0;
        
        if(c == '0'){
            ulex[i] = c; i++;
            c = fgetc(fsrc);
            if(c == 'x')
                state = 1;
            else if(is_blank(c) || isoperator(c)){
                printf("Line %d. Unknown variable 0. \n",line);
                err = TRUE;
                continue;
            }
        }
        else if(isalpha(c))
           state = 2;
        else if(c == '"')
            state = 3;
        else if(c == '#')
            state = 4;
        else if(is_blank(c))
            state = 5;
        else if(c == '+' || c == '-' || c == '*' || c == '/')
            state = 6;
        else if(c == '>' || c == '<')
            state = 7;
        else if(c == '=')
            state = 8;
        
        switch(state){
            case 1:                             // numerical variable
                do {
                    ulex[i] = c; i++;
                    c = fgetc(fsrc);
                } while(ishexdec(c));
                ulex[i] = 0;
                    
                if(equal(ulex,"0x") && (is_blank(c) || isoperator(c))){
                    printf("Line %d. Incomplete numerical variable %s \n",line,ulex);
                    err = TRUE;
                }
                else if(!is_blank(c) && !ishexdec(c) && !isoperator(c)){
                    while(!is_blank(c) && !isoperator(c)){
                        ulex[i] = c;
                        i++;
                        c = fgetc(fsrc);
                    }
                    ulex[i] = 0;
                    printf("Line %d. Incorrect numerical variable %s \n",line,ulex);
                    err = TRUE;
                }
                else{
                    fprintf(flex,"[val]\n");
                    fprintf(flin,"%d\n",line);
                    pushtable(&val,ulex);
                }
                break;
            
            case 2:                         // identifiers and keywords
                do {
                    ulex[i] = c; i++;
                    c = fgetc(fsrc);
                } while(isalnum(c) && i < 15);
                ulex[i] = 0;
                
                if(search(keywords,ulex)){                           // keyword
                    fprintf(flex,"%s\n",ulex);
                    fprintf(flin,"%d\n",line);
                }
                else if(isalnum(c) && i == 15){
                    while(!is_blank(c) && !isoperator(c)){
                        ulex[i] = c;
                        i++;
                        c = fgetc(fsrc);
                    }
                    ulex[i] = 0;
                        
                    printf("Line %d. Identifier is too long (15 characters maximum) \n",line);
                    err = TRUE;
                }
                else if(!is_blank(c) && !isoperator(c)){
                    while(!is_blank(c) && !isoperator(c)){
                        ulex[i] = c;
                        i++;
                        c = fgetc(fsrc);
                    }
                    ulex[i] = 0;
                        
                    if(ulex[i-1] == '"')
                        printf("Line %d. String is not properly closed between quote marks \n",line);
                    else
                        printf("Line %d. Unknown variable %s \n",line,ulex);
                    err = TRUE;
                }
                else{
                    fprintf(flex,"[id]\n");
                    fprintf(flin,"%d\n",line);
                    pushtable(&ids,ulex);
                }
                    
                break;
            
            case 3:                                             // string
                ulex[i] = c; i++; 
                linestr = line;
                c = fgetc(fsrc);
                    
                while(c != EOF && i < MAXLEN){
                    if(c == '"'){
                        ulex[i] = c; i++;
                        c = fgetc(fsrc);
                        break;
                    }
                    else{
                        ulex[i] = c; i++;
                        c = fgetc(fsrc);
                    }
                    if(c == '\n')
                        line++;
                    if(i == MAXLEN - 20)
                        printf("Line %d. Warning: String is too long (%d characters maximum)\n",linestr,MAXLEN);
                }
                ulex[i] = 0;
                    
                if(ulex[i-1] != '"'){
                    printf("Line %d. String is not properly closed between quote marks \n",line);
                    err = TRUE;
                }
                else{
                    fprintf(flex,"[txt]\n");
                    fprintf(flin,"%d\n",linestr);
                    pushtable(&txt,ulex);
                }
                break;
            
            case 4:                                 // commentary
                for(i = 0; c != '\n' && c != EOF && i <= 100; i++)
                    c = fgetc(fsrc);
                break;
            
            case 5:                                 // blank characters
                do {
                    if(c == '\n')
                        line++;
                    c = fgetc(fsrc);
                } while(is_blank(c) && c != EOF);
                break;
            
            case 6:
                fprintf(flex,"[op_ar]\n");
                fprintf(flin,"%d\n",line);
                c = fgetc(fsrc);
                    
                break;
            
            case 7:
                fprintf(flex,"[op_rel]\n");
                fprintf(flin,"%d\n",line);
                c = fgetc(fsrc);
                
                break;
            
            case 8:
                c = fgetc(fsrc);
                if(c == '='){
                    fprintf(flex,"[op_rel]\n");
                    fprintf(flin,"%d\n",line);
                    c = fgetc(fsrc);
                }
                else{
                   fprintf(flex,"=\n");
                   fprintf(flin,"%d\n",line);
                }
                    
                break;
            
            default:
                do {
                    ulex[i] = c; i++;
                    c = fgetc(fsrc);
                } while(!is_blank(c) && !isoperator(c));
                ulex[i] = 0;
                    
                printf("Line %d. Unknown variable %s\n",line,ulex);
                err = TRUE;
        }
    }
    fprintf(flex,"$\n");
    fprintf(flin,"%d\n",line-1);
    
    fclose(fsrc);    
    fclose(flin);
    fclose(flex);

    fprintf(fsim,"IDS\n");
    for(i = 0; i < ids.sp; i++)
        fprintf(fsim,"%s, ID%.2d \n",ids.stack[i],i);
   
    fprintf(fsim,"\nTXT\n");
    for(i = 0; i < txt.sp; i++)
        fprintf(fsim,"%s, TX%.2d \n",txt.stack[i],i);

    fprintf(fsim,"\nVAL\n");
    for(i = 0; i < val.sp; i++)
        fprintf(fsim,"%s, %d \n",val.stack[i],(int)strtol(val.stack[i],NULL,0));
    
    freePila(&ids);
    freePila(&val);
    freePila(&txt);
    fclose(fsim);
    
    if(err)
        printf("\nTokenizing failure.\n\n");
    else
        printf("\nSuccesful tokenizing.\n\n");
    
    return 0;
}
