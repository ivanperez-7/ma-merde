/*****************************************
Nombre: potencia.c
Objetivo: Simular la funcion pow de math.h
Autor: Ivan Perez Maldonado
Fecha: 28/02/19
******************************************/

#include <stdio.h>

double potencia(double base, double exponente);

int main(){
	double base, exponente, resultado;

	printf("Ingresa la base: ");
	scanf("%lf",&base);
	printf("Ingresa la exponente: ");
	scanf("%lf",&exponente);

	resultado = potencia(base,exponente);
	printf("\nEl resultado es %.2lf",resultado);
	return 0;
}

// ****************** Descripción de funciones ******************
double potencia(double base, double exponente){
	double resultado = 1, i;

   if(exponente == 0)
      resultado = 1;
	else if(exponente >= 1){
      for(i = 1;i <= exponente;i++)
         resultado *= base;
	}

	return resultado;
}
