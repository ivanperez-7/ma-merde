/*
Nombre: menuprincipal.c
Objetivo: Desplegar un menú principal con cuatro opciones diferentes
Autor: Iván Pérez Maldonado
Fecha: 28/01/2019
*/

#include <stdio.h>

void opA();
void opB();
void opC();
void opD();

int main(){
	char menu;

  // Menú principal
  printf("Menu principal\nA. Calcular la suma de dos numeros\nB. Calcular área y perímetro de un círculo\nC. Calcular superficie de una habitación\nD. Convertir °F a °C o °C a °F\n\nOpcion: ");
  scanf("%c",&menu);

  switch(menu){
    case('A'):
      opA();
      break;
    case('B'):
      opB();
      break;
    case('C'):
      opC();
      break;
    case('D'):
      opD();
      break;
    default:
      printf("Opcion no valida");
  }
	return 0;
}

// ************************** Descripción de funciones *****************************

void opA(){   // Suma de dos números cualesquiera
  float x,y,suma;

  printf("Ingresa los dos sumandos: ");
  scanf("%f %f",&x,&y);
  suma = x + y;
  printf("\nLa suma de los numeros es de %.2f",suma);
}

void opB(){   // Área y perímetro del círculo
  const float PI = 3.1416;
  float r,area,per;

  printf("Ingresa el radio del circulo: ");
  scanf("%f",&r);
  area = PI*r*r;
  per = PI*2*r;
  printf("\nEl area del circulo es de %.2f y su perimetro es de %.2f",area,per);
}

void opC(){     // Superficie de una habitación
  printf("");
}

void opD(){     // Conversión de grados de temperatura
  int op;
  double celsius = 0,fahren = 0;

  printf("\nSeleccione una opcion:\n1. °C a °F\n2. °F a °C\nOpcion: ");
  scanf("%d",&op);

  switch(op){
    case(1):
      printf("\nIngrese los grados Celsius: ");
      scanf("%lf",&celsius);
      fahren = (1.8)*(celsius + 32);
      printf("\n\nLos grados en Fahrenheit es de %.2lf",fahren);
      break;

    case(2):
      printf("\nIngrese los grados Fahrenheit: ");
      scanf("%lf",&fahren);
      celsius = (0.555555555555555555555555555)*(fahren - 32);
      printf("\n\nLos grados en Celsius es de %.2lf",celsius);
      break;

    default:
      printf("Opcion no valida\n");
  }
}
