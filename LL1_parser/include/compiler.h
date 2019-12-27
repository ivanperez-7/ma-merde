#ifndef __COMPILER__
#define __COMPILER__

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _StackStr{
    int sp, top;
    char **stack;
} StackStr;

extern char err;

int equal(char *a, char *b);
char *getnom(char *src, char *exten);
char **dynstr(int r, int c);
void freestr(char **ptr, int r);
void initPila(StackStr *p, int r, int c);
void freePila(StackStr *p);
void pushStr(StackStr *p, char *src);
void popStr(StackStr *p, char *target);
void printStr(StackStr p);
int search(char **arr, char *src);

#endif
