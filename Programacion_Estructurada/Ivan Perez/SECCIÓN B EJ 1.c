#include <stdio.h>

#define NCAL 100

int main(){
	int Calif[NCAL];
	int reprobados = 0, suficiente = 0, sobresaliente = 0, excelente = 0;
	
	printf("Registro de calificaciones.\n\n");
	for(int i = 0;i < NCAL;i++){
		printf("Calificacion %d : ",i+1);
		scanf("%d",&Calif[i]);
		
		if(Calif[i] >= 0 && Calif[i] < 70)
			reprobados++;
		else if(Calif[i] >= 70 && Calif[i] < 80)
			suficiente++;
		else if(Calif[i] >= 80 && Calif[i] < 90)
			sobresaliente++;
		else if(Calif[i] >= 90 && Calif[i] <= 100)
			excelente++;
	}
	
	printf("\n===========\nResultados\n===========\n");
	printf("Excelente : %d\nSobresaliente : %d\nSuficiente : %d\nReprobados : %d",excelente,sobresaliente,suficiente,reprobados);

	return 0;
}
