/**************************************************************
Nombre: multmax.c
Objetivo: Crear una funcion para multiplicar matrices cuadradas
Autor: Iván Pérez Maldonado
Fecha: 24/03/19
**************************************************************/

#include <stdio.h>

// ************************* Declaración de funciones *************************
void multiplica(int n, double MAT1[][n], double MAT2[][n]);
void imprimirmatriz(int n, double MAT[][n]);
void leematriz(int n, double MAT[][n]);

int main(){
	int N;

	printf("Ingrese la dimension de la matriz: ");
	scanf("%d",&N);
	double m1[N][N];
	double m2[N][N];

	printf("\n==========\nMatriz 1\n==========\n");
	leematriz(N,m1);
	printf("\nMatriz ingresada:\n");
	imprimirmatriz(N,m1);

	printf("\n==========\nMatriz 2\n==========\n");
	leematriz(N,m2);
	printf("\nMatriz ingresada:\n");
	imprimirmatriz(N,m2);

	printf("\n============================\nMultiplicacion de matrices\n============================\n");
	multiplica(N,m1,m2);
	printf("\n");
	multiplica(N,m2,m1);

	return 0;
}

// ************************* Descripción de funciones *************************
void multiplica(int n, double MAT1[][n], double MAT2[][n]){
	int i,j,k;
	double MULT[n][n];

	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++)
			MULT[i][j] = 0;
	}

	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			for(k = 0;k < n;k++)
				MULT[i][j] += MAT1[i][k] * MAT2[k][j];
		}
	}
	imprimirmatriz(n,MULT);
}

void imprimirmatriz(int n, double MAT[][n]){
	int i,j;

	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++)
			printf("%-10.2lf",MAT[i][j]);
		printf("\n");
	}
}

void leematriz(int n, double MAT[][n]){
	int i,j;

	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			printf("Ingrese la entrada %d,%d: ",i+1,j+1);
			scanf("%lf",&MAT[i][j]);
		}
	}
}
