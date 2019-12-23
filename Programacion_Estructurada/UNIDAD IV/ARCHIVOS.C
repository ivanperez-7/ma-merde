/****************************
Nombre: ARCHIVOS.c
Objetivo: cdwewefjiowefjiofw
Autor: Iván Pérez Maldonado
Fecha: 2/05/19
*****************************/

#include <stdio.h>

int main(){
	int ncuenta;
	char nombre[50];
	float sueldo;
	FILE *fapt;
	
	printf("Sistema de registros\n\n");
	
	if( (fapt = fopen("clientes.dat","a")) != NULL ){
		printf("No. de cuenta : ");
		scanf("%d",&ncuenta);
		
		while(ncuenta != 0){
			printf("Nombre del cliente: ");
			scanf(" %s",nombre);
			
			printf("Sueldo: ");
			scanf("%f",&sueldo);
			
			fprintf(fapt,"%d %s %.2f\n",ncuenta,nombre,sueldo);
			printf("\nNo. de cuenta : ");
			scanf("%d",&ncuenta);
		}
		fclose(fapt);
	}

    return 0;
}
