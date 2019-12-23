/*
Nombre: 
Objetivo: Calcula el sueldo de un empleado con base en las horas trabajadas
Autor: 
Fecha: 
*/

#include <stdio.h>

int main(){
	int numero,cont=0;
	float tasaimp,sueldohora,horas,montopago;
	
	printf("Tasa de impuestos: ");
	scanf("%f",&tasaimp);
	printf("Sueldo por hora: ");
	scanf("%f",&sueldohora);
	
	printf("\nNo. empleado    Horas trabajadas    Impuestos   Pago Neto\n");
	printf("************    ****************    *********   *********\n");
	
	printf("Numero de empleado: ");
	scanf("%d",&numero);
	while(numero!=0){
		cont++;
		printf("Numero de horas trabajadas: ");
		scanf("%f",&horas);
		montopago = horas*sueldohora;
		montopago = montopago - montopago*tasaimp/100.0;
		printf("%d	%.2f	%.2f	%8.2f\n\n",numero,horas,tasaimp,montopago);
		printf("Numero de empleado: ");
		scanf("%d",&numero);
	}
	printf("\n\nNumeros de empleados: %d",cont);
	return 0;
}
