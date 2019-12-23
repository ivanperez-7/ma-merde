/**************************************
Nombre: censo.c
Objetivo: Utilizar estructura de datos
Autor: Iván Pérez Maldonado
Fecha: 04/04/19
***************************************/

#include <stdio.h>
#include <string.h>

// ************************* Declaración de funciones *************************
void scans(char cad[], int MAX);

int main(){
    struct censo{
        char nombre[80];
        int edad;
        int telefono;
        char direccion[100];
    } persona1;

    printf("Ingrese el nombre de la persona: ");
    scans(persona1.nombre,80);

    while( strcmp(persona1.nombre,"Fin") != 0 ){
        printf("Ingrese la edad de la persona: ");
        scanf("%d",&persona1.edad);
        printf("Ingrese el telefono de la persona: ");
        scanf("%d",&persona1.telefono); getchar();
        printf("Ingrese la direccion de la persona: ");
        scans(persona1.direccion,100);

        printf("\nNombre:\t\t%s\nEdad:\t\t%d\nTelefono:\t%d\nDireccion:\t%s\n\n",persona1.nombre,persona1.edad,persona1.telefono,persona1.direccion);
        printf("Ingrese el nombre de la persona: ");
        scans(persona1.nombre,80);
    }

    return 0;
}

// ************************* Descripción de funciones *************************
void scans(char cadena[], int MAX){
    int c,i;

    for(i = 0;i < MAX - 1 && (c = getchar()) != EOF && c != 10;i++)
        cadena[i] = c;

    cadena[i] = 0;
}
