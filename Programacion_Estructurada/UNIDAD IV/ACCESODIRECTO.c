#include <stdio.h>

#define NREGS 100

struct clientes{
	int nCuenta;
	char Apellido[50];
	char Nombre[50];
	double saldo;
};

int main(){
	int i;
	struct clientes bCliente = {0," "," ",0.0};
	FILE *fptr;
	
	if( (fptr = fopen("credito.dat","wb")) == NULL )
		printf("Error al abrir archivo");
	else{
		for(i = 1;i <= NREGS;i++)
			fwrite(&bCliente, sizeof(struct clientes), 1, fptr);
		fclose(fptr);
	}
	
	return 0;
}
