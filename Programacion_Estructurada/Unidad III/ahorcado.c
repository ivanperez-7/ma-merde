/********************************
Nombre: ahorcado.c
Objetivo: Juego de 'el ahorcado'
Autor: Ivan Perez Maldonado
Fecha: 21/03/19
*********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define nOrac 8

// ************************* Declaración de funciones *************************
int leecadena(char cadena[]);
int leeletras(char cadena[]);
int letrasdif(char cadena[]);
int arrsearch(char cadena[], char c, int MAX);
int esletra(char c);
int esmayus(char c);
int esminus(char c);

int main(){
   int i, o, k = 0, lcad, numint, aciertos = 0, tf = -1;
   char oraciones[nOrac][100], respuesta[52], c, c2;

   /* Asignación de oraciones. */
   strcpy(oraciones[0],"Hay muchas letras aqui");
   strcpy(oraciones[1],"Esta es una oracion");
   strcpy(oraciones[2],"Juego del ahorcado");
   strcpy(oraciones[3],"La flor del sol");
   strcpy(oraciones[4],"Hola mundo");
   strcpy(oraciones[5],"Nunca adivinaras esta oracion");
   strcpy(oraciones[6],"Luz de luna");
   strcpy(oraciones[7],"El veloz murcielago hindu comia feliz cardillo y kiwi");

   srand(time(NULL));
   o = 7;    /* seleccionar oración aleatoria */
   printf("===================\nJuego del ahorcado\n===================\n");
   printf("La oracion tiene %d letras, con %d letras diferentes.\n",leeletras(oraciones[o]),letrasdif(oraciones[o]));

   lcad = leecadena(oraciones[o]);
   numint = letrasdif(oraciones[o]) + 5;
   for(i = 0;i < 52;i++)
      respuesta[i] = 32;

   while(numint != 0 && aciertos != letrasdif(oraciones[o])){
      if(tf == 1)
         printf("\nCorrecto!\n");
      else if(tf == 0)
         printf("\nIncorrecto!\n");

      printf("\nLlevas %d letras diferentes encontradas, te quedan %d intentos.\n%c",aciertos,numint,34);
      for(i = 0;i < lcad;i++){
         if( arrsearch(respuesta,oraciones[o][i],52) || esletra(oraciones[o][i]) != 1)
            printf("%c",oraciones[o][i]);
         else
            printf("_");
      }

      printf("%c\nIngresa una letra: ",34);
      scanf(" %c",&c);
      if( esminus(c) )
         c2 = c - 32;
      else if( esmayus(c) )
         c2 = c + 32;

      if( arrsearch(oraciones[o],c,lcad) && arrsearch(respuesta,c,52) == 0 && esletra(c)){
         respuesta[k] = c;
         respuesta[k+1] = c2;
         k += 2;
         aciertos++;
         tf = 1;
      }
      else if( arrsearch(oraciones[o],c2,lcad) && arrsearch(respuesta,c2,52) == 0 && esletra(c2)){
         respuesta[k] = c;
         respuesta[k+1] = c2;
         k += 2;
         aciertos++;
         tf = 1;
      }
      else
         tf = 0;

      numint--;
   }

   if(aciertos == letrasdif(oraciones[o]))
      printf("\nHas ganado!!\nLa oracion es: %s\n",oraciones[o]);
   else
      printf("\nTe quedaste sin intentos!!\n");

	return 0;
}

// ************************* Descripción de funciones *************************
int leecadena(char cadena[]){
   int i = 0, caracteres = 0;

   for(i = 0;cadena[i] != 0 && cadena[i] != EOF;i++)
      caracteres++;

   return (caracteres);
}

int leeletras(char cadena[]){
   int i = 0, caracteres = 0;

   for(i = 0;cadena[i] != 0 && cadena[i] != EOF;i++)
      if(esletra(cadena[i])) caracteres++;

   return (caracteres);
}

int letrasdif(char cadena[]){
   int i, k = 0, cont = 0;
   char letras[52];

   for(i = 0;i < 52;i++)
      letras[i] = -1;

   for(i = 0;cadena[i] != 0 && cadena[i] != EOF;i++){
      if( arrsearch(letras,cadena[i],52) == 0 && esletra(cadena[i]) ){
         if( esminus(cadena[i]) ) {
            letras[k] = cadena[i];
            letras[k+1] = cadena[i] - 32;
         }
         else if( esmayus(cadena[i]) ){
            letras[k] = cadena[i];
            letras[k+1] = cadena[i] + 32;
         }
         k += 2;
         cont++;
      }
   }

   return cont;
}

int arrsearch(char cadena[], char c, int MAX){
   int i = 0, tf = 1;

   for(i = 0;i < MAX && cadena[i] != c;i++) ;
   if(i == MAX)
      tf = 0;  // no encontrado

   return tf;
}

int esletra(char c){
   int tf = 0;

   if(esmayus(c) || esminus(c))
      tf = 1;
   return tf;
}

int esmayus(char c){
   int tf = 0;

   if(c >= 65 && c <= 90)
      tf = 1;
   return tf;
}

int esminus(char c){
   int tf = 0;

   if(c >= 97 && c <= 122)
      tf = 1;
   return tf;
}
