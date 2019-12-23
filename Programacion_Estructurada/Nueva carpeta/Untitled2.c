#include <stdio.h>

int main(){
   double f = 0,c;

   printf("Tabla de conversion Fahrenheit a Celsius\n");
   printf("\n%-12s %-5s","Fahrenheit","Celsius");

   while(f <= 400){
      c = (0.555555555555555555555555555)*(f - 32);
      printf("\n%-12.1lf %-5.2lf",f,c);
      f += 10;
   }
   return 0;
}
