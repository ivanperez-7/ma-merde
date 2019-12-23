/****************************************
Nombre: sumacuadrados.c
Objetivo: Calcular media de numeros dados
Autor: Iván Pérez Maldonado
Fecha: 23/03/19
*****************************************/

#include <stdio.h>

int main(){
   int nums[10], suma = 0, i;

   for(i = 0;i < 10;i++){
      printf("Ingresa el numero %d: ",i+1);
      scanf("%d",&nums[i]);
      suma += (nums[i])*(nums[i]);
   }

   printf("\nEl promedio de los cuadrados de los numeros es %.2lf\n",(float)suma/(float)10);
	return 0;
}
