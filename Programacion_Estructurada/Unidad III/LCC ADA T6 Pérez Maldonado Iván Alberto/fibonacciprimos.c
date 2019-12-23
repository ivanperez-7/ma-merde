/*************************************************************
Nombre: fibonacciprimos.c
Objetivo: Mostrar numeros primos de la secuencia de Fibonacci
Autor: Iván Pérez Maldonado
Fecha: 16/04/19
**************************************************************/

#include <stdio.h>

// ****************** Declaración de funciones ******************
int esprimo(unsigned long int num);

int main(){
   int cont = 0, num;
   unsigned long int f0 = 0, f1 = 1, fn;

   printf("=======================\nSecuencia de Fibonacci\n=======================");
   printf("\nCuantos numeros quieres mostrar? ");
   scanf("%d",&num);

   if(num > 0){
      printf("\nNumeros:\n");

      while(cont < num){
         fn = f0 + f1;

         if(esprimo(fn)){
            printf("%lu\n",fn);
            cont++;
         }
         f0 = f1;
         f1 = fn;
      }
   }
   return 0;
}

// ****************** Descripción de funciones ******************
int esprimo(unsigned long int num){
   unsigned long int div = 2;
   int primo = 1;

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
