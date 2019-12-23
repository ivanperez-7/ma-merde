/*
Nombre: menuprincipal.c
Objetivo: Desplegar un men� principal con cuatro opciones diferentes
Autor: Iv�n P�rez Maldonado
Fecha: 28/01/2019
*/

#include <stdio.h>

void opA();
void opB();
void opC();
void opD();

int main(){
	char menu;

  // Men� principal
  printf("Menu principal\nA. Calcular la suma de dos numeros\nB. Calcular �rea y per�metro de un c�rculo\nC. Calcular superficie de una habitaci�n\nD. Convertir �F a �C o �C a �F\n\nOpcion: ");
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

// ************************** Descripci�n de funciones *****************************

void opA(){   // Suma de dos n�meros cualesquiera
  float x,y,suma;

  printf("Ingresa los dos sumandos: ");
  scanf("%f %f",&x,&y);
  suma = x + y;
  printf("\nLa suma de los numeros es de %.2f",suma);
}

void opB(){   // �rea y per�metro del c�rculo
  const float PI = 3.1416;
  float r,area,per;

  printf("Ingresa el radio del circulo: ");
  scanf("%f",&r);
  area = PI*r*r;
  per = PI*2*r;
  printf("\nEl area del circulo es de %.2f y su perimetro es de %.2f",area,per);
}

void opC(){     // Superficie de una habitaci�n
  printf("");
}

void opD(){     // Conversi�n de grados de temperatura
  int op;
  double celsius = 0,fahren = 0;

  printf("\nSeleccione una opcion:\n1. �C a �F\n2. �F a �C\nOpcion: ");
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
