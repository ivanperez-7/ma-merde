/***********************************************
Nombre: estadistica.c
Objetivo: Estadística de longitudes de palabras
Autor: Iván Pérez Maldonado
Fecha: 21/04/19
************************************************/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

// ************************* Declaración de funciones *************************
int esalfanum(char c);

int main(){
    int longitudes[11] = {0,0,0,0,0,0,0,0,0,0,0};
    int cont = 0;
    char c;

    printf("Ingresa tu texto:\n");
    c = getchar();

    while(c != EOF){
        if(esalfanum(c))
            cont++;
        else{
            longitudes[cont]++;
            cont = 0;
        }

        c = getchar();
    }

    printf("\n");
    for(cont = 1;cont <= 10;cont++)
        printf("Total de palabras de longitud %d : %d\n",cont,longitudes[cont]);

    return 0;
}

// ************************* Descripción de funciones *************************
int esalfanum(char c){
    int tf = FALSE;

    if((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        tf = TRUE;

    return tf;
}
