/************************************************
Nombre: ocurrencias2.c
Objetivo: Buscar subcadenas dentro de un parrafo
Autor: Iván Pérez Maldonado
Fecha: 28/03/19
*************************************************/

#include <stdio.h>
#include <string.h>

#define MX 512

// ****************** Declaración de funciones ******************
void scans(char cad[], int MAX);

int main(){
   int oc = 0;
   char parr[MX], search[MX];
   char *p, *s;

   printf("=============================\nBuscar subcadenas en cadena\n=============================\nIngrese el parrafo:\n");
   scans(parr,MX);

   printf("\nIngrese la cadena a buscar (-1 para salir): ");
   scans(search,MX);

   while(strcmp(search,"-1") != 0){
      oc = 0;
      p = &parr[0];

      do{
         s = strstr(p,search);
         if(s != NULL)
            oc++;
         p = s + 1;
      } while(s != NULL);

      printf("Ocurrencias: %d\n",oc);
      printf("\nIngrese la cadena a buscar: ");
      scans(search,MX);
   }

   return 0;
}

// ****************** Descripción de funciones ******************
void scans(char cadena[], int MAX){
   int c,i;

   for(i = 0;i < MAX - 1 && (c = getchar()) != EOF && c != 10;i++)
      cadena[i] = c;

   cadena[i] = 0;
}
