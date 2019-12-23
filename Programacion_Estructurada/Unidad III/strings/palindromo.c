/***********************************************
Nombre: palindromo.c
Objetivo: Verificar si una cadena es palindromo
Autor: Iván Pérez Maldonado
Fecha: 28/03/19
************************************************/

#include <stdio.h>
#include <string.h>

// ******************** Declaración de funciones ********************
void scans(char cad[], int MAX);
void copiarstr(char cad[], char cad2[], int MAX);

int main(){
   int i, j, len, tf = 1;
   char palabra[50], palabra2[50];

   printf("Ingresa una oracion o palabra: ");
   scans(palabra,50);

   strlwr(palabra);
   copiarstr(palabra,palabra2,50);
   len = strlen(palabra2);

   for(i = 0, j = len - 1;i < len/2 && tf == 1;i++, j--){
      if(palabra2[i] != palabra2[j])
         tf = 0;
   }

   if(tf == 1)
      printf("La cadena es palindroma\n");
   else
      printf("La cadena NO es palindroma\n");

	return 0;
}

// ******************** Descripción de funciones ********************
void scans(char cad[], int MAX){
   int c,i;

   for(i = 0;i < MAX - 1 && (c = getchar()) != EOF && c != 10;i++)
      cad[i] = c;

   cad[i] = 0;
}

void copiarstr(char cad[], char cad2[], int MAX){
   int i, i2;

   for(i = 0, i2 = 0;i < MAX - 1 && (cad[i]) != EOF && cad[i] != 10;i++){
      if(cad[i] != 32){
         cad2[i2] = cad[i];
         i2++;
      }
   }

   cad2[i2] = 0;
}
