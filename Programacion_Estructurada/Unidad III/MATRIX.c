/********************************
Nombre: MATRIX.c
Objetivo: Pruebas con matrices
Autor: Ivan Perez Maldonado
Fecha: 19/03/19
*********************************/

#include <stdio.h>

#define R 5
#define C 6

void sortrow(int row, int colmax, int arr[][colmax]);
void sortcol(int col, int rowmax, int arr[][C]);
void printm(int d1, int d2, int MAT[][C]);
void fswap(int *r, int *s);

int main(){
   int A[R][C] = {5,2,3,4,5,6,1,8,9,10,11,12,25,14,15,16,17,18,19,20,21,22,23,24,13,26,27,28,29,30}; // 5 filas con 6 columnas.
   int i,j;

   for(i = 0;i < R;i++){
      for(j = 0;j < C;j++)
         printf("%-3d",A[i][j]);
      printf("\n");
   }

   sortcol(0,5,A); printf("\n\n");
   printm(5,3,A);

	return 0;
}

// ************************ FUNCIONES ************************

void sortrow(int row, int colmax, int arr[][colmax]){
   int i,j,menor;

   for(i = 0;i <= colmax - 2;i++){
      menor = i;

      for(j = i + 1;j <= colmax - 1;j++){
         if(arr[row][j] < arr[row][menor])
            menor = j;
      }
      if(i != menor)
         fswap(&arr[row][menor],&arr[row][i]);
   }
}

void sortcol(int col, int rowmax, int arr[][C]){
   int i,j,menor;

   for(i = 0;i <= rowmax - 2;i++){
      menor = i;

      for(j = i + 1;j <= rowmax - 1;j++){
         if(arr[j][col] < arr[menor][col])
            menor = j;
      }
      if(i != menor)
         fswap(&arr[menor][col],&arr[i][col]);
   }
}

void printm(int d1, int d2,int MAT[][C]){
   int i,j;

   for(i = 0;i < d1;i++){
      for(j = 0;j < d2;j++)
         printf("%-3d",MAT[i][j]);
      printf("\n");
   }
}

void fswap(int *r, int *s){
   int x;

   x = *r;
   *r = *s;
   *s = x;
}
