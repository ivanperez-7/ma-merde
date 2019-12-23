/******************************************
Nombre: fstrings.c
Objetivo: Funciones con cadenas en string.h
Autor: Iv�n P�rez Maldonado
Fecha: 28/03/19
*******************************************/

#include <stdio.h>
#include <string.h>

int main(){
	//Funci�n strcpy

	/*
	char nombre[7]= "Oscar" ;
	char oscar[7];

	strcpy(oscar, nombre);
	printf("El nombre es: %s", oscar);
	*/

	//Funci�n strncpy

   /*
	char nombre[7] = "Hola" ;
	char oscar[7];

	strncpy(oscar, nombre, 2);
	printf("Las primeras dos letras del nombre son: %s",oscar);
   */

	// Funci�n strcmp

	/*
	char s1[3] = "Oso";
	char s2[3] = "oso";
	int i;

	printf( "%s\t", s1 );
	printf( "%s\n", s2 );

	i = strcmp(s1, s2);
	if(i==0)
		printf("Las cadenas son iguales");
	else
		printf("Las cadenas son diferentes");
	*/

	//Funci�n strncmp

	/*
	char s1[3] = "Oso";
	char s2[3] = "oso";
	int i;

	printf( "%s\t", s1 );
	printf( "%s\n", s2 );

	i = strncmp(s1, s2, 2);
	if(i==0)
		printf("Las primeras dos letras son iguales");
	else
		printf("Las primeras dos letras son diferentes");
	*/

	//Funci�n strncmpi

	/*
	char str1[] = "hola" ;
	char str2[] = "hola" ;

	int j = strcmpi ( str1, str2 ) ;

	if(j == 0)
		printf("Las cadenas son iguales");
	else("");
	*/

	//Funci�n strcat

	/*
	char nombre[10] = "Alberto";
	char apellido[10] = " Leyva";

	strcat(nombre, apellido);
	printf("%s", nombre);
	*/

	//Funci�n strncat

	/*
	char nombre[10] = "Alberto";
	char apellidos[20] = " Leyva Mart�nez";

	strncat(nombre, apellidos, 8);
	printf("%s", nombre);
	*/

	//Funci�n strlen

	/*
	char s1[50] = "Banda Tierra Sagrada";
	int len;

	len = strlen(s1);

	printf("El largo de %s es %d", s1, len);
	*/

	//Funci�n strlwr

	/*
	char nombre[50] = "AlBerTo LEYvA";

	strlwr(nombre);
	printf("%s", nombre);
	*/

	//Funci�n strset

	/*
	char contrasena[10] = "salu2";

	strset(contrasena, '*');
	printf("%s", contrasena);
	*/

	//Funci�n strpbrk

	/*
	char s1[5] = "12345";
	char s2[5] ="56789";
	char *i;

	i = strpbrk(s1, s2);
	printf("Hay %c caracteres iguales", *i);
	*/

	//Funci�n strrev

	/*
	char palabra[6] = "salu2";

	strrev(palabra);
	printf("La palabra al reves es %s", palabra);
	*/

	return 0;
}

