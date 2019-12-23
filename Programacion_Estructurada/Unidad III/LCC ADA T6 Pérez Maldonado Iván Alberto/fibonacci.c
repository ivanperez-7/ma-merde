/******************************************************
Nombre: fibonacci.c
Objetivo: Mostrar numeros de la secuencia de Fibonacci
Autor: Iván Pérez Maldonado
Fecha: 16/04/19
*******************************************************/

#include <stdio.h>

int main(){
   int i, num;
   double f0 = 0, f1 = 1, fn;

   printf("=======================\nSecuencia de Fibonacci\n=======================");
   printf("\nCuantos numeros quieres mostrar? ");
   scanf("%d",&num);

   if(num == 1)
      printf("\nNumeros:\n0");
   else if(num >= 2){
      printf("\nNumeros:\n0\n1");

      for(i = 0;i < num - 2;i++){
         fn = f1 + f0;
         printf("\n%.0lf",fn);
         f0 = f1;
         f1 = fn;
      }
   }

   return 0;
}
