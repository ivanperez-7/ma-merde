/*
Nombre: media.c
Objetivo: Leer numeros y calcular media
Autor: Ivan Perez Maldonado
Fecha: 14/03/2019
*/

#include <stdio.h>

#define NUM 4

int main(){
	int nums[NUM], i = 0, dato, suma = 0, prom, enc = 0,deb = 0, cont = 0;

	printf("Calcular media.\n\n");
	do {
      printf("Ingresa el numero %d: ",i+1);
      scanf("%d",&dato);
      if(dato != -1){
         nums[i] = dato;
         suma += dato;
         i++;
         cont++;
      }
	} while(i < NUM && dato != -1);

   if(i == 0) i++;
   prom = suma/i;
	for(i = 0; i < cont; i++){
      if(nums[i] > prom)
         enc++;
      else if(nums[i] < prom)
         deb++;
   }

   printf("\nPromedio de los numeros: %d\nNumeros por encima: %d\nNumeros por debajo: %d",prom,enc,deb);
	return 0;
}
