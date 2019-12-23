/***********************************************
Nombre: menuactividades.c
Objetivo: Desplegar un menu con varias opciones
Autor: Ivan Alberto Perez Maldonado
Fecha: 16/04/19
************************************************/

#include <stdio.h>
#include <stdlib.h>

// *************** Declaración de funciones ***************
void opc1();
void opc2();
void opc3();
void opc4();

int main(){
   int opcion;
   char c = 32;

   do {
      system("cls");
      printf("Menu principal\n1.- Calcular factorial de un numero\n2.- Calcular area de un circulo\n");
      printf("3.- Numero de vocales en una oracion\n4.- Numero mayor de tres numeros\n5.- Salir\n\n");

      do {
         printf("Seleccione una opcion: ");
         scanf("%d",&opcion);
      } while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5);

      if(opcion !=5)
         system("cls");

      switch(opcion){
         case 1:
            opc1();
            break;

         case 2:
            opc2();
            break;

         case 3:
            opc3();
            break;

         case 4:
            opc4();
            break;

         case 5:
            printf("\nDesea salir del programa? (Y/N) ");
            scanf(" %c",&c);

         default: ;
      }
   } while(c != 'y' && c != 'Y');

   return 0;
}

// *************** Descripción de funciones ***************
void opc1(){
   int num, mult;
   double fact = 1;

   printf("=======================\nFactorial de un numero\n=======================");
   printf("\nIngresa un numero entero no negativo: ");
   scanf("%d",&num);

   if(num < 0)
      printf("\nNo es posible calcular el factorial.\n");
   else if(num == 0)
      printf("\nEl factorial del numero es 1\n");

   else{
      for(mult = num;mult >= 1;mult--)
         fact *= mult;

      printf("\nEl factorial de %d es %.0lf\n",num,fact);
   }
   system("pause");
}

void opc2(){
   const float PI = 3.14159265359;
   double radio, area;

   printf("====================\nArea de un circulo\n====================\n");
   printf("Ingresa el radio del circulo: ");
   scanf("%lf",&radio);

   area = PI * radio * radio;
   printf("\nEl area del circulo es %.4lf\n",area);

   system("pause");
}

void opc3(){
   int cont = 0;
   char c;

   getchar();
   printf("=============================\nNumero de vocales en oracion\n=============================");
   printf("\nIngrese una oracion:\n");

   c = getchar();
   while(c != 0 && c != '\n' && c != EOF){
      if(c == 65 || c == 69 || c == 73 || c == 79 ||  c == 85 || c == 97 || c == 101 || c == 105 || c == 111 || c == 117)
         cont++;

      c = getchar();
   }

   printf("\nLa oracion tiene %d vocales\n",cont);
   system("pause");
}

void opc4(){
   double num, mayor;

   printf("=============================\nNumero mayor de tres numeros\n=============================");
   printf("\nIngresa un numero: ");
   scanf("%lf",&num);

   mayor = num;
   printf("Ingrese otro numero: ");
   scanf("%lf",&num);

   if(num > mayor)
      mayor = num;
   printf("Ingrese otro numero: ");
   scanf("%lf",&num);

   if(num > mayor)
      mayor = num;
   printf("\nEl numero mayor de los tres es %.2lf\n",mayor);

   system("pause");
}
