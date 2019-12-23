/******************************************
Nombre: sumaresta.c
Objetivo: Programa ejercitador para un niño
Autor: Ivan Perez Maldonado
Fecha: 26/02/19
*******************************************/

#include <stdio.h>
#include <time.h>

#define SIZE 10000

// ****************** Declaración de funciones ******************
double suma(double x, double y);
double resta(double x, double y);
double mult(double x, double y);
double div(double x, double y);

int main(){
   int x = 0, y = 0, opcion = -1, aciertos = 0, fallos = 0;
   double resultado = 0, prueba;

   printf("Te puedo ayudar a:\n1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n5. Resultados\n0. Fin");
   do {
      x = rand()%SIZE;
      if(x <= 7) x *= -1;
      y = rand()%SIZE;
      if(y <= 7) y *= -1;

      switch(opcion){
         case 1:
            printf("\nRealiza la operacion %d + %d\n",x,y);
            printf("Ingresa tu resultado obtenido: ");
            scanf("%lf",&resultado);

            prueba = suma(x,y);
            if(resultado == prueba)
               aciertos++;
            else
               fallos++;
            break;

         case 2:
            printf("\nRealiza la operacion %d - %d\n",x,y);
            printf("Ingresa tu resultado obtenido: ");
            scanf("%lf",&resultado);

            prueba = resta(x,y);
            if(resultado == prueba)
               aciertos++;
            else
               fallos++;
            break;

         case 3:
            printf("\nRealiza la operacion %d * %d\n",x,y);
            printf("Ingresa tu resultado obtenido: ");
            scanf("%lf",&resultado);

            prueba = mult(x,y);
            if(resultado == prueba)
               aciertos++;
            else
               fallos++;
            break;

         case 4:
            while(x % y != 0){
               x = rand()%SIZE;
               if(x <= 7) x *= -1;
            }
            printf("\nRealiza la operacion %d / %d\n",x,y);
            printf("Ingresa tu resultado obtenido: ");
            scanf("%lf",&resultado);

            prueba = div(x,y);
            if(resultado == prueba)
               aciertos++;
            else
               fallos++;
            break;

         case 5:
            printf("Llevas %d aciertos y %d fallos. \n",aciertos,fallos);
            break;

         default:
            ;
      }

      printf("\n\nIngresa una opcion: ");
      scanf("%d",&opcion);
   } while(opcion != 0);

   printf("\nGracias y vuelva pronto C:");
   return 0;
}

// ****************** Descripción de funciones ******************
double suma(double x, double y){
   return (x + y);
}

double resta(double x, double y){
   return (x - y);
}

double mult(double x, double y){
   return (x * y);
}

double div(double x, double y){
   return (x / y);
}
