/******************************************
Nombre: jugadores.c
Objetivo: Estructura con datos de jugadores
Autor: Iván Pérez Maldonado
Fecha: 3/4/19
*******************************************/

#include <stdio.h>

int main(){
   struct jugador {
      char nombre[60];
      char equipo[60];
      int partidos;
      int goles;
      float promgoles;
   } jugador1 = {"El brayan","UFC",100,128}, jugador2, jugador3;

   jugador2 = jugador1;
   jugador3 = jugador2;

   jugador1.promgoles = (float)jugador1.goles / (float)jugador1.partidos;
   printf("Promedio jugador 1: %.2lf",jugador1.promgoles);

   jugador2.promgoles = (float)jugador2.goles / (float)jugador2.partidos;
   printf("\nPromedio jugador 2: %.2lf",jugador2.promgoles);

   jugador3.promgoles = (float)jugador3.goles / (float)jugador3.partidos;
   printf("\nPromedio jugador 3: %.2lf",jugador3.promgoles);

	return 0;
}
