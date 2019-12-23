#include <stdio.h>

#define NVENDS 16

int main(){
	struct ventas{
		char clave[5];
		char nombre[41];
		float vsem1;
		float vsem2;
		float vsem3;
		float vsem4;
		float vtotales;
		float comision;
	} ventasmes[NVENDS] = {
		{"7777", "Juan Camaney", 6800.00, 7500.00}, {"2777", "Pedro Páramo", 8800.00, 9500.00},
		{"1179", "Sofía Loren", 8900.00, 7300.00},{"3333", "Isela Blanco", 7800.00, 8500.00},
		{"6430", "Luis Conde", 6008.00, 4005.00},{"8884", "Pedro Junior", 8800.00, 9001.00},
		{"1101", "Pablo Coronel", 5800.00, 7500.00},{"7430", "José María", 5800.00, 6200.00},
		{"4321", "Juan Melgar", 7800.00, 7500.00},{"4345", "Carolina Monaco", 8800.00, 9500.00},
		{"1401", "Samanta Pérez", 9800.00, 1750.00},{"8406", "Tomás Aquino", 3368.00, 5578.00},
		{"4341", "Juan Escutia", 5800.00, 9500.00},{"4545", "Vicente Juárez", 7800.00, 1500.00},
		{"1901", "Stefany Zaldívar", 7800.00, 5750.00},{"9406", "Andrés Giñaq", 8368.00, 4578.00}
	};
	
	float totalcom = 0;
	struct ventas *ptr = &ventasmes[0];
	
	printf("Registro de ventas y comisiones.\n\n");
	for(int i = 0;i < NVENDS;i++){
		ptr->vtotales = ptr->vsem1 + ptr->vsem2;
		
		printf("Ingrese las ventas de la semana 3 de %s : ",ptr->nombre);
		scanf("%f",&ptr->vsem3);
		printf("Ingrese las ventas de la semana 4 de %s : ",ptr->nombre);
		scanf("%f",&ptr->vsem4);
		
		ptr->vtotales += ptr->vsem3 + ptr->vsem4;
		ptr->comision = ptr->vsem1*0.10 + ptr->vsem2*0.08 + ptr->vsem3*0.06 + ptr->vsem4*0.04;
		totalcom += ptr->comision;
		
		printf("\n");
		ptr++;
	}
	
	printf("%-8s%-30s%-10s%-10s%-10s%-10s%-10s%s\n","Clave","Nombre vendedor","VSem1","VSem2","VSem3","VSem4","VTotales","Comision");
	printf("=================================================================================================\n");
	ptr = &ventasmes[0];
	
	for(int i = 0;i < NVENDS;i++){
		printf("%-8s%-30s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%.2f\n",ptr->clave,ptr->nombre,ptr->vsem1,ptr->vsem2,ptr->vsem3,ptr->vsem4,ptr->vtotales,ptr->comision);
		ptr++;
	}
	
	printf("\nTotal de Comisiones : %.2f",totalcom);
	return 0;
}
