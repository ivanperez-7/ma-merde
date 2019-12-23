/*********************************************
Nombre: dados.c
Objetivo: Programa que simula un tiro de dados
Autor: Ivan Perez Maldonado
Fecha: 25/03/19
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANG 6
#define TIROS 50000

int main(){
   int i, j, sumas[6][6], suma;
   double porcentaje;

   printf("===========================================\nCombinaciones posibles al tirar los dados\n===========================================\n %-4s","+");

   for(i = 1;i <= RANG;i++) printf("%-4d",i); printf("\n");
   for(i = 1;i <= RANG;i++){
      printf(" %-4d",i);
      for(j = 1;j <= RANG;j++)
         printf("%-4d",i+j);
      printf("\n");
   }

   for(i = 0;i < 6;i++){
      for(j = 0;j < 6;j++)
         sumas[i][j] = 0;
   }

   srand(time(NULL));
   printf("\n\nSe tiraron %d veces dos dados, estos son los resultados.\n",TIROS);
   for(i = 0;i < TIROS;i++)
      sumas[rand()%6][rand()%6]++;

   printf(" %-6s","");
   for(i = 1;i <= RANG;i++) printf("%-7d",i); printf("\n");
   for(i = 1;i <= RANG;i++){
      printf(" %-4d",i);
      for(j = 1;j <= RANG;j++){
         porcentaje = (float)sumas[i-1][j-1] / (float)TIROS;
         printf("%.2lf%-3c",porcentaje*100,37);
      }
      printf("\n");
   }

	return 0;
}
