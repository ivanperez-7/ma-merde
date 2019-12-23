/************************************
Nombre: frases.c
Objetivo: Generador de frases random
Autor: Ivan Perez Maldonado
Fecha: 12/04/19
*************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define nOrac 15

int main(){
   int i;
   char mat1[15][20] = {
   "Tengo", "Puedo", "Oigo", "Yo", "Quiero", "Veo", "Hay", "Raro", "Estoy", "Soy", "Hoy", "Consumo", "Tomo", "Voy", "Como"
   };
   char mat2[15][20] = {
   "droga", "perro", "arbol", "fluidos", "cristal", "servilleta", "palo", "crack", "tenedor", "arena", "tenedor", "trapo", "escoba", "pelo", "ojo"
   };
   char mat3[15][20] = {
   "raro", "bueno", "malo", "cuchara", "negra", "mano", "gorra", "dulce", "panucho", "taco", "arroz", "aqui", "alla", "pollo", "frijol"
   };

   srand(time(NULL));
   for(i = 0;i < 1001;i++){
      printf("%s ",mat1[rand()%nOrac]);
      printf("%s ",mat2[rand()%nOrac]);
      printf("%s\n\n",mat3[rand()%nOrac]);
   }

   return 0;
}
