#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/********************* Declaración de funciones ********************/
void imprime(int cols, int mat[][cols]);
int suma(int cols, int mat[][cols]);

int main(){
	int MAT[15][15], negativos = 0, positivos = 0;
	
	srand(time(NULL));
	for(int i = 0;i < 15;i++){
		for(int j = 0;j < 15;j++)
			MAT[i][j] = rand()%10 * 20 - 100 + rand()%10;
	}
	
	imprime(15,MAT);
	printf("\nSuma de la diagonal invertida = %d",suma(15,MAT));
	
	for(int i = 0;i < 15;i++){
		for(int j = 0;j < 15;j++){
			if(MAT[i][j] < 0)
				negativos++;
			else
				positivos++;
		}
	}
	printf("\nHay %d numeros positivos en la matriz y %d numeros negativos.",positivos,negativos);
	
	return 0;
}

/********************* Descripción de funciones ********************/
void imprime(int cols, int mat[][cols]){
	for(int i = 0;i < cols;i++){
		for(int j = 0;j < cols;j++)
			printf("%-5d",mat[i][j]);
		printf("\n");
	}
}

int suma(int cols, int mat[][cols]){
	int res = 0;
	
	for(int i = cols - 1, j = 0;i >= 0;i--,j++)
		res += mat[i][j];
	
	return res;
}
