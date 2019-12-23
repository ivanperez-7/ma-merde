/*************************************
Nombre: strtok.c
Objetivo: Uso de la función strtok()
Autor: Iván Pérez Maldonado
Fecha: 28/03/19
**************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
   char tel[20] = "(999)225-2909", del[5] = "()-";
   char *num1, *num2;
   int lada;
   long int numero;

   lada = atoi(strtok(tel,del));
   num1 = strtok(NULL,del);
   num2 = strtok(NULL,del);
   numero = atol(strcat(num1,num2));

   printf("Lada: %d\nNumero: %ld",lada,numero);
	return 0;
}
