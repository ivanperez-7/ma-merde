/********************************************************************
Nombre: pesoideal.c
Objetivo: Calcular el peso ideal y calorias a consumir de una persona
Autor: Ivan Perez Maldonado
Fecha: 19/02/2019
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(){
   int indep, op, actividad;
   double altura, pesoideal, calorias;
   char sex;

   printf("Sexo de la persona:\nH = Hombre\nM = Mujer\n");
   do {
      printf("Selecciona una opcion: ");
      fflush(stdin);
      sex = getchar();
   } while(sex != 'H' && sex != 'h' && sex != 'M' && sex != 'm');

   switch(sex){
      case 'H':
      case 'h':
         indep = 22;
         break;

      case 'M':
      case 'm':
         indep = 21;

      default:
         ;
   }

   printf("\nIngresa la altura en metros: ");
   scanf("%lf",&altura);
   printf("\nActividad fisica:\n1.- Muy ligera\n2.- Ligera\n3.- Moderada\n4.- Pesada\n");
   do {
      printf("Selecciona una opcion: ");
      fflush(stdin);
      scanf("%d",&op);
   } while(op != 1 && op != 2 && op != 3 && op != 4);

   switch(op){
      case (1):
         if(sex == 'H' || sex == 'h')
            actividad = 32;
         else
            actividad = 28;
         break;

      case (2):
         if(sex == 'H' || sex == 'h')
            actividad = 35;
         else
            actividad = 30;
         break;

      case (3):
         if(sex == 'H' || sex == 'h')
            actividad = 37;
         else
            actividad = 32;
         break;

      case (4):
         if(sex == 'H' || sex == 'h')
            actividad = 40;
         else
            actividad = 35;
         break;

      default:
         ;
   }

   pesoideal = 2 * altura * indep;
   calorias = pesoideal * actividad;

   system("cls");
   printf("\nEl peso ideal es de %.2lf",pesoideal);
   printf("\nLa cantidad de calorias que se deben consumir son %.2lf\n",calorias);
   return 0;
}
