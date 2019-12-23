/*****************************************************************
Nombre: invmatrix.c
Objetivo: Calcular la inversa de una matriz con el método Montante
Autor: Iván Pérez Maldonado
Fecha: 19/03/19
*****************************************************************/

#include <stdio.h>

// ************************* Declaración de funciones *************************
double invmat(int n, double MAT[][n]);

int main(){
   int i,j,N;

   printf("Ingresa la dimension de la matriz: ");
   scanf("%d",&N);
   double mat[N][N]; // matriz original
   double deter;

   printf("\n");
   for(i = 0;i < N;i++){
      for(j = 0;j < N;j++){
         printf("Ingrese el numero %d,%d: ",i+1,j+1);
         scanf("%lf",&mat[i][j]);
      }
   }

   printf("\nMatriz original:\n");
   for(i = 0;i < N;i++){
      for(j = 0;j < N;j++)
         printf("%-3.0lf",mat[i][j]);
      printf("\n");
   }

   deter = invmat(N,mat);
   printf("\nMatriz inversa:\n");
   for(i = 0;i < N;i++){
      for(j = 0;j < N;j++)
         printf("%-12.6lf",mat[i][j]);
      printf("\n");
   }

   printf("\nDeterminante = %.2lf\n",deter);
   return 0;
}

// ************************* Descripción de funciones *************************
double invmat(int n, double MAT[][n]){
   int ROWS = n, COLS = 2*n, i, j, p;
   double piv, pivant = 1, INVMAT[n+1][2*n+1], det;

   for(i = 1;i <= ROWS;i++){
      for(j = 1;j <= COLS;j++)
         INVMAT[i][j] = 0;
   }

   for(i = 1;i <= ROWS;i++){
      for(j = n+1;j <= COLS;j++){
         if(i+n == j)
            INVMAT[i][j] = 1;
      }
   }

   for(i = 0;i < n;i++){
      for(j = 0;j < n;j++)
         INVMAT[i+1][j+1] = MAT[i][j];
   }

   for(p = 1;p <= ROWS;p++){
      piv = INVMAT[p][p];
      for(i = 1;i <= ROWS;i++){
         if(i != p){
            for(j = p+1;j <= COLS;j++)
               INVMAT[i][j] = (INVMAT[i][j]*piv - INVMAT[p][j]*INVMAT[i][p])/(pivant);
         }
      }

      for(i = 1;i <= ROWS;i++)
         if(i != p) INVMAT[i][p] = 0;
      pivant = piv;
   }

   det = INVMAT[n][n];
   if(det != 0){
      for(i = 1;i <= ROWS;i++){
         for(j = n+1;j <= COLS;j++)
            MAT[i-1][j-n-1] = INVMAT[i][j] / det;
      }
   }
   else{
      for(i = 1;i <= ROWS;i++){
         for(j = n+1;j <= COLS;j++)
            MAT[i-1][j-n-1] = -1;
      }
   }

   return det;
}
