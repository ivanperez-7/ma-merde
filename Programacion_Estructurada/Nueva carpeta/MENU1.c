/*
Nombre: 
Objetivo: 
Autor: 
Fecha: 
*/

#include <stdio.h>

int main(){
	// opción A
	float op1,op2,suma;
	printf("Teclea primer operando: ");
	scanf("%f",&op1);
	printf("Teclea segundo operando: ");
	scanf("%f",&op2);
	suma = op1 + op2;
	printf("La suma es %.3f\n",suma);
	
	// opción B
	float r,area,per;
	printf("Ingrese el radio: ");
	scanf("%f",&r);
	area = 3.1416 * r * r;
	per = 3.1416 * 2 * r;
	printf("El area del circulo es %.3f y su perimetro es %.3f",area,per);
	
	
	return 0;
}
