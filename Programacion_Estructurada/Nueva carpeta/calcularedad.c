/*
Programa: calcularedad.c
Objetivo: Calcula la edad en años de una persona
Autor: Iván Pérez
Fecha: 18 de enero de 2019
*/
#include <stdio.h>

int main() {
	int anacimiento, mnacimiento;
	int aactual, mactual;
	int edad;
	
	printf("Ingrese su anioo de nacimiento: ");
	scanf("%d", &anacimiento);
	printf("Ingrese su mes de nacimiento: ");
	scanf("%d", &mnacimiento);
	
	printf("Ingrese el anio actual: ");
	scanf("%d", &aactual);
	printf("Ingrese el mes actual: ");
	scanf("%d", &mactual);
	
	edad = aactual - anacimiento;
	if (mactual < mnacimiento) edad--;
	printf("Usted tiene %d anios de edad\n", edad);
	
	return 0;
}
