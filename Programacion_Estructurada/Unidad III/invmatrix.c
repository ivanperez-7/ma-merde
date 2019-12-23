/*****************************************************************
Nombre: invmatrix.c
Objetivo: Calcular la inversa de una matriz con el método Montante
Autor: Iván Pérez Maldonado
Fecha: 19/03/19
*****************************************************************/

#include <stdio.h>

#define N 2

// ************************* Declaración de funciones *************************
double invmat(int n, double MAT[][n]);
double invmat2(int n, double MAT[][n], double TARG[][n]);

int main(){
   int i,j;
   double mat[N][N] = {9,7,0,2}; // matriz original
   double deter;

   for(i = 0;i < N;i++){
      for(j = 0;j < N;j++)
         printf("%-3.0lf",mat[i][j]);
      printf("\n");
   }

   deter = invmat(N,mat);
   printf("\n\nDeterminante = %.2lf\n\n",deter);
   for(i = 0;i < N;i++){
      for(j = 0;j < N;j++)
         printf("%-12.6lf",mat[i][j]);
      printf("\n");
   }

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

double invmat2(int n, double MAT[][n], double TARG[][n]){
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
            TARG[i-1][j-n-1] = INVMAT[i][j] / det;
      }
   }
   else{
      for(i = 1;i <= ROWS;i++){
         for(j = n+1;j <= COLS;j++)
            TARG[i-1][j-n-1] = -1;
      }
   }

   return det;
}
