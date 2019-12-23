/********************************************************
Nombre: vectores.c
Objetivo: Programa con funciones para operar con vectores
Autor: Ivan Perez Maldonado
Fecha: 22/03/19
*********************************************************/

#include <stdio.h>

#define MAX 5

// ************************* Declaración de funciones *************************
void scanarr(float arr[], int MAXL);
void printarr(float arr[], int MAXL);
void arrsum(float arr[], float arr2[], float arr3[], int MAXL);
void arrdif(float arr[], float arr2[], float arr3[], int MAXL);
void arrceros(float arr[], int MAXL);
void arrunos(float arr[], int MAXL);

int main(){
	float v1[MAX];
	float v2[MAX];
	float v3[MAX];

   printf("====================\nFuncion leer vector\n====================\nVector 1.\n");
   scanarr(v1,MAX);
   printf("\nVector 2.\n");
   scanarr(v2,MAX);

   printf("\n======================\nFuncion suma vectores\n======================\nv3 = ");
   arrsum(v1,v2,v3,MAX);
   printarr(v3,MAX);

   printf("\n\n=======================\nFuncion resta vectores\n=======================\nv3 = ");
   arrdif(v1,v2,v3,MAX);
   printarr(v3,MAX);

   printf("\n\n====================\nInicializar en cero\n====================\nv3 = ");
   arrceros(v3,MAX);
   printarr(v3,MAX);

   printf("\n\n====================\nInicializar en unos\n====================\nv3 = ");
   arrunos(v3,MAX);
   printarr(v3,MAX);

	return 0;
}

// ************************* Descripción de funciones *************************
void scanarr(float arr[], int MAXL){
	int i;

	for(i = 0;i < MAXL; i++){
		printf("Ingrese el dato %d: ",i+1);
		scanf("%f",&arr[i]);
	}
}

void printarr(float arr[], int MAXL){
	int i;

	printf("[");
	for(i = 0;i < MAXL - 1; i++)
		printf("%.2f, ",arr[i]);
	printf("%.2f]",arr[i]);
}

void arrsum(float arr[], float arr2[], float arr3[], int MAXL){
	int i;

	for(i = 0;i < MAXL; i++)
		arr3[i] = arr[i] + arr2[i];
}

void arrdif(float arr[], float arr2[], float arr3[], int MAXL){
	int i;

	for(i = 0;i < MAXL; i++)
		arr3[i] = arr[i] - arr2[i];
}

void arrceros(float arr[], int MAXL){
	int i;

	for(i = 0;i < MAXL;i++)
		arr[i] = 0;
}

void arrunos(float arr[], int MAXL){
	int i;

	for(i = 0;i < MAXL;i++)
		arr[i] = 1;
}
