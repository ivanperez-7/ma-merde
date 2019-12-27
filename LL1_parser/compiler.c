#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <compiler.h>

char err = FALSE;

int equal(char *a, char *b){
    return (!strcmp(a,b));
}

char *getnom(char *src, char *exten){
    static char out[50];
    int i;
    
    for(i = 0; src[i] != '.'; i++)
        out[i] = src[i];
    out[i] = 0;

    return strcat(out,exten);
}
    
char **dynstr(int r, int c){
    char **ptr = (char **)malloc(r * sizeof(char *));
    
    for(int i = 0; i < r; i++)
        ptr[i] = (char *)malloc(c * sizeof(char));
    
    return ptr;
}

void freestr(char **ptr, int r){
    for(int i = 0; i < r; i++)
        free(ptr[i]);
    free(ptr);
}

void initPila(StackStr *p, int r, int c){
    p->sp = 0;
    p->top = r;
    p->stack = dynstr(r,c);
}
    
void freePila(StackStr *p){
    freestr(p->stack,p->top);
    p->sp = p->top = 0;
}
    
void pushStr(StackStr *p, char *src){
    if(p->sp < p->top){
        strcpy(p->sp[p->stack],src);
        p->sp++;
    }
    else
        printf("ERROR: Full stack\n");
}

void popStr(StackStr *p, char *target){
    if(p->sp > 0){
        p->sp--;
        strcpy(target,p->stack[p->sp]);
        strcpy(p->stack[p->sp],"");
    }
    else
        printf("ERROR: Empty stack\n");
}
    
void printStr(StackStr p){
    int i;

    printf("[");
    for(i = 0; i < p.sp-1; i++)
        printf("%s, ",p.stack[i]);
    printf("%s]\n",p.stack[i]);
}
    
int search(char **arr, char *src){
    for(int i = 0; arr[i] && !equal(arr[i],""); i++){
        if(equal(src, arr[i]))
            return TRUE;
    }
    return FALSE;
}
