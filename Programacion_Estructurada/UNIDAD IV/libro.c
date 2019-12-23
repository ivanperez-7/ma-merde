/*****************************
Nombre: libro.c
Objetivo: Ejemplo de registro
Autor: Iván Pérez Maldonado
Fecha: 2/4/19
******************************/

#include <stdio.h>

int main(){
   struct libro{
      char titulo[50];
      char nombre[50];
      char editorial[50];
      int edicion;
      char ISBN[20];
   } libro1 = {"Hola mundo","xdxdxdxd","Yo merengues",666,"482039233-12"};

   printf("Titulo:\t\t%s\nNombre:\t\t%s\nEditorial:\t%s\nEdicion:\t%d\nISBN:\t\t%s",libro1.titulo,libro1.nombre,libro1.editorial,libro1.edicion,libro1.ISBN);

	return 0;
}
