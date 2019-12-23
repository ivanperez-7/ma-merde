/*****************************************************************
Nombre: montante.c
Objetivo: Calcular la inversa de una matriz con el método Montante
Autor: Iván Pérez Maldonado
Fecha: 19/03/19
*****************************************************************/

#include <stdio.h>

// ************************* Declaración de funciones *************************
double invmat(int n, double MAT[][n]);

int main(){
	int N;

	printf("================\nInvertir matriz\n================\n");
	printf("Ingresa la dimension de la matriz: ");
	scanf("%d",&N);
	
	double mat[N][N]; // matriz original
	double deter;

	printf("\n");
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++){
			printf("Ingrese la entrada [%d,%d]: ",i+1,j+1);
			scanf("%lf",&mat[i][j]);
		}
	}

	printf("\nMatriz original:\n");
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++)
			printf("%-5.0lf",mat[i][j]);
		printf("\n");
	}
	deter = invmat(N,mat);
	
	printf("\nMatriz inversa:\n");
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++)
			printf("%-7.3lf",mat[i][j]);
		printf("\n");
	}

	printf("\nDeterminante = %.2lf\n",deter);
	return 0;
}

// ************************* Descripción de funciones *************************
double invmat(int n, double MAT[n][n]){
	const int ROWS = n, COLS = 2*n;
	double pivant = 1, piv, det;
	double INVMAT[ROWS+1][COLS+1];

	for(int i = 1;i <= ROWS;i++){
		for(int j = 1;j <= ROWS;j++)
			INVMAT[i][j] = MAT[i-1][j-1];
	}

	for(int i = 1;i <= ROWS;i++){
		for(int j = ROWS+1;j <= COLS;j++){
			if(i + ROWS == j)
				INVMAT[i][j] = 1;
			else
				INVMAT[i][j] = 0;
		}
	}

	for(int p = 1;p <= ROWS;p++){
		piv = INVMAT[p][p];
		for(int i = 1;i <= ROWS;i++){
			if(i != p){
				for(int j = p+1;j <= COLS;j++)
					INVMAT[i][j] = (INVMAT[i][j]*piv - INVMAT[p][j]*INVMAT[i][p])/(pivant);
			}
		}
		
		pivant = piv;
	}

	det = INVMAT[n][n];
	for(int i = 1;i <= ROWS;i++){
		for(int j = ROWS+1;j <= COLS;j++)
			MAT[i-1][j-ROWS-1] = INVMAT[i][j] / det;
	}

	return det;
}
