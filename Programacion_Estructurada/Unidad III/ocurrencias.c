/************************************************
Nombre: ocurrencias.c
Objetivo: Buscar subcadenas dentro de un parrafo
Autor: Iván Pérez Maldonado
Fecha: 28/03/19
*************************************************/

#include <stdio.h>
#include <string.h>

// ****************** Declaración de funciones ******************
void scans(char cad[], int MAX);
int strsearch(char cad[], char parr[]);

int main(){
   char parr[1000];
   char search[50];

   printf("Ingrese el parrafo:\n");
   scans(parr,1000); printf("\n");

   do{
      printf("Ingrese una frase a buscar: ");
      scans(search,50);
      printf("Ocurrencias de la frase: %d\n\n",strsearch(search,parr));
   } while(strcmp(search,"-1") != 0);

   return 0;
}

// ****************** Descripción de funciones ******************
void scans(char cadena[], int MAX){
   int c,i;

   for(i = 0;i < MAX - 1 && (c = getchar()) != EOF && c != 10;i++)
      cadena[i] = c;

   cadena[i] = 0;
}

int strsearch(char cad[], char parr[]){
   int oc = 0, ic, ip;

   for(ip = 0, ic = 0;ip < strlen(parr);ip++){
      if(parr[ip] == cad[ic]){
         if(ic == strlen(cad) - 1){
            oc++;
            ic = 0;
         }
         else
            ic++;
      }
      else
         ic = 0;
   }

   return oc;
}
