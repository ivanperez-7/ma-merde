#include <stdio.h>

#define MAX 5

void scanarr(float arr[], int MAXL);
void printarr(float arr[], int MAXL);
void arrsum(float arr[], float arr2[], float arr3[], int MAXL);
void arrdif(float arr[], float arr2[], float arr3[], int MAXL);
void arrzero(float arr[], int MAXL);
void arrone(float arr[], int MAXL);

int main(){
	float v1[MAX], v2[MAX], v3[MAX];
	
	
	return 0;
}

// ******************** FUNCIONES ********************

void scanarr(float arr[], int MAXL){
	int i;
	
	for(i = 0;i < MAXL; i++){
		printf("Ingrese el dato %d: ",i+1);
		scanf("%f",&arr[i]);
	}
}

void printarr(float arr[], int MAXL){
	int i;
	
	printf("[");
	for(i = 0;i < MAXL - 1; i++)
		printf("%.2f, ",arr[i]);
	printf("%.2f]",arr[i]);
}

void arrsum(float arr[], float arr2[], float arr3[], int MAXL){
	int i;
	
	for(i = 0;i < MAXL; i++)
		arr3[i] = arr[i] + arr2[i];
}

void arrdif(float arr[], float arr2[], float arr3[], int MAXL){
	int i;
	
	for(i = 0;i < MAXL; i++)
		arr3[i] = arr[i] - arr2[i];
}

void arrzero(float arr[], int MAXL){
	int i;
	
	for(i = 0;i < MAXL;i++)
		arr[i] = 0;
}
	
void arrone(float arr[], int MAXL){
	int i;
	
	for(i = 0;i < MAXL;i++)
		arr[i] = 1;
}
