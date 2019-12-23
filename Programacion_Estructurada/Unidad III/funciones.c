/*****************************************************************
Nombre: funciones.c
Objetivo: Simular funciones para el manejo de cadenas y caracteres
Autor: Ivan Perez Maldonado
Fecha: 28/02/19
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// ****************** Declaración de funciones ******************
void scans(char cad[], int MAX);
void sortarr(int cad[], int MAX);
void sortarr2(int cad[], int MAX);
int BBinaria(int cad[], int valor, int MAX);
int leecadena(char cadena[]);
int es_primo(int num);
int copystring(char cad[], char nueva[], int MAX);
void printarr(int cad[], int longitud);
void fswap(int *r, int *s);
void factores(int num);
double factorial(int num);
double nCr(int n, int r);
double nPr(int n, int r);

int main(int argc,char *argv[]){
   /*
   char cadena[200];
   int longitud = 0;

   printf("Ingrese el texto:\n");
   scans(cadena,200);
   longitud = leecadena(cadena);

   printf("\nLongitud de la cadena: %d",longitud);
   */
   /*
   const int LONGITUD = 20;
   char cadena[LONGITUD];
   char nueva[LONGITUD];

   printf("Ingrese el texto:\n");
   scans(cadena,LONGITUD);

   copystring(cadena,nueva,LONGITUD);
   printf("\nNueva cadena: %s",nueva);
   */
   /*
   int suma = 0, i;

   for(i = 0;i < argc;i++){
      suma += atoi(argv[i]);
   }
   printf("Suma = %d\n\nLista de argumentos:",suma);
   for(i = 1;i < argc;i++)
      printf("\n%d",atoi(argv[i]));
   */
   /*
   char cadena[11];
   printf("Cadena: ");
   scans(cadena,11);
   printf("Cadena ingresada: %s\nLongitud de cadena: %d",cadena,leecadena(cadena));
   */
   /*
   int r = 10, s = 20;

   printf("Antes: r = %d, s = %d",r,s);
   fswap(&r,&s);
   printf("\nDespues: r = %d, s = %d",r,s);
   */
   int arreglo[6] = {5,8,-43,9,0,7},i;

   printf("Antes = ");
   printarr(arreglo,6);

   sortarr(arreglo,6);

   printf("\n\nDespues = ");
   printarr(arreglo,6);
   printf("\nBusqueda binaria = %d",BBinaria(arreglo,7,6));

   return 0;
}

// ****************** Descripción de funciones ******************

void scans(char cadena[], int MAX){
   int c,i;

   for(i = 0;i < MAX - 1 && (c = getchar()) != EOF && c != 10;i++)
      cadena[i] = c;

   cadena[i] = 0;
}

void sortarr(int cad[], int MAX){
   int i,j,menor;

   for(i = 0;i <= MAX - 2;i++){
      menor = i;

      for(j = i + 1;j <= MAX - 1;j++){
         if(cad[j] < cad[menor])
            menor = j;
      }
      if(i != menor)
         fswap(&cad[menor],&cad[i]);
   }
}

void sortarr2(int cad[], int MAX){
   int i,j,mayor;

   for(i = 0;i <= MAX - 2;i++){
      mayor = i;

      for(j = i + 1;j <= MAX - 1;j++){
         if(cad[j] > cad[mayor])
            mayor = j;
      }
      if(i != mayor)
         fswap(&cad[mayor],&cad[i]);
   }
}

int BBinaria(int cad[], int valor, int MAX){
   int vmedio = 0, a = 0, b = MAX - 1, tf = FALSE, pos = -1;

   while(a < b && tf == FALSE){
      vmedio = (a+b+1)/2;

      if(cad[vmedio] == valor){
         pos = vmedio;
         tf = TRUE;
      }
      else if(cad[vmedio] < valor)
         a = vmedio+1;
      else if(cad[vmedio] > valor)
         b = vmedio-1;
   }

   return pos;
}

int leecadena(char cadena[]){
   int i = 0, caracteres = 0;

   for(i = 0;cadena[i] != 0 && cadena[i] != EOF;i++)
      caracteres++;

   return (caracteres);
}

int es_primo(int num){
   int primo = TRUE, div = 2;

   if(num <= 1)
      primo = FALSE;
   else{
      while(div < num && primo == TRUE){
         if(num % div == 0)
            primo = FALSE;
         div++;
      }
   }

   return primo;
}

int copystring(char cad[], char nueva[], int MAX){
   int i;

   for(i = 0;i < MAX - 1 && (cad[i]) != EOF && cad[i] != 10;i++)
      nueva[i] = cad[i];

   nueva[i] = 0;
   return i;
}

void printarr(int cad[], int longitud){
   int i;

   printf("[");
   for(i = 0;i < longitud - 1;i++)
      printf("%d, ",cad[i]);
   printf("%d]",cad[i]);
}

void fswap(int *r, int *s){
   int x;

   x = *r;
   *r = *s;
   *s = x;
}

void factores(int num){
   int div = 2, unidad = 1;

   if(num == 0)
      printf("0 = 1 x 0");
   else if(num == 1)
      printf("1 = 1 x 1");
   else if(num == -1)
      printf("-1 = 1 x -1");
   else{
      if(num < 0)
         unidad = -1;
      while(num % div != 0) div++;
      printf("%d = %d x %d",num,unidad,div);
      num /= div;

      div = 2;
      if(num < 0)
         num *= -1;
      while(div <= num){
         if(num % div == 0){
            printf(" x %d",div);
            num /= div;
            div = 2;
         }
         else
            div++;
      }
   }
}

double factorial(int num){
   double resultado = 1, i = 0;

   if(num >= 2){
      while(i < num){
         resultado *= num - i;
         i++;
      }
   }

   return resultado;
}

double nCr(int n, int r){
   double resultado;

   if(r == 0)
      resultado = 1;
   else if(n == 0 || r > n)
      resultado = 0;
   else
      resultado = ( factorial(n) )/( (factorial(r))*(factorial(n-r)) );

   return resultado;
}

double nPr(int n, int r){
   double resultado;

   if(r == 0)
      resultado = 1;
   else if(n == 0 || r > n)
      resultado = 0;
   else
      resultado = ( factorial(n) )/( (factorial(n-r)) );

   return resultado;
}
