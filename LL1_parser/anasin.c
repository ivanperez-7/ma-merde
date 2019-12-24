#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define LEN 32                 // lenght of ter + non-ter strings
#define MAX 32                 // maximum size of stack

struct Stack{
    int sp, top;
    char stack[MAX][LEN];
} parser = {0,MAX,{""}};

char NONTER[][LEN] = {"<PROG>","<SENTS>","<SENT>","<AUX0>","<AUX1>","<AUX2>","<AUX3>","<ELEM>","<COMPARA>"};
char TER[][LEN] = {"PROGRAMA","FINPROG","[id]","=","[op_ar]","SI","ENTONCES","SINO","FINSI","REPITE","VECES","FINREP","IMPRIME","[txt]","LEE","#","[comentario]","[val]","[op_rel]","$"};        // include EOF "$"
char rules[][100] = { "",                              // right side of rule separated by blank spaces!!
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

int LL1[][(int)(sizeof(TER)/LEN)] = {                                       // 0 = no transition in LL1 table - syntax error
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

const int T = (int)(sizeof(TER)/LEN);           // number of terminals
const int NT = (int)(sizeof(NONTER)/LEN);       // number of non-terminals
int err = FALSE;

int equal(char *a, char *b){
    return (!strcmp(a,b));
}

int idx(char arr[][LEN], char *src){
    int idx, lim = equal(arr[0],NONTER[0]) ? NT : T;

    for(idx = 0; !equal(arr[idx],src) && idx < lim; idx++) 
        ;
    if(idx == lim){
        printf("\nERROR: %s not found in array %s\n\n",src,(lim == NT ? "NONTER" : "TER"));
        exit(-1);
    }
    return idx;
}

int isterminal(char *src){
    int i = 0;

    for(; i < T; i++)
        if(equal(TER[i],src))
            return TRUE;

    return FALSE;
}

void push(struct Stack *p, char *in){
    if(p->sp < p->top){
        strcpy(p->stack[p->sp], in);
        p->sp++;
    }
    else{
        printf("\nFull stack\n");
        err = TRUE;
    }
}

char *pop(struct Stack *p){
    static char out[LEN];

    p->sp--;
    strcpy(out,p->stack[p->sp]);
    strcpy(p->stack[p->sp],"");

    return out;
}
    
char *revstr(char *src){
    int i, len = (int)strlen(src);
    static char out[100];
    
    for(i = 0; i < len; i++)
        out[i] = src[len - 1 - i];
    out[i] = 0;

    return out;
}

void pushrule(char *rule){
    char *token = strtok(revstr(rule),"   "), aux[LEN];
    
    while(token && !equal(token,">-")){
        push(&parser,revstr(strcpy(aux,token)));
        token = strtok(NULL,"  ");
    }
}

void print(struct Stack p){
    int i;

    printf("[");
    for(i = 0; i < p.sp-1; i++)
        printf("%s, ",p.stack[i]);
    printf("%s]\n",p.stack[i]);
}

char *getnom(char *src, char *exten){
    static char out[30];
    int i;
    
    for(i = 0; src[i] != '.'; i++)
        out[i] = src[i];
    out[i] = 0;

    return strcat(out,exten);
}

int main(int argc, char **argv){
    int index, flag = argc == 2 ? 0 : atoi(argv[2]);
    char input[LEN], *top;
    FILE *fsrc = fopen(argv[1],"r");
    
    if(!fsrc){
        printf("\nNo file %s was found.\n\n",argv[1]);
        exit(-1);
    }
    
    fscanf(fsrc,"%s",input);
    push(&parser,"$");
    push(&parser,NONTER[0]);
    if(flag) print(parser);

    do {
        top = pop(&parser);
            
        if(isterminal(top) && equal(top,input))
            fscanf(fsrc,"%s",input);
        else if(!isterminal(top) && (index = LL1[idx(NONTER,top)][idx(TER,input)]))
            pushrule(rules[index]);
        else
            err = TRUE;
        
        if(flag) print(parser);
    } while( !err && parser.sp != 0 );
        
    if(!err)
        printf("\nSuccesful parsing.\n\n");
    else
        printf("\nSyntax error. Parsing failure.\n\n");
    
    return 0;
}
