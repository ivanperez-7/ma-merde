/*********** Buscaminas para Windows ***********/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define True 1
#define False 0

#define DESC 1
#define NODESC 0
#define BANDERA 2
#define FALLO 3

#define VACIO -20
#define BLANCO 0
#define MINA -1

#define ABRIR 13
#define SALIR 27

int FILAS, COLS, nMinas, Jf, Jc;
int esconder, mina, contminas;

/****************** Declaración de funciones ******************/
void Juego();
void HacerJugada(int CAMPO[FILAS+2][COLS+2], int VERIF[FILAS+2][COLS+2], char Jugada);
void ObtenerNivel();
void Instrucciones();
void llenarCampo(int CAMPO[FILAS+2][COLS+2]);
void impCampo(int CAMPO[FILAS+2][COLS+2], int VERIF[FILAS+2][COLS+2]);
void eBomba(int CAMPO[FILAS+2][COLS+2], int VERIF[FILAS+2][COLS+2], int F, int C);
void Centrar();
int verifGanar(int CAMPO[FILAS+2][COLS+2], int VERIF[FILAS+2][COLS+2]);
int esVecina(int filaB, int colB);
int contBanderas(int VERIF[FILAS+2][COLS+2]);
int totalBand(int VERIF[FILAS+2][COLS+2]);

int main(){
    char opcion;
    
    srand(time(NULL));
    system("color 0F");
    system("title Buscaminas");
    
    do {                    /* pantalla de inicio*/
        system("mode con: cols=110 lines=27");
        system("cls");
        printf("Bienvenido al juego del buscaminas.\n\n1. Jugar\n2. Reglas del juego\n3. Salir\n\nPresiona tu opción en el teclado. ");
        do { opcion = getch(); } while(opcion != '1' && opcion != '2' && opcion != '3');
        
        switch(opcion){
            case '1':
                ObtenerNivel();
                Juego();
                break;
            
            case '2':
                Instrucciones();
                break;
            
            case '3':
                printf("\n\n¿Desea salir del juego? (Y/N) ");
                do { opcion = getch(); } while (opcion != 'Y' && opcion != 'y' && opcion != 'N' && opcion != 'n');
                break;
            
            default:
                opcion = 0;
        }
    } while(opcion != 'Y' && opcion != 'y');
    
    system("cls");
    system("color 07");
    
    return 0;
}

/****************** Descripción de funciones ******************/
void Juego(){
    int CAMPO[FILAS+2][COLS+2];      // original
    int VERIF[FILAS+2][COLS+2];      // auxiliar
    char Jugada = 0;
    
    mina = False;                    // inicializar partida
    esconder = False;       
    contminas = nMinas;
    Jf = FILAS / 2 + 1; 
    Jc = COLS / 2 + 1;
    
    for(int i = 0;i < FILAS+2;i++){       // todas las casillas están no descubiertas y vacías
        for(int j = 0;j < COLS+2;j++){
            CAMPO[i][j] = VACIO;
            VERIF[i][j] = NODESC;
        }
    }
    
    // ***** comienza juego *****
    while( !(Jugada == ABRIR && VERIF[Jf][Jc] != BANDERA) && !mina ){       // primera jugada
        impCampo(CAMPO,VERIF);
        printf("\nMINAS : %d\n\nRealiza una jugada. ",contminas);
        
        Jugada = getch();
        HacerJugada(CAMPO,VERIF,Jugada);
    }
    llenarCampo(CAMPO);
    
    if(!mina)
        HacerJugada(CAMPO,VERIF,ABRIR);
    
    while( !mina && !verifGanar(CAMPO,VERIF) ){         // resto del juego
        impCampo(CAMPO,VERIF);
        printf("\nMINAS : %d\n\nRealiza una jugada. ",contminas);
        
        Jugada = getch();
        HacerJugada(CAMPO,VERIF,Jugada);
    }
    
    if(mina){          // partida perdida
        for(int i = 1;i <= FILAS;i++){
            for(int j = 1;j <= COLS;j++){
                if(CAMPO[i][j] == MINA && VERIF[i][j] == NODESC)
                    VERIF[i][j] = DESC;
                
                if(CAMPO[i][j] != MINA && VERIF[i][j] == BANDERA)
                    VERIF[i][j] = FALLO;
            }
        }
        
        impCampo(CAMPO,VERIF);
        printf("\nHas perdido !!\a\n");
    }
    else{           // partida ganada
        for(int i = 1;i <= FILAS;i++){
            for(int j = 1;j <= COLS;j++){
                if(CAMPO[i][j] == MINA)
                    VERIF[i][j] = BANDERA;
            }
        }
        
        impCampo(CAMPO,VERIF);
        printf("\nHas ganado !!\a\n");
    }
    
    printf("Presione la tecla ESC para continuar... ");
    do {  Jugada = getch();  } while(Jugada != SALIR);
}

void HacerJugada(int CAMPO[FILAS+2][COLS+2], int VERIF[FILAS+2][COLS+2], char Jugada){
    switch(Jugada){
        case 'w': case 'W':
            esconder = False;
            if(Jf > 1)
                Jf--;
            break;
        
        case 's': case 'S':
            esconder = False;
            if(Jf < FILAS)
                Jf++;
            break;
        
        case 'a': case 'A':
            esconder = False;
            if(Jc > 1)
                Jc--;
            break;
        
        case 'd': case 'D':
            esconder = False;
            if(Jc < COLS)
                Jc++;
            break;
        
        case ABRIR:
            if(VERIF[Jf][Jc] == NODESC && CAMPO[Jf][Jc] != VACIO){
                esconder = True;
                
                if(CAMPO[Jf][Jc] == MINA)
                    mina = True;
                else if(CAMPO[Jf][Jc] >= 1)
                    VERIF[Jf][Jc] = DESC;
                else
                    eBomba(CAMPO,VERIF,Jf,Jc);
            }
            else if(VERIF[Jf][Jc] == DESC && contBanderas(VERIF) == CAMPO[Jf][Jc] && CAMPO[Jf][Jc] != BLANCO){
                esconder = True;
                
                for(int i = Jf - 1;i <= Jf + 1;i++){
                    for(int j = Jc - 1;j <= Jc + 1;j++){
                        if(VERIF[i][j] == NODESC){
                            if(CAMPO[i][j] == MINA)
                                mina = True;
                            else if(CAMPO[i][j] == BLANCO)
                                eBomba(CAMPO,VERIF,i,j);
                            else
                                VERIF[i][j] = DESC;
                        }
                    }
                }
            }
            break;
        
        case 'p': case 'P':
            if(VERIF[Jf][Jc] == NODESC){
                VERIF[Jf][Jc] = BANDERA;
                contminas--;
                esconder = True;
            }
            else if(VERIF[Jf][Jc] == BANDERA){
                VERIF[Jf][Jc] = NODESC;
                contminas++;
                esconder = True;
            }
            break;
        
        case 'o': case 'O':
            if(!esconder)
                esconder = True;
            else
                esconder = False;
            break;
        
        case 'j': case 'J':
            printf("\nSaltar a la casilla [i,j]: ");
            scanf("%d %d",&Jf,&Jc);
            esconder = False;
            
            if(Jf < 1)
                Jf = 1;
            else if(Jf > FILAS)
                Jf = FILAS;
            if(Jc < 1)
                Jc = 1;
            else if(Jc > COLS)
                Jc = COLS;
            
            break;
        
        case SALIR:
            mina = True;
            esconder = True;
            break;
        
        default:
            ;
    }
}

void ObtenerNivel(){                /* escoger dificultad */
    char nivel;
    
    system("cls");
    printf("Bienvenido al juego del buscaminas.\n\nElige un nivel de dificultad.\n1. Principiante\n2. Intermedio\n3. Experto\n4. Juego personalizado\n\nPresiona tu opción en el teclado. ");
    do { nivel = getch(); } while(nivel != '1' && nivel != '2' && nivel != '3' && nivel != '4');
    
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
            printf("\n\nFilas: ");
            scanf("%d",&FILAS);
            if(FILAS < 1)
                FILAS = 1;
            else if(FILAS >= 100)
                FILAS = 99;
            
            printf("Columnas: ");
            scanf("%d",&COLS);
            if(COLS < 1)
                COLS = 1;
            else if(COLS >= 100)
                COLS = 99;
            
            printf("Minas: ");
            scanf("%d",&nMinas);
            if(nMinas < 0)
                nMinas = 0;
            else if(nMinas >= FILAS * COLS)
                nMinas = FILAS * COLS - 1;
            
            break;
        
        default:
            ;
    }
}

void Instrucciones(){   
    char inst[][250] = { 
        "El juego consiste en despejar un campo lleno de minas sin detonar ninguna de éstas." ,
        "Algunas casillas tienen un número, el cual indica la cantidad de minas que hay en las casillas vecinas.\n   Así, si una casilla tiene el número 3, significa que de las ocho casillas que hay alrededor, hay 3 con mina y 5 sin mina." ,
        "Si se descubre una casilla sin número, indica que ninguna de las casillas vecinas tiene mina y éstas se descubren automáticamente." ,
        "Se pierde la partida al descubrir una casilla que contiene una mina." ,
        "Utiliza las teclas W,A,S,D para mover el cursor a través de las casillas del campo." ,
        "Para descubrir una casilla, debes localizarte sobre ésta y presionar la tecla ENTER." ,
        "Puedes poner una bandera en las casillas donde crees que pueda haber una mina.\n   Para ello, debes localizarte sobre una casilla y presionar la tecla P." ,
        "Puedes brincar a una casilla pulsando la tecla J y luego ingresando las coordenadas de ésta." ,
        "Puedes cancelar la partida en cualquier momento presionando la tecla ESC." ,
        "Puedes esconder u ocultar el cursor en cualquier momento presionando la tecla O." ,
        "Si marcas con una bandera una casilla sin mina, al perder la partida verás una X en esta casilla."
    };
    
    system("cls");
    system("mode con: cols=135 lines=30");
    printf("Reglas e instrucciones.");
    
    for(unsigned int i = 0;i < sizeof(inst)/250;i++){
        printf("\n\n%d. %s ",i+1,inst[i]);
        Sleep(300);
    }

    printf("\n\n\n");
    system("pause");
}

void llenarCampo(int CAMPO[FILAS+2][COLS+2]){
    int num, filaB, colB, tf = False;
    
    for(int i = 1;i <= FILAS;i++){         /* llenar de casillas en blanco */
        for(int j = 1;j <= COLS;j++)
            CAMPO[i][j] = BLANCO;
    }

    for(int i = 0;i < nMinas;i++){
        do {
            num = rand()%(FILAS * COLS);
            filaB = num / COLS + 1;
            colB = num % COLS + 1;
            
            if(nMinas <= FILAS * COLS - 9)
                tf = esVecina(filaB,colB);
        } while(CAMPO[filaB][colB] == MINA || (filaB == Jf && colB == Jc) || tf);     /* bombas no se repiten, se excluye la primera jugada con colindantes*/
        
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

void impCampo(int CAMPO[FILAS+2][COLS+2], int VERIF[FILAS+2][COLS+2]){
    int color;
    
    system("cls");
    printf("Buscaminas\n\n");
    
    Centrar();
    printf("[x]   ");
    
    for(int i = 1;i <= COLS;i++)
        printf("%-3d",i);
    printf("\n");
    
    Centrar();
    for(int i = 1;i <= COLS*3+5;i++)
        printf("=");
    printf("\n");
    
    for(int i = 1;i <= FILAS;i++){
        Centrar();
        printf("[%d]  ",i);
        if(i < 10)
            printf(" ");
        
        for(int j = 1;j <= COLS;j++){
            if(i == Jf && j == Jc && !esconder)
                printf(".  ");
            else{
                switch(VERIF[i][j]){
                    case DESC:
                        if(CAMPO[i][j] == BLANCO)
                            printf("   ");
                        else if(CAMPO[i][j] != MINA){
                            switch(CAMPO[i][j]){
                                case 1:
                                    color = 9;
                                    break;
                                    
                                case 2:
                                    color = 10;
                                    break;
                                    
                                case 3:
                                    color = 12;
                                    break;
                                    
                                case 4:
                                    color = 13;
                                    break;
                                    
                                case 5:
                                    color = 11;
                                    break;
                                    
                                case 6:
                                    color = 1;
                                    break;
                                    
                                case 7:
                                    color = 6;
                                    break;
                                    
                                case 8:
                                    color = 15;
                                    break;
                                    
                                default:
                                    color = 15;
                            }
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
                            
                            printf("%d  ",CAMPO[i][j]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        }
                        else
                            printf("*  ");
                        break;
                    
                    case NODESC:
                        printf("-  ");
                        break;
                    
                    case BANDERA:
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                        printf("o  ");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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

void eBomba(int CAMPO[FILAS+2][COLS+2], int VERIF[FILAS+2][COLS+2], int F, int C){
    VERIF[F][C] = DESC;
    
    for(int i = F - 1;i <= F + 1;i++){
        for(int j = C - 1;j <= C + 1;j++){
            if(CAMPO[i][j] == BLANCO && VERIF[i][j] == NODESC)
                eBomba(CAMPO,VERIF,i,j);
            else if(VERIF[i][j] != BANDERA)
                VERIF[i][j] = DESC;
        }
    }
}

void Centrar(){
    for(int i = 0;i < 54 - (COLS*3+5)/2;i++)
        printf(" ");
}

int verifGanar(int CAMPO[FILAS+2][COLS+2], int VERIF[FILAS+2][COLS+2]){
    int tf = True;
    
    for(int i = 1;i <= FILAS && tf;i++){
        for(int j = 1;j <= COLS && tf;j++){
            if(CAMPO[i][j] != MINA && VERIF[i][j] != DESC)
                tf = False;
        }
    }
    
    return tf;
}

int esVecina(int filaB, int colB){
    int tf = False;
    
    for(int i = Jf - 1;i <= Jf + 1 && !tf;i++){
        for(int j = Jc - 1;j <= Jc + 1 && !tf;j++){
            if(filaB == i && colB == j)
                tf = True;
        }
    }
    
    return tf;
}

int contBanderas(int VERIF[FILAS+2][COLS+2]){
    int band = 0;
    
    for(int i = Jf - 1;i <= Jf + 1;i++){
        for(int j = Jc - 1;j <= Jc + 1;j++){
            if(VERIF[i][j] == BANDERA)
                band++;
        }
    }
    
    return band;
}
