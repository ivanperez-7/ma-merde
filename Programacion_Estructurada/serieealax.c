/*
Nombre: serieealax.c
Objetivo: Calcular una aproximación del número e^x dados dos numeros x y n
Autor: Iván Pérez Maldonado
Fecha: 12/02/2019
*/

#include <stdio.h>
#include <math.h>

double fact(double i);

int main(){
   double x,n,suma = 0,i;

   printf("Aproximacion de e^x\nIntroduzca dos numeros x y n: ");
   scanf("%lf %lf",&x,&n);

   for(i = 0;i <= n;i++){
      suma += ( pow(x,i) ) / ( fact(i) );
   }
   printf("\nResultado = %lf",suma);

   return 0;
}

double fact(double i){
   double res = 1,c = 0;

	if(i == 0 || i == 1)
		res = 1;
	else if(i >= 2)
		while(c < i){
			res *= i - c;
			c++;
		}

   return res;
}
