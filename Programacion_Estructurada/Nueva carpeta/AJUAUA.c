#include <stdio.h>

int main(){
   unsigned int n,m;

   printf("Introduzca dos numeros naturales: ");
   scanf("%u %u",&n,&m);

   if(n%m == 0){    // Prueba de divisibilidad
      printf("\n%u es multiplo de %u",n,m);
   }
   else{
      printf("\n%u no es multiplo de %u",n,m);
   }

   return 0;
}
