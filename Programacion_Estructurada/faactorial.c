/*
Nombre: factorial.c
Objetivo: Calcular el factorial de un entero mayor o igual que cero
Autor: Iván Pérez Maldonado
Fecha: 12/02/2019
*/

#include <stdio.h>

int main(){
	unsigned long int num,fact = 1,i = 0;
	
	printf("Ingresa un numero mayor o entero que 0: ");
	scanf("%lu",&num);
	
	if(num == 0 || num == 1)
		fact = 1;
	else if(num >= 2)
		while(i < num){
			fact *= num - i;
			i++;
		}
		
	printf("\nEl factorial es %lu",fact);
   return 0;
}
