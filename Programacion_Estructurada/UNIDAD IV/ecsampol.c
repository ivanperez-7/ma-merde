#include <stdio.h>

int main() {
	char c;
	short s;
	int i;
	long lg;
	long long ll;
	float f;
	double d;
	long double ld;
	int array[20];
   int *ptr;
	int j, k; int *ptr1;

	j = 1; k=2;
	ptr = array;
	ptr1 = &k;

	printf("j = %d y su dirección es %p \n", j, (void *) &j);
	printf("k = %d y su dirección es %p \n", k, (void *) &k);
	printf("ptr1 = %p y su dirección es %p \n", j, (void *) &ptr1);
	printf("el valor entero que apunta ptr = %d  \n", *ptr1);
   printf("\n");
	printf("   sizeof c = %u \t sizeof(char) = %u \n", sizeof c, sizeof(char));
	printf("   sizeof s = %u \t sizeof(short) = %u \n", sizeof s, sizeof(short));
	printf("   sizeof i = %u \t sizeof(int) = %u \n", sizeof i, sizeof(int));
	printf("   sizeof lg = %u \t sizeof(long) = %u \n", sizeof lg, sizeof(long));
	printf("   sizeof ll = %u \t sizeof(long long) = %u \n", sizeof ll, sizeof(long long));
	printf("   sizeof f = %u \t sizeof(float) = %u \n", sizeof f, sizeof(float));
	printf("   sizeof d = %u \t sizeof(double) = %u \n", sizeof d, sizeof(double));
	printf("   sizeof ld = %u \t sizeof(long double) = %u \n", sizeof ld, sizeof(long double));
	printf("   sizeof array = %u \t sizeof(char) = %u \n", sizeof array, sizeof ptr);
	printf("ptr = %p y  su dirección es : %p \n", ptr, (void *) &ptr);

	return 0;
}
