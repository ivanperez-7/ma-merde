/*
Nombre: velocdelaluz.c
Objetivo: Calcular la cantidad de energía necesaria para mover un cuerpo a la velocidad de la luz
Autor: Iván Pérez Maldonado
Fecha: 29/01/2019
*/

#include <stdio.h>

int main(){
  const float C = 2.997925E10; //        cm/seg
  float masa,energia;

  printf("Ingresa la masa del cuerpo: ");
  scanf("%f",&masa);

  energia = masa*C*C;
  printf("\nLa energia requerida es de %.2f",energia);

  return 0;
}
