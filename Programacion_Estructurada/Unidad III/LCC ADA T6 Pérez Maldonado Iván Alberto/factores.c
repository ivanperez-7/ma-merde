/*******************************************
Nombre: factores.c
Objetivo: Mostrar factores de enteros dados
Autor: Iván Pérez Maldonado
Fecha: 16704/19
********************************************/

#include <stdio.h>

// *************** Declaración de funciones ***************
void factores(int num);

int main(){
   int num;

   printf("=================\nMostrar factores\n=================\n");
   printf("Ingresa un numero: ");
   scanf("%d",&num);

   printf("\n"); factores(num);
   return 0;
}

// *************** Descripción de funciones ***************
void factores(int num){
   int div = 2, unidad = 1;

   if(num == 0)
      printf("0 = 1 x 0");
   else if(num == 1)
      printf("1 = 1 x 1");
   else if(num == -1)
      printf("-1 = 1 x -1");
   else{
      if(num < 0)
         unidad = -1;

      while(num % div != 0) div++;
      printf("%d = %d x %d",num,unidad,div);
      num /= div;

      div = 2;
      if(num < 0)
         num *= -1;
      while(div <= num){
         if(num % div == 0){
            printf(" x %d",div);
            num /= div;
            div = 2;
         }
         else
            div++;
      }
   }
}
