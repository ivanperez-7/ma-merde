/*****************************************************************
Nombre: esprimo.c
Objetivo: Verificar si un numero es primo o no a través de función
Autor: Iván Pérez Maldonado
Fecha: 16/04/19
******************************************************************/

#include <stdio.h>

// *************** Declaración de funciones ***************
int esprimo(int num);

int main(){
   int num;

   printf("=======================\nTest de numeros primos\n=======================");
   printf("\nIngresa un numero: ");
   scanf("%d",&num);

   if(esprimo(num))
      printf("\nEl numero es primo\n");
   else
      printf("\nEl numero no es primo\n");

   return 0;
}

// *************** Descripción de funciones ***************
int esprimo(int num){
   int primo = 1, div = 2;

   if(num <= 1)
      primo = 0;
   else{
      while(div < num && primo == 1){
         if(num % div == 0)
            primo = 0;
         div++;
      }
   }

   return primo;
}
