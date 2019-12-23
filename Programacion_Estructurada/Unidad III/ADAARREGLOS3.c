/*
Nombre:
Objetivo:
Autor:
Fecha:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANG 6
#define TIROS 50000

// ************************* Declaración de funciones *************************

int main(){
   int i, j, resul[11], suma;
   double porcentaje;

   printf("===========================================\nCombinaciones posibles al tirar los dados\n===========================================\n %-4s","+");

   for(i = 1;i <= RANG;i++) printf("%-4d",i); printf("\n");
   for(i = 1;i <= RANG;i++){
      printf(" %-4d",i);
      for(j = 1;j <= RANG;j++)
         printf("%-4d",i+j);
      printf("\n");
   }

   srand(time(NULL));
   printf("\n\nSe tiraron %d veces dos dados, estos son los resultados.\n",TIROS);
   for(i = 0;i < 11;i++) resul[i] = 0;
   for(i = 0;i < TIROS;i++){
      suma = (rand()%6 + 1) + (rand()%6 + 1);
      resul[suma - 2]++;
   }

   for(i = 0;i < 11;i++){
      porcentaje = (float)resul[i] / (float)TIROS;
      printf("%-2d - %.2lf%c\n",i+2,porcentaje*100,37);
   }
	return 0;
}

// ************************* Descripción de funciones *************************
