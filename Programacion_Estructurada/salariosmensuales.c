/*********************************************************************
Nombre: salariosmensuales.c
Objetivo: Calcular el salario mensual de los empleados en una empresa
Autor: Ivan Perez Maldonado
Fecha: 15/02/2019
**********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scans(char cad[], int MAX);

int main(){
   char nombre[40], t;
   int i;
   double tasaimp, sueldohora, horasreg, horasextra, sueldoextra, sueldobruto, sueldoneto, prest, sueldoprest, sueldoimp;

   printf("Introduce la tasa de impuestos: ");
   scanf("%lf",&tasaimp);
   printf("Introduce el sueldo por hora: ");
   scanf("%lf",&sueldohora);
   printf("\nIntroduce el nombre del empleado: ");
   getchar();
   scans(nombre,40);

   while( strcmp(nombre,"Fin") && strcmp(nombre,"FIN") ){
      printf("Introduce las horas trabajadas: ");
      scanf("%lf",&horasreg);
      printf("Tipo de empleado:\nA = Administrativo\nD = Docente\nM = Manual\n");

      do {
         printf("Introduce una opcion: ");
         getchar();
         t = getchar();
      } while(t != 'A' && t != 'D' && t != 'M' && t != 'a' && t != 'd' && t != 'm');

      sueldoextra = 0.0;
      horasextra = 0.0;
      if(horasreg > 40){
         horasextra = horasreg - 40.0;
         horasreg -= horasextra;
         sueldoextra = horasextra * sueldohora * 1.5;
      }

      switch(t){
         case 'A':
         case 'a':
            prest = 0.05;
            break;

         case 'D':
         case 'd':
            prest = 0.02;
            break;

         case 'M':
         case 'm':
            prest = 0.08;
            break;

         default:
               ;
      }

      sueldoprest = (horasreg * sueldohora + sueldoextra) * (prest);
      sueldobruto = (horasreg * sueldohora + sueldoextra) + sueldoprest;
      sueldoimp = (sueldobruto) * (tasaimp / 100);
      sueldoneto = sueldobruto - sueldoimp;

      printf("\n%54s %30s","Horas","Sueldo");
      printf("\n%-40s %-13s %-15s %-15s %-15s %-13s %s\n","Nombre del empleado","Regulares","Extra","Bruto","Neto","Impuesto", "Prestacion");
      for(i = 0;i < 127;i++) printf("=");
      printf("\n%-40s %-13.2lf %-15.2lf %-15.2lf %-15.2lf %-13.2lf %.2lf \n",nombre,horasreg,horasextra,sueldobruto,sueldoneto,sueldoimp,sueldoprest);

      printf("\n\nIntroduce el nombre del empleado: ");
      getchar();
      scans(nombre,40);
   }

   return 0;
}

// ****************** Descripción de funciones ******************

int scans(char cadena[], int MAX){
   int i, c;

   for(i = 0;i < MAX - 1 && (c = getchar()) != EOF && c != 10;i++)
      cadena[i] = c;

   cadena[i] = 0;
}
