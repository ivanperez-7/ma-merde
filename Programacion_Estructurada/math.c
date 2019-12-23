/*
Nombre: math.c
Objetivo: Programa para probar las funciones de la librería math.h
Autor: Iván Pérez Maldonado
Fecha: 31/01/2019
*/

#include <stdio.h>
#include <math.h>

int main(){
  int op,num3;
  double num,num2,res;

  printf("Funciones de la libreria math.h\n\nSeleccione una opcion:\n");
  printf("1. ceil\n2. exp\n3. fabs\n4. floor\n5. fmod\n6. frexp\n7. ldexp\n8. log\n9. log10\n10. modf\n11. pow\n12. sqrt");
  printf("\n\nOpcion: ");
  scanf("%d",&op);

  switch(op){
    case(1):
      printf("\nIngrese un numero: ");
      scanf("%lf",&num);
      res = ceil(num);  // función techo
      printf("Salida: %.2lf",res);
      break;

    case(2):
      printf("\nIngrese un numero: ");
      scanf("%lf",&num);
      res = exp(num);   // se eleva el número Euler 'e' a un exponente 'x'
      printf("Salida: %.4lf",res);
      break;

    case(3):
      printf("\nIngrese un numero: ");
      scanf("%lf",&num);
      res = fabs(num);   // función valor absoluto
      printf("Salida: %.2lf",res);
      break;

    case(4):
      printf("\nIngrese un numero: ");
      scanf("%lf",&num);
      res = floor(num);  // función piso
      printf("Salida: %.2lf",res);
      break;

    case(5):
      printf("\nIngrese dos numeros: ");
      scanf("%lf %lf",&num,&num2);
      res = fmod(num,num2); // num reducción módulo num2
      printf("Salida: %.2lf",res);
      break;

    case(6):
      printf("\nIngrese dos numeros: ");
      scanf("%lf %d",&num,&num3);
      res = frexp(num,&num3); // numero fraccionado y luego elevado a potencia de dos
      printf("Salida: %.2lf",res);
      break;

    case(7):
      printf("\nIngrese dos numeros: ");
      scanf("%lf %d",&num,&num3);
      res = ldexp(num,num3); // numero multiplicado por 2^num3
      printf("Salida: %.2lf",res);
      break;

    case(8):
      printf("\nIngrese un numero: ");
      scanf("%lf",&num);
      res = log(num);  // función logaritmo natural
      printf("Salida: %.2lf",res);
      break;

    case(9):
      printf("\nIngrese un numero: ");
      scanf("%lf",&num);
      res = log10(num);  // función logaritmo base 10
      printf("Salida: %.2lf",res);
      break;

    case(10):
      printf("\nIngrese un numero: ");
      scanf("%lf",&num);
      res = modf(num,&num2); /*res representa la parte decimal del numero
                              mientras que num2 representa la parte entera*/
      printf("%lf = %lf + %lf",num,num2,res);
      break;

    case(11):
      printf("\nIngrese dos numeros: ");
      scanf("%lf %lf",&num,&num2);
      res = pow(num,num2);   // num^num2
      printf("Salida: %.2lf",res);
      break;

    case(12):
      printf("\nIngrese un numero: ");
      scanf("%lf",&num);
      res = sqrt(num);    // raíz cuadrada
      printf("Salida: %.3lf",res);
      break;

    default:
      printf("\nOpcion no valida");
  }

  return 0;
}
