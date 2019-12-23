/*
Nombre:
Objetivo:
Autor:
Fecha:
*/

#include <stdio.h>

// ************************* Declaración de funciones *************************
int searcharr(int a[], int val, int MAX);

int main(){
   int numeros[20], i, num;

   for(i = 0; i < 20;i++)
      numeros[i] = -1;

   for(i = 0;i < 20;i++){
      do{
         printf("Ingrese un numero: ");
         scanf("%d",&num);
      } while(num < 10 || num > 100);

      if( searcharr(numeros,num,20) == 0 )
         printf("Usted ingreso el numero %d\n\n",num);
      else
         printf("El numero esta repetido\n\n");

      numeros[i] = num;
   }

	return 0;
}

// ************************* Descripción de funciones *************************
int searcharr(int a[], int val, int MAX){
   int i, tf = 1;

   for(i = 0;i < MAX && a[i] != val;i++)
      ;

   if(i == MAX)
      tf = 0;

   return tf;
}
