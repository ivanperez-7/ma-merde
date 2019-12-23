#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0
#define DELAY 4000

#define DESC 1
#define NDESC 0
#define BANDERA -2
#define FALLO -3

#define BLANCO 0
#define MINA -1

#define ABRIR 13
#define SALIR 27

int FILAS, COLS, nMinas, mostrar = FALSE;
int Jf, Jc;		// Jugada fila, jugada columna
char nivel;

// ***************** Descripción de funciones *****************
void Juego();
void ObtenerNivel();
void ObtenerJuego();
void Instrucciones();
void llenarMatriz(int CAMPO[FILAS+2][COLS+2]);
void impMatriz(int CAMPO[FILAS+2][COLS+2], int verif[FILAS+2][COLS+2]);
void eBomba(int CAMPO[FILAS+2][COLS+2], int verif[FILAS+2][COLS+2], int F, int C);
int verifGanar(int CAMPO[FILAS+2][COLS+2], int verif[FILAS+2][COLS+2]);
int esColindante(int JF, int JC, int CF, int CC);

int main(){
	char opcion = -1;
	
	system("color f4");
	srand(time(NULL));
	
	while(opcion != '3'){
		system("cls");			/* pantalla de inicio*/
		printf("Bienvenido al juego del buscaminas.\n\n1. Jugar\n2. Reglas del juego\n3. Salir\n\nPresiona tu opción en el teclado. ");
		opcion = getch();
		
		switch(opcion){
			case '1':
				ObtenerNivel();
				Juego();
				break;
			
			case '2':
				Instrucciones();
				break;
			
			default:
				;
		}
	}
	
	return 0;
}

// ***************** Declaración de funciones *****************
void Juego(){
	int mina = FALSE, tf = FALSE;
	int CAMPO[FILAS+2][COLS+2];      // original
	int VERIF[FILAS+2][COLS+2];      // auxiliar
	char Jugada = 32;
	
	for(int i = 0;i < FILAS+2;i++){       // todas las casillas están no descubiertas
		for(int j = 0;j < COLS+2;j++)
			VERIF[i][j] = NDESC;
	}
	
	mostrar = FALSE;		// inicializar cursor
	Jf = FILAS / 2; Jc = COLS / 2;
	
	while(!tf && Jugada != SALIR){                       // primera jugada
		impMatriz(CAMPO,VERIF);
		printf("\n\nRealiza una jugada. ");
		Jugada = getch();
		
		switch(Jugada){
			case 'w': case 'W':
				mostrar = FALSE;
				if(Jf > 1)
					Jf--;
				break;
			
			case 's': case 'S':
				mostrar = FALSE;
				if(Jf < FILAS)
					Jf++;
				break;
			
			case 'a': case 'A':
				mostrar = FALSE;
				if(Jc > 1)
					Jc--;
				break;
			
			case 'd': case 'D':
				mostrar = FALSE;
				if(Jc < COLS)
					Jc++;
				break;
			
			case ABRIR:
				mostrar = TRUE;
				if(VERIF[Jf][Jc] == NDESC)
					tf = TRUE;
				break;
			
			case 'p': case 'P':
				mostrar = TRUE;
				if(VERIF[Jf][Jc] == NDESC)
					VERIF[Jf][Jc] = BANDERA;
				else if(VERIF[Jf][Jc] == BANDERA)
					VERIF[Jf][Jc] = NDESC;
				break;
			
			case 'o': case 'O':
				if(!mostrar)
					mostrar = TRUE;
				else
					mostrar = FALSE;
				break;
			
			case SALIR:
				mina = TRUE;
				Jf = 0;
				Jc = 0;
				break;
			
			default:
				printf("\a");
		}
	}
	llenarMatriz(CAMPO);
	
	if(!mina){
		if(CAMPO[Jf][Jc] >= 1)
			VERIF[Jf][Jc] = DESC;
		else
			eBomba(CAMPO,VERIF,Jf,Jc);
	}
	
	while(!mina && !verifGanar(CAMPO,VERIF)){          // comienza juego
		impMatriz(CAMPO,VERIF);
		printf("\n\nRealiza una jugada. ");
		Jugada = getch();
		
		switch(Jugada){
			case 'w': case 'W':
				mostrar = FALSE;
				if(Jf > 1)
					Jf--;
				break;
			
			case 's': case 'S':
				mostrar = FALSE;
				if(Jf < FILAS)
					Jf++;
				break;
			
			case 'a': case 'A':
				mostrar = FALSE;
				if(Jc > 1)
					Jc--;
				break;
			
			case 'd': case 'D':
				mostrar = FALSE;
				if(Jc < COLS)
					Jc++;
				break;
			
			case ABRIR:
				mostrar = TRUE;
				if(VERIF[Jf][Jc] == NDESC){
					if(CAMPO[Jf][Jc] == MINA)
						mina = TRUE;
					else if(CAMPO[Jf][Jc] >= 1)
						VERIF[Jf][Jc] = DESC;
					else
						eBomba(CAMPO,VERIF,Jf,Jc);
				}
				break;
			
			case 'p': case 'P':
				mostrar = TRUE;
				if(VERIF[Jf][Jc] == NDESC)
					VERIF[Jf][Jc] = BANDERA;
				else if(VERIF[Jf][Jc] == BANDERA)
					VERIF[Jf][Jc] = NDESC;
				break;
			
			case 'o': case 'O':
				if(!mostrar)
					mostrar = TRUE;
				else
					mostrar = FALSE;
				break;
			
			case SALIR:
				mina = TRUE;
				Jf = 0;
				Jc = 0;
				break;
			
			default:
				printf("\a");
		}
	}
	
	if(mina){          // partida perdida
		for(int i = 1;i <= FILAS;i++){
			for(int j = 1;j <= COLS;j++){
				if(CAMPO[i][j] == MINA && VERIF[i][j] == NDESC)
					VERIF[i][j] = DESC;
				
				if(CAMPO[i][j] != MINA && VERIF[i][j] == BANDERA)
					VERIF[i][j] = FALLO;
			}
		}
		
		impMatriz(CAMPO,VERIF);
		printf("\n\nHas perdido !!\a\n");
	}
	else{           // partida ganada
		for(int i = 1;i <= FILAS;i++){
			for(int j = 1;j <= COLS;j++){
				if(CAMPO[i][j] == MINA)
					VERIF[i][j] = BANDERA;
			}
		}
		
		impMatriz(CAMPO,VERIF);
		printf("\n\nHas ganado !!\a\n");
	}
	system("pause");
}

void ObtenerNivel(){
	do {         /* escoger dificultad */
		system("cls");
		printf("Bienvenido al juego del buscaminas.\n\nElige un nivel de dificultad.\n");
		printf("1. Principiante\n2. Intermedio\n3. Experto\n4. Juego personalizado\n\nPresiona tu opción en el teclado. ");
		nivel = getch();
	} while(nivel != '1' && nivel != '2' && nivel != '3' && nivel != '4');
	
	switch(nivel){
		case '1':        /* nivel principiante */
			FILAS = 9;
			COLS = 9;
			nMinas = 10;
			break;
		
		case '2':        /* nivel intermedio */
			FILAS = 16;
			COLS = 16;
			nMinas = 40;
			break;
		
		case '3':        /* nivel experto */
			FILAS = 16;
			COLS = 30;
			nMinas = 99;
			break;
		
		case '4':        /* juego personalizado */
			printf("\n");
			ObtenerJuego();/* escoger dificultad */
			break;
		
		default:
			;
	}
}

void ObtenerJuego(){
	FILAS = 0; COLS = 0; nMinas = 0;
	
	printf("\nNumero de filas: ");
	scanf("%d",&FILAS);
	if(FILAS <= 1)
		FILAS = 2;
	else if(FILAS >= 100)
		FILAS = 99;
	
	printf("Numero de columnas: ");
	scanf("%d",&COLS);
	if(COLS <= 1)
		COLS = 2;
	else if(COLS >= 100)
		COLS = 99;
	
	printf("Numero de minas: ");
	scanf("%d",&nMinas);
	if(nMinas <= 0)
		nMinas = 1;
	else if(nMinas >= FILAS * COLS)
		nMinas = FILAS * COLS - 1;
}

void Instrucciones(){
	system("cls");
	
	printf("Reglas e instrucciones del juego.\n\n1. El juego consiste en despejar un campo lleno de minas sin detonar ninguna de éstas.");
	Sleep(DELAY);
	printf("\n\n2. Algunas casillas tienen un número, el cual indica la cantidad de minas que hay en las casillas vecinas.\n   De esta forma, si una casilla tiene el número 3, significa que de las ocho casillas que hay alrededor, hay 3 con mina y 5 sin mina.");
	Sleep(DELAY);
	printf("\n\n3. Si se descubre una casilla sin número, indica que ninguna de las casillas vecinas tiene mina y éstas se descubren automáticamente.");
	Sleep(DELAY);
	printf("\n\n4. Se pierde la partida al descubrir una casilla que contiene una mina.");
	Sleep(DELAY);
	printf("\n\n5. Utiliza las teclas W,A,S,D para mover el cursor a través de las casillas del campo.");
	Sleep(DELAY);
	printf("\n\n6. Para descubrir una casilla, debes localizarte sobre ésta y presionar la tecla ENTER.");
	Sleep(DELAY);
	printf("\n\n7. Puedes poner una bandera en las casillas donde crees que pueda haber una mina.\n   Para ello, debes localizarte sobre una casilla y presionar la tecla P.");
	Sleep(DELAY);
	printf("\n\n8. Puedes cancelar la partida en cualquier momento presionando la tecla ESC.");
	Sleep(DELAY);
	printf("\n\n9. Puedes mostrar u ocultar el cursor en cualquier momento presionando la tecla O.");
	Sleep(DELAY);
	
	printf("\n\n");
	system("pause");
}

void llenarMatriz(int CAMPO[FILAS+2][COLS+2]){
	int filaB, colB, num, tf = FALSE;
	
	for(int i = 0;i < FILAS+2;i++){         /* llenar de casillas en blanco */
		for(int j = 0;j < COLS+2;j++){
			if(i >= 1 && i <= FILAS && j >= 1 && j <= COLS)
				CAMPO[i][j] = BLANCO;
			else
				CAMPO[i][j] = -20;
		}
	}

	for(int i = 0;i < nMinas;i++){
		do {
			num = rand()%(FILAS * COLS);
			filaB = num / COLS + 1;
			colB = num % COLS + 1;
			
			if(nMinas <= FILAS * COLS - 9)
				tf = esColindante(Jf,Jc,filaB,colB);
		} while(CAMPO[filaB][colB] == MINA || (filaB == Jf && colB == Jc) || tf);     /* bombas no se repiten, se excluye la primera jugada */
		
		
	CAMPO[filaB][colB] = MINA;         /* colocar bombas en el campo */
	}
	
	for(int i = 1;i <= FILAS;i++){       /* contar bombas alrededor de las casillas */
		for(int j = 1;j <= COLS;j++){
			if(CAMPO[i][j] == MINA){
				for(int n = i - 1;n <= i + 1;n++){
					for(int m = j - 1;m <= j + 1;m++){
						if(CAMPO[n][m] != MINA)
							CAMPO[n][m]++;
					}
				}
			}
		}
	}
}

void impMatriz(int CAMPO[FILAS+2][COLS+2], int verif[FILAS+2][COLS+2]){
	system("cls");
	printf("Buscaminas\n\n[x]   ");
	
	for(int i = 1;i <= COLS;i++)
		printf("%-3d",i);
	printf("\n");
	for(int i = 1;i <= COLS*3+4;i++)
		printf("=");
	printf("=\n");
	
	for(int i = 1;i <= FILAS;i++){
		printf("[%d]  ",i);
		if(i < 10)
			printf(" ");
		
		for(int j = 1;j <= COLS;j++){
			if(i == Jf && j == Jc && !mostrar)
				printf(".  ");
			else{
				switch(verif[i][j]){
					case DESC:
						if(CAMPO[i][j] == BLANCO)
							printf("   ");
						else if(CAMPO[i][j] != MINA)
							printf("%d  ",CAMPO[i][j]);
						else
							printf("*  ");
						break;
					
					case NDESC:
						printf("o  ");
						break;
					
					case BANDERA:
						printf("P  ");
						break;
					
					case FALLO:
						printf("X  ");
						break;
					
					default:
						;
				}
			}
		}
		printf("\n");
	}
}

void eBomba(int CAMPO[FILAS+2][COLS+2], int verif[FILAS+2][COLS+2], int F, int C){
	verif[F][C] = DESC;
	
	for(int n = F - 1;n <= F + 1;n++){
		for(int m = C - 1;m <= C + 1;m++){
			if(CAMPO[n][m] == BLANCO && verif[n][m] == NDESC)
				eBomba(CAMPO,verif,n,m);
			
			if(verif[n][m] != BANDERA)
				verif[n][m] = DESC;
		}
	}
}

int verifGanar(int CAMPO[FILAS+2][COLS+2], int verif[FILAS+2][COLS+2]){
	int tf = TRUE;
	
	for(int i = 1;i <= FILAS && tf;i++){
		for(int j = 1;j <= COLS && tf;j++){
			if(CAMPO[i][j] != MINA && verif[i][j] != DESC)
				tf = FALSE;
		}
	}
	
	return tf;
}

int esColindante(int JF, int JC, int CF, int CC){
	int tf = FALSE;
	
	for(int i = JF - 1;i <= JF + 1 && !tf;i++){
		for(int j = JC - 1;j <= JC + 1 && !tf;j++){
			if(CF == i && CC == j)
				tf = TRUE;
		}
	}
	
	return tf;
}
