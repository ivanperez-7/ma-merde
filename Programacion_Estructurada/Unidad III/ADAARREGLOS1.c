/*
Nombre:
Objetivo:
Autor: Ivan Perez Maldonado
Fecha: 22/03/19
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 220

// ************************* Declaración de funciones *************************
double Media(int n, int a[]);
double Mediana(int n, int a[]);
int Moda(int n, int a[], int frec[10]);
void BurbujaSort(int n, int a[]);
void ImprimeArreglo(int n, int a[]);

int main(){
   int i,j;
   int respuestas[NMAX], frecuencias[10];

   srand(time(NULL));   // semilla
   for(i = 0;i < NMAX;i++)
      respuestas[i] = rand()%9 + 1;  // enteros 1 <= n <= 9

   printf("====================\nMatriz generada\n====================\n");
   ImprimeArreglo(NMAX,respuestas);

   printf("\n\n=========\nMedia\n=========\nLa media de los datos es de %.2lf",Media(NMAX,respuestas));
   printf("\n\n=========\nMediana\n=========\nLa mediana de los datos es %.2lf",Mediana(NMAX,respuestas));
   printf("\n\n=========\nModa\n=========\nLa moda de los datos es %d",Moda(NMAX,respuestas,frecuencias));

   printf("\n\nSe presenta un histograma con las frecuencias:\n\n");
   for(i = 1;i < 10;i++){
      printf("   %-3d|",i);
      for(j = 1;j <= frecuencias[i];j++) printf("*");
      printf("   %d\n",frecuencias[i]);
   }

	return 0;
}

// ************************* Descripción de funciones *************************
double Media(int n, int a[]){
   double media = -1;
   int suma = 0, i;

   if(n > 0){
      for(i = 0;i < n;i++)
         suma += a[i];
      media = (float)suma / (float)n;
   }

   return media;
}

double Mediana(int n, int a[]){     // el arreglo debe estar ordenado de menor a mayor.
   double med = -1;

   if(n > 0){
      BurbujaSort(n,a);
      med = (float)(a[n/2 - 1] + a[n/2]) / (float)(2);
   }

   return med;
}

int Moda(int n, int a[], int frec[10]){
   int moda = -1, i, j;

   for(i = 0;i < 10;i++) frec[i] = 0;

   if(n > 0){
      for(i = 0;i < n;i++)
         frec[a[i]]++;

      for(i = 1;i < 10; i++){
         if(frec[i] > moda){
            moda = frec[i];
            j = i;
         }
      }
   }
   return j;
}

void BurbujaSort(int n, int a[]){
   unsigned int pass; // contador de paso
	unsigned int j; // contador de comparación
	unsigned int hold;

	for ( pass = 1; pass < n; ++pass ) {   // número de pasos
      for ( j = 0; j < n - pass; ++j ) { // número de comparaciones por paso
			if ( a[j] > a[j+1] ) {        // intercambia elementos desordenados
				hold = a[j];
				a[j] = a[j+1];
				a[j+1] = hold;
			}
		}
	}
}

void ImprimeArreglo(int n, int a[]){
   int i;

   for(i = 0;i < n- 1;i++){
      printf("%d ",a[i]);
      if((i+1) % 20 == 0) printf("\n");
   }
   printf("%d",a[i]);
}
