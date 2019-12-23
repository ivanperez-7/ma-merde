/*
Nombre:
Objetivo:
Autor: Iván Pérez Maldonado
Fecha:
*/

#include <stdio.h>

int main(){
	int ncuenta;
	char nombre[50];
	float sueldo, monto;
	FILE *fptr;

	printf("Uso de archivos de acceso secuencial (Input)\n");
	monto = 0.0;

	if( (fptr = fopen("clientes.dat","r")) == NULL )
		printf("\nError al abrir archivo.");
	else{
		printf("\n%-20s%-20s Sueldo\n","Numero cuenta","Nombre");
		printf("==================================================\n");
		fscanf(fptr,"%d %s %f",&ncuenta,nombre,&sueldo);
		monto += sueldo;
		
		while(!feof(fptr)){
			printf("%-20d%-20s %.2f\n",ncuenta,nombre,sueldo);
			fscanf(fptr,"%d %s %f",&ncuenta,nombre,&sueldo);
			monto += sueldo;
		}
		
		printf("\n\nMonto final : %.2f",monto);
		fclose(fptr);
	}
	
	return 0;
}
