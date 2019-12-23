/***************************
Nombre: concstr.c
Objetivo: Combinar cadenas
Autor: Iván Pérez Maldonado
Fecha: 26/03/19
****************************/

#include <stdio.h>
#include <string.h>

// ****************** Declaración de funciones ******************
void scans(char cad[], int MAX);
int leecadena(char cadena[]);

int main(){
   int i;
   char cad1[100], cad2[100], cad3[210];

   printf("Ingrese la primera cadena: ");
   scans(cad1,100);

   printf("Ingrese la segunda cadena: ");
   scans(cad2,100);

   printf("\n");
   for(i = 0;i < 100 && cad1[i] != 0;i++)
      cad3[i] = cad1[i];
   cad3[i] = 32;

   for(i = 0;i < 100 && cad2[i] != 0;i++)
      cad3[i+leecadena(cad1)+1] = cad2[i];
   cad3[i+leecadena(cad1)+1] = 0;

   puts(cad3);
	return 0;
}

// ****************** Descripción de funciones ******************
void scans(char cadena[], int MAX){
   int c,i;

   for(i = 0;i < MAX - 1 && (c = getchar()) != EOF && c != 10;i++)
      cadena[i] = c;

   cadena[i] = 0;
}

int leecadena(char cadena[]){
   int i = 0, caracteres = 0;

   for(i = 0;cadena[i] != 0 && cadena[i] != EOF;i++)
      caracteres++;

   return caracteres;
}
