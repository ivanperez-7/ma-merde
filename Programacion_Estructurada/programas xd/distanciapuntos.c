/*
Nombre: distanciapuntos.c
Objetivo: Calcular la distancia entre dos puntos en el plano cartesiano
Autor: Iván Pérez Maldonado
Fecha: 29/01/2019
*/

#include <stdio.h>
#include <math.h>

int main(){
  double x1,y1,x2,y2,dist;

	printf("Coordenadas de P1\nx1 = ");
	scanf("%lf",&x1);
	printf("y1 = ");
	scanf("%lf",&y1);
	printf("Coordenadas de P2\nx2 = ");
	scanf("%lf",&x2);
	printf("y2 = ");
	scanf("%lf",&y2);

	dist = sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	printf("\nLa distancia es de %.3lf",dist);

  return 0;
}
