/*
Nombre: 
Objetivo: 
Autor: 
Fecha: 
*/

#include <stdio.h>
//#define Gravy 6.673e-8

int main(){
	const float Gravy = 6.673e-8;
	float m1,m2,F,r;
	
	printf("Ingrese las masas: ");
	scanf("%f %f",&m1,&m2);
	printf("Ingrese la distancia: ");
	scanf("%f",&r);
	
	if(m1>0 && m2>0 && r>0){
		F = Gravy*((m1*m2)/(r*r));
		printf("\n\nF = %g",F);
	}
	else
	   printf("\n\nJUas juas no hay solucion");
	
	return 0;
}
