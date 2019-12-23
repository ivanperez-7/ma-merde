/*************************************
Nombre: fechas.c
Objetivo: Uso de la función strtok()
Autor: Iván Pérez Maldonado
Fecha: 28/03/19
**************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char fecha[20], del[2] = "/";
	char meses[12][20] = {"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre","noviembre","diciembre"};
	int dia, mes, anio;

	printf("Ingrese una fecha dd/mm/aaaa: ");
	gets(fecha);

	dia = atoi(strtok(fecha,del));
	mes = atoi(strtok(NULL,del));
	anio = atoi(strtok(NULL,del));

	printf("\n%d de %s de %d\n",dia,meses[mes-1],anio);
	printf("%d de %s, %d\n",dia,meses[mes-1],anio);

	meses[mes-1][0] -= 32;
	printf("%s %d de %d\n",meses[mes-1],dia,anio);

	return 0;
}
