/***********************************************
Nombre: aNumero.c
Objetivo: Función que convierte cadena a número
Autor: Iván Pérez Maldonado
Fecha: 22/04/19
************************************************/

#include <stdio.h>
#include <math.h>

// ************************* Declaración de funciones *************************
int aNum(char cad[]);
int esdigito(char c);

int main(){
    char c[4];

    printf("Ingrese un numero de tres digitos: ");
    gets(c);
    printf("\nEl numero es %d",aNum(c));

    return 0;
}

// ************************* Descripción de funciones *************************
int aNum(char cad[]){
    int num = 0, i, e = 2;

    for(i = 0;i <= 3 && esdigito(cad[i]);i++,e--){
        num += (cad[i] - 48) * pow(10,e);
        if(i == 0)
            num++;
    }

    if(i != 3 || cad[i] != 0)
        num = -1;

    return num;
}

int esdigito(char c){
   int tf = 0;

    if(c >= 48 && c <= 57)
        tf = 1;

    return tf;
}
