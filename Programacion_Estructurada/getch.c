#include <stdio.h>
#include <conio.h>

int main(){
	char c;
	
	printf("Ingresa un caracter: ");
	do {
		c = getch();
		printf("\n%c, %d",c,c);
	} while (c != 'E');
	
	return 0;
}
