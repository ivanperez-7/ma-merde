/********************************************
Nombre: digito.c
Objetivo: Funcion logica que recibe caracter
Autor: Iván Pérez Maldonado
Fecha: 16/04/19
*********************************************/

#include <stdio.h>

// *************** Declaración de funciones ***************
int esdigito(char c);

int main(){
   char c;

   printf("===============\nFuncion digito\n===============");
   printf("\nIngrese un caracter: ");
   c = getchar();

   if(esdigito(c))
      printf("\nEl caracter es un digito\n");
   else
      printf("\nEl caracter no es un digito\n");

   return 0;
}

// *************** Descripción de funciones ***************
int esdigito(char c){
   int tf = 0;

   if(c >= 48 && c <= 57)
      tf = 1;

   return tf;
}
