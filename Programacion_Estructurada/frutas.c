/*************************************************************************
Nombre: frutas.c
Objetivo: Calcular un monto de pago en dolares o euros y comparar en pesos
Autor: Ivan Perez Maldonado
Fecha: 21/02/19
**************************************************************************/

#include <stdio.h>

int main(){
   const int naranja = 5;
   const int manzana = 10;
   const int pera = 8;
   const float euro = 22.0;
   const float dolar = 19.0;
   int num, opcion, suma = 0;
   double pago;

   printf("Ingresa el numero de naranjas: ");
   scanf("%d",&num);
   suma += num * naranja;
   printf("Ingresa el numero de manzanas: ");
   scanf("%d",&num);
   suma += num * manzana;
   printf("Ingresa el numero de peras: ");
   scanf("%d",&num);
   suma += num * pera;

   printf("\nTipo de cambio:\n1.- Euro\n2.- Dolar\n");
   do {
      printf("Ingresa una opcion: ");
      scanf("%d",&opcion);
   } while(opcion != 1 && opcion != 2);

   printf("Ingrese el pago realizado: ");
   scanf("%lf",&pago);
   switch(opcion){
      case 1:
         pago *= euro;
         break;

      case 2:
         pago *= dolar;
         break;

      default:
         ;
   }

   if(pago == suma)
      printf("\nEl pago fue exacto");
   else if(pago > suma)
      printf("\nSobra dinero en el pago");
   else if(pago < suma)
      printf("\nFalta dinero en el pago");

   return 0;
}
