/***************************************************************
Nombre: sistemasecuaciones.c
Objetivo: Resolver sistemas de ecuaciones con el método Montante
Autor: Iván Pérez Maldonado
Fecha: 21/03/19
****************************************************************/

#include <stdio.h>

#define N 3

// ************************* Declaración de funciones *************************
void resmat(int n, double MAT[][n+1], double SOL[n]);

int main(){
   int i,j;
   double mat[N][N+1] = {1,1,1,7,1,3,-2,-4,1,9,4,8};
   double solmat[N];

   for(i = 0;i < N;i++){
      for(j = 0;j < N+1;j++)
         printf("%-3.0lf",mat[i][j]);
      printf("\n");
   }

   resmat(N,mat,solmat); printf("\n\n");
   for(i = 0;i < N;i++)
      printf("%.5lf\n",solmat[i]);

	return 0;
}

// ************************* Descripción de funciones *************************
void resmat(int n, double MAT[][n+1], double SOL[n]){
   int ROWS = n, COLS = n+1, i, j, p;
   double piv, pivant = 1,det;

   for(p = 0;p < ROWS;p++){
      piv = MAT[p][p];
      for(i = 0;i < ROWS;i++){
         if(i != p){
            for(j = p+1;j < COLS;j++)
               MAT[i][j] = (MAT[i][j]*piv - MAT[p][j]*MAT[i][p])/(pivant);
         }
      }

      for(i = 0;i < ROWS;i++)
         if(i != p) MAT[i][p] = 0;
      pivant = piv;
   }

   det = MAT[n-1][n-1];
   for(i = 0;i < ROWS;i++)
      SOL[i] = MAT[i][n] / det;
}
