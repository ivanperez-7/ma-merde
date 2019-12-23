/*****************************************************
Nombre: minimoscuadrados.c
Objetivo: Calcular un pronostico basado en datos dados
Autor: Ivan Perez Maldonado
Fecha: 15/03/2019
******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 5
#define MOVIL 0

// *************************** FUNCIONES ********************************
int scans(char cad[], int MAXL);
double valabs(double num);
double sumatoria(int cols, double arr[MAX][4], int MAXL);

int main(){
   int i = 0;
   char vind[50];
   double tabla[MAX][4], sumax, sumaxy, sumay, sumaxsq, m, b, vindx; // 0:X, 1:Y, 2:X*Y, 3:X**2

	printf("Aproximacion por metodo de minimos cuadrados.\n\n");
	for(i = 0;i < MAX;i++){
      printf("Ingrese los valores de (x%d,y%d): ",i + 1,i + 1);
      scanf("%lf %lf",&tabla[i][0],&tabla[i][1]);
      tabla[i][0] += MOVIL;
      tabla[i][1] += MOVIL;

      tabla[i][2] = tabla[i][0] * tabla[i][1];
      tabla[i][3] = tabla[i][0] * tabla[i][0];
	}

   sumax = sumatoria(0,tabla,MAX);
   sumay = sumatoria(1,tabla,MAX);
   sumaxy = sumatoria(2,tabla,MAX);
   sumaxsq = sumatoria(3,tabla,MAX);
   m = (MAX*sumaxy - sumax*sumay) / ( MAX*sumaxsq - pow(valabs(sumax),2) );
   b = (sumay*sumaxsq - sumax*sumaxy) / ( MAX*sumaxsq - pow(valabs(sumax),2) );

   printf("\nIntroduce un valor de x: ");
   getchar(); scans(vind,50);
   while( strcmp(vind,"Fin") != 0 && strcmp(vind,"fin") != 0 ){
      vindx = atof(vind);
      printf("valor de y = %lf\n",m*vindx + b);
      printf("\nIntroduce un valor de x: ");
      scans(vind,50);
   }

	return 0;
}

// *************************** FUNCIONES ********************************
double valabs(double num){
	if(num < 0)
		num *= -1;
	return num;
}

double sumatoria(int cols, double arr[MAX][4], int MAXL){
   double suma = 0;
   int i;

   for(i = 0; i < MAXL;i++)
      suma += arr[i][cols];

   return suma;
}

int scans(char cadena[], int MAXL){
   int c,i;

   for(i = 0;i < MAXL - 1 && (c = getchar()) != EOF && c != 10;i++)
      cadena[i] = c;

   cadena[i] = 0;
   return i;
}
