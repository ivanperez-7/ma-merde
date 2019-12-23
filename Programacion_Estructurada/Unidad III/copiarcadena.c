/*****************************************************************
Nombre: copiarcadena.c
Objetivo: Simular funciones para el manejo de cadenas y caracteres
Autor: Ivan Perez Maldonado
Fecha: 28/02/19
******************************************************************/

#include <stdio.h>

#define LON 100

// ****************** Declaración de funciones ******************
void copiacadena(char cadena[],char nueva[]);
int scans(char cad[], int MAX);

int main(){
   char cadena[LON];
   char nueva[LON];

   printf("Ingrese el texto:\n");
   scans(cadena,LON);

   copiacadena(cadena,nueva);
   printf("\nNueva cadena: %s",nueva);
	return 0;
}

// ****************** Descripción de funciones ******************
void copiacadena(char cadena[],char nueva[]){
   int i = 0;

   while(cadena[i] != 0){
      nueva[i] = cadena[i];
      i++;
   }
   nueva[i] = 0;
}

int scans(char cadena[], int MAX){
   int c,i;

   for(i = 0;i < MAX - 1 && (c = getchar()) != EOF && c != 10;i++)
      cadena[i] = c;

   cadena[i] = 0;
   return i;
}
