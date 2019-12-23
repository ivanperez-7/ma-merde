/*
Nombre: media.c
Objetivo: Obtener el promedio de una serie de n�meros
Autor: Iv�n P�rez Maldonado
Fecha: 29/01/2019
*/

#include <stdio.h>

int main() {
	double media = 0,num;
	int cont = 0;

  printf("Calcular promedio\n-1 para salir\n\nPrimer numero: ");
  scanf("%lf",&num);
  while(num != -1){
    media += num;
    cont++;
    printf("Siguiente numero: ");
    scanf("%lf",&num);
  }

  if(cont != 0) media /= cont;
  printf("\nEl promedio de los numeros es de %.3lf",media);

  return 0;
}
