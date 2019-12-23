/********************************************
Nombre: vocal.c
Objetivo: Funcion logica que recibe caracter
Autor: Iván Pérez Maldonado
Fecha: 16/04/19
*********************************************/

#include <stdio.h>

// *************** Declaración de funciones ***************
int esvocal(char c);

int main(){
   char c;

   printf("===============\nFuncion vocal\n===============");
   printf("\nIngrese un caracter: ");
   c = getchar();

   if(esvocal(c))
      printf("\nEl caracter es una vocal\n");
   else
      printf("\nEl caracter no es una vocal\n");

   return 0;
}

// *************** Descripción de funciones ***************
int esvocal(char c){
   int tf = 0;

   if(c == 65 || c == 69 || c == 73 || c == 79 ||  c == 85 || c == 97 || c == 101 || c == 105 || c == 111 || c == 117)
      tf = 1;

   return tf;
}
