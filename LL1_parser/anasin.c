#include <string.h>
#include <compiler.h>

#define LEN 32                 // lenght of ter + non-ter strings
#define MAX 32                 // maximum size of stack

char *NONTER[] = {"<PROG>","<SENTS>","<SENT>","<AUX0>","<AUX1>","<AUX2>","<AUX3>","<ELEM>","<COMPARA>"};
char *TER[] = {"PROGRAMA","FINPROG","[id]","=","[op_ar]","SI","ENTONCES","SINO","FINSI","REPITE","VECES","FINREP","IMPRIME","[txt]","LEE","#","[comentario]","[val]","[op_rel]","$"};        // include EOF "$"
char *rules[] = { "",                              // right side of rule separated by blank spaces!!
    "<PROG> -> PROGRAMA [id] <SENTS> FINPROG",      
    "<SENTS> -> <SENT> <AUX0>",                 
    "<AUX0> -> <SENTS>",                            
    "<AUX0> -> ",
    "<SENT> -> [id] = <ELEM> <AUX1>",               
    "<AUX1> -> [op_ar] <ELEM>",                 
    "<AUX1> -> ",
    "<SENT> -> SI <COMPARA> ENTONCES <SENTS> <AUX2>",
    "<AUX2> -> SINO <SENTS> FINSI",
    "<AUX2> -> FINSI",
    "<SENT> -> REPITE <ELEM> VECES <SENTS> FINREP",
    "<SENT> -> IMPRIME <AUX3>",
    "<AUX3> -> <ELEM>",
    "<AUX3> -> [txt]",
    "<SENT> -> LEE [id]",
    "<SENT> -> # [comentario]",
    "<ELEM> -> [id]",   
    "<ELEM> -> [val]",
    "<COMPARA> -> [id] [op_rel] <ELEM>" 
};

int LL1[][(int)(sizeof(TER)/sizeof(char *))] = {                                       // 0 = no transition in LL1 table - syntax error
    1, 0, 0,  0, 0, 0, 0, 0, 0,  0,  0, 0, 0,  0,  0,  0,  0, 0,  0, 0,
    0, 0, 2,  0, 0, 2, 0, 0, 0,  2,  0, 0, 2,  0,  2,  2,  0, 0,  0, 0,
    0, 0, 5,  0, 0, 8, 0, 0, 0,  11, 0, 0, 12, 0,  15, 16, 0, 0,  0, 0,
    0, 4, 3,  0, 0, 3, 4, 4, 4,  3,  4, 4, 3,  4,  3,  3,  4, 4,  4, 4,
    0, 7, 7,  7, 6, 7, 7, 7, 7,  7,  7, 7, 7,  7,  7,  7,  7, 7,  7, 7,
    0, 0, 0,  0, 0, 0, 0, 9, 10, 0,  0, 0, 0,  0,  0,  0,  0, 0,  0, 0,
    0, 0, 13, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0,  14, 0,  0,  0, 13, 0, 0,
    0, 0, 17, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0,  0,  0,  0,  0, 18, 0, 0,
    0, 0, 19, 0, 0, 0, 0, 0, 0,  0,  0, 0, 0,  0,  0,  0,  0, 0,  0, 0
};

const int T = (int)(sizeof(TER)/sizeof(char*));
const int NT = (int)(sizeof(NONTER)/sizeof(char*));

int idx(char **arr, char *src){
    int idx, lim = equal(arr[0],"PROGRAMA") ? T : NT;

    for(idx = 0; !equal(arr[idx],src) && idx < lim; idx++)
        ;
    if(idx == lim){
        printf("ERROR: %s not found in array %s\n",src,equal(arr[0],"PROGRAMA") ? "TER" : "NONTER");
        exit(-1);
    }
    return idx;
}

int isterminal(char *src){
    return search(TER,src);
}
    
char *revstr(char *src){
    int i, len = (int)strlen(src);
    static char out[100];
    
    for(i = 0; i < len; i++)
        out[i] = src[len - 1 - i];
    out[i] = 0;

    return out;
}

void pushrule(StackStr *p, char *rule){
    char *token = strtok(revstr(rule),"   "), aux[LEN];
    
    while(token && !equal(token,">-")){
        pushStr(p,revstr(strcpy(aux,token)));
        token = strtok(NULL,"  ");
    }
}

void printerror(int line, char *top, char *input){
    printf("\nLine %d: ",line);

    if(equal(top,"FINPROG"))
        printf("no FINPROG was found.");
    else if(equal(top,"="))
        printf("expected = operator after identifier");
    else if(equal(top,"<ELEM>"))
        printf("expected identifier or integer.");
    else
        ;
}

int main(int argc, char **argv){
    int line, index;
    char input[LEN], top[LEN], flag = argc < 3 ? 0 : 1;
    FILE *fsrc = fopen(argv[1],"r"), *flin = fopen(getnom(argv[1],".lin"),"r");
    StackStr parser;

    if(!fsrc){
        printf("\nNo file %s was found.\n\n",argv[1]);
        exit(-1);
    }
    
    initPila(&parser,MAX,LEN); 
    fscanf(fsrc,"%s",input);
    fscanf(flin,"%d",&line);
    pushStr(&parser,"$");
    pushStr(&parser,NONTER[0]);
    if(flag) printStr(parser);

    do {
        popStr(&parser,top);
        
        if(isterminal(top) && equal(top,input)){
            fscanf(fsrc,"%s",input);
            fscanf(flin,"%d",&line);
        }
        else if(!isterminal(top) && (index = LL1[idx(NONTER,top)][idx(TER,input)]))
            pushrule(&parser,rules[index]);
        else{
            err = TRUE;
            printerror(line,top,input);
        }
        
        if(flag) printStr(parser);
    } while( parser.sp != 0 );
    
    freePila(&parser);
    
    if(!err)
        printf("\nSuccesful parsing.\n\n");
    else
        printf("\n\nParsing failure.\n\n");
    
    return 0;
}
