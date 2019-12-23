/*****************************************************************
Nombre: longitudcadena.c
Objetivo: Simular funciones para el manejo de cadenas y caracteres
Autor: Ivan Perez Maldonado
Fecha: 28/02/19
******************************************************************/

#include <stdio.h>

// ****************** Declaración de funciones ******************
int leecadena(char cadena[200]);
void copiacadena(char cadena[200],char nueva[200]);

int main(){
   /*
   char cadena[200];
   int longitud = 0;

   printf("Ingrese el texto:\n");
   gets(cadena);
   longitud = leecadena(cadena);

   printf("\nLongitud de la cadena: %d",longitud);
   */

   char cadena[200];
   char nueva[200];

   printf("Ingrese el texto:\n");
   gets(cadena);

   copiacadena(cadena,nueva);
   printf("\nNueva cadena: %s",nueva);

	return 0;
}

// ****************** Descripción de funciones ******************
int leecadena(char cadena[200]){
   int i = 0, caracteres = 0;

   do {
      if(cadena[i] != 0)
         caracteres++;
      i++;
   } while(cadena[i] != 0);

   return (caracteres);
}

void copiacadena(char cadena[200],char nueva[200]){
   int i = 0;

   do {
      nueva[i] = cadena[i];
      i++;
   } while(cadena[i] != 0);
}
