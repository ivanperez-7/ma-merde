/*
Nombre: formulageneral.c
Objetivo: Hallar las soluciones de una ecuaci�n ax^2 + bx + c = 0 dados los coeficientes
Autor: Iv�n P�rez Maldonado
Fecha: 29/01/2019
*/

#include <stdio.h>
#include <math.h>

int main(){
  double a,b,c,x1,x2;

	printf("Expresion de la forma ax^2 + bx + c = 0\na = ");
	scanf("%lf",&a);
	printf("b = ");
	scanf("%lf",&b);
	printf("c = ");
	scanf("%lf",&c);

	x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
	x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);

	printf("\n\nx1 = %.2lf\nx2 = %.2lf",x1,x2);

  return 0;
}
