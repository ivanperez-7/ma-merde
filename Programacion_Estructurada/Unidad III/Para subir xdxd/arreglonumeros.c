/***************************************************
Nombre: arreglonumeros.c
Objetivo: Leer arreglo de numeros y realizar cambios
Autor: Iván Pérez Maldonado
Fecha: 23/03/19
****************************************************/

#include <stdio.h>

// ************************* Declaración de funciones *************************
void printarr(int arr[], int MAXL);

int main(){
   char opcion;
   int nums[15], nuevonum = -1, posicion, i;

   for(i = 0;i < 15;i++){
      printf("Ingrese el numero %d: ",i+1);
      scanf("%d",&nums[i]);
   }

   printf("\n\n");
   do {
      getchar();
      printf("Desea realizar algun cambio? (Y/N) ");
      opcion = getchar();
   } while(opcion != 'Y' && opcion != 'y' && opcion != 'N' && opcion != 'n');

   if(opcion == 'Y' || opcion == 'y'){
      while(nuevonum != 0){
         printf("\nIngresa el numero nuevo (0 para salir): ");
         scanf("%d",&nuevonum);

         do {
            printf("Ingresa la posicion del numero: ");
            scanf("%d",&posicion);
         } while(posicion < 1 || posicion > 15);

         printf("\nAntes:\n");
         printarr(nums,15);

         nums[posicion - 1] = nuevonum;
         printf("\n\nDespues:\n");
         printarr(nums,15);
         printf("\n\n");

         printf("\nIngresa el numero nuevo: ");
         scanf("%d",&nuevonum);
      }
   }

	return 0;
}

// ************************* Descripción de funciones *************************
void printarr(int arr[], int MAXL){
	int i;

	printf("[");
	for(i = 0;i < MAXL - 1; i++)
		printf("%d, ",arr[i]);
	printf("%d]",arr[i]);
}
