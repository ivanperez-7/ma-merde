/**************************************************************
Nombre: permutaciones.c
Objetivo: Calcular n�mero de permutaciones a trav�s de funci�n
Autor: Iv�n P�rez Maldonado
Fecha: 16/04/2019
***************************************************************/

#include <stdio.h>

// *************** Declaraci�n de funciones ***************
double factorial(int num);
double nPr(int n, int r);

int main(){
   int n, r;

   printf("=================================\nCalcular numero de permutaciones\n=================================");
   printf("\nNumero de elementos: ");
   scanf("%d",&n);

   printf("Numero de elementos tomados a la vez: ");
   scanf("%d",&r);

   printf("\nnPr = %.0lf",nPr(n,r));
   return 0;
}

// *************** Descripci�n de funciones ***************
double factorial(int num){
   double resultado = 1, i = 0;

   if(num < 0)
      resultado = -1;
   if(num >= 2){
      while(i < num){
         resultado *= num - i;
         i++;
      }
   }

   return resultado;
}

double nPr(int n, int r){
   double resultado;

   if(r == 0)
      resultado = 1;
   else if(n == 0 || r > n)
      resultado = 0;
   else
      resultado = ( factorial(n) )/( (factorial(n-r)) );

   return resultado;
}
