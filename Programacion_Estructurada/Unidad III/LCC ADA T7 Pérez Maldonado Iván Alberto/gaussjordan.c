/*******************************************************
Nombre: gaussjordan.c
Objetivo: Invertir matriz con el método de Gauss-Jordan
Autor: Iván Pérez Maldonado
Fecha: 17/04/19
********************************************************/

#include <stdio.h>

// ************************* Declaración de funciones *************************
void invmat(int n, double MAT[][n]);
void inter(double ren[], double target[], int MAXL);
void multren(double ren[], double C, int MAXL);
void multsuma(double ren[], double target[], double C, int MAXL);

int main(){
   int i,j,N;

   printf("================\nInvertir matriz\n================\n");
   printf("Ingrese la longitud de la matriz: ");
   scanf("%d",&N);
   double mat[N][N]; // matriz original

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

   invmat(N,mat);
   printf("\nMatriz inversa:\n");
   for(i = 0;i < N;i++){
      for(j = 0;j < N;j++)
         printf("%-12.6lf",mat[i][j]);
      printf("\n");
   }

   return 0;
}

// ************************* Descripción de funciones *************************
void invmat(int n, double MAT[][n]){
   int ROWS = n, COLS = 2*n, i, j, p;
   double piv, INVMAT[n+1][2*n+1];

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

   for(i = 1;i <= ROWS;i++){
      piv = INVMAT[i][i];
      multren(INVMAT[i],(1/piv),COLS);

      for(j = i + 1;j <= ROWS;j++)
         multsuma(INVMAT[i],INVMAT[j],-INVMAT[j][i],COLS);
   }

   for(i = ROWS - 1;i >= 1; i--){
      for(j = ROWS;j > i;j--)
         multsuma(INVMAT[j],INVMAT[i],-INVMAT[i][j],COLS);
   }

   for(i = 1;i <= ROWS;i++){
      for(j = n+1;j <= COLS;j++)
         MAT[i-1][j-n-1] = INVMAT[i][j];
   }
}

void inter(double ren[], double target[], int MAXL){
   int i;
   double temp;

   for(i = 1;i <= MAXL;i++){
      temp = ren[i];
      ren[i] = target[i];
      target[i] = temp;
   }
}

void multren(double ren[], double C, int MAXL){
   int i;

   for(i = 1;i <= MAXL;i++)
      ren[i] *= C;
}

void multsuma(double ren[], double target[], double C, int MAXL){
   int i;

   for(i = 1;i <= MAXL;i++){
      target[i] += ren[i] * C;
   }
}
