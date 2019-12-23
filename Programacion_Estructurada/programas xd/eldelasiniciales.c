/*
Nombre: eldelasiniciales.c
Objetivo: Solicitar iniciales de un nombre e imprimirlas
Autor: Iván Pérez Maldonado
Fecha: 29/01/2019
*/

#include <stdio.h>

int main(){
  char a,b,c,d;
  int opcion;

  printf("Introduce las iniciales de tu nombre completo (dos nombres y dos apellidos): ");
  scanf("%c %c %c %c",&a,&b,&c,&d);
  printf("\nPor favor, escoja una opcion\n1. Imprimir iniciales separadas por puntos\n2. Imprimir iniciales en ASCII\n\nOpcion: ");
  scanf("%d",&opcion);

  if(opcion == 1) printf("\n%c.%c.%c.%c.",a,b,c,d);
  else if(opcion == 2) printf("\n%d %d %d %d",a,b,c,d);
  else printf("\nOpcion no valida");

  return 0;
}
