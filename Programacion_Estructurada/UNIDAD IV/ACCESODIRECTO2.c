#include <stdio.h>

#define NREGS 100

struct clientes{
	int nCuenta;
	char Apellido[50];
	char Nombre[50];
	double saldo;
};

int main(){
	struct clientes bCliente = {0," "," ",0.0};
	FILE *fptr;
	
	printf("Banco nacional del norte\nRegistro de saldos de clientes\n\n");
	
	if( (fptr = fopen("credito.dat","rb+")) == NULL )
		printf("Error al abrir archivo");
	else{
		printf("Numero de cuenta : ");
		scanf("%d",&bCliente.nCuenta);
		
		while(bCliente.nCuenta != 0){
			printf("Apellido del cliente : ");
			scanf(" %s",bCliente.Apellido);
			printf("Nombre del cliente : ");
			scanf(" %s",bCliente.Nombre);
			printf("Saldo cuenta : ");
			scanf("%lf",&bCliente.saldo);
			
			fseek(fptr,(bCliente.nCuenta-1)*sizeof(struct clientes),SEEK_SET);
			fwrite(&bCliente, sizeof(struct clientes), 1, fptr);
			
			printf("\nNumero de cuenta : ");
			scanf("%d",&bCliente.nCuenta);
		}
	}

	return 0;
}
