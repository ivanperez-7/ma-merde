/**************************
Nombre: ulex.c
Objetivo: Analizador lexico
Autor: Iván Pérez Maldonado
Fecha: 12/03/19
***************************/

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// ****************** Declaración de funciones ******************
int esalfanum(char c);
int esletra(char c);
int esdigito(char c);
int esblanco(char c);

int main(){
   int caso, i, par;
   char c, ulex[200];

   c = getchar();
   while(c != EOF){
      i = 0;
      caso = 0;

      if(esletra(c))
         caso = 1;
      else if(esdigito(c))
         caso = 2;
      else if(esblanco(c))
         caso = 3;
      else if(c == '=')
         caso = 4;
      else if(c == '/')
         caso = 5;
      else if(c == '#')
         caso = 6;

      switch(caso){
         case 1: // identificador
            ulex[i] = c;
            i++;
            c = getchar();
            while(esalfanum(c) || c == '_'){
               ulex[i] = c;
               i++;
               c = getchar();
            }
            ulex[i] = 0;
            printf("Ulex = (%s) - Identificador\n",ulex);
            break;

         case 2:     // constantes
            ulex[i] = c;
            i++;
            c = getchar();
            while(esdigito(c)){
               ulex[i] = c;
               i++;
               c = getchar();
            }
            if(c == '.'){
               do {
               ulex[i] = c;
               i++;
               c = getchar();
               } while(esdigito(c));
               ulex[i] = 0;
               printf("Ulex = (%s) - Constante Real\n",ulex);
            }
            else{
               ulex[i] = 0;
               printf("Ulex = (%s) - Constante Entera\n",ulex);
            }

            break;

         case 3:
            while(esblanco(c))
               c = getchar();
            break;

         case 4:
            ulex[i] = c;
            i++;
            c = getchar();
            while(esblanco(c) != TRUE && c != 32){
               ulex[i] = c;
               i++;
               c = getchar();
            }
            ulex[i] = 0;
            if(ulex[0] == '=' && ulex[1] == '=' && ulex[2] == 0)
               printf("Ulex = (%s) - Operador logico\n",ulex);
            else if(ulex[0] == '=' && ulex[1] == 0)
               printf("Ulex = (%s) - Operador de asignacion\n",ulex);
            break;

         case 5:
            c = getchar();
            if(c == '/'){
               while(c != '\n')
                  c = getchar();
            }
            else if(c == '*'){
               par = FALSE;
               while(par == FALSE){
                  c  = getchar();
                  if(c == '*'){
                     c = getchar();
                     if(c == '/')
                        par = TRUE;
                  }
               }
               c = getchar();
            }
            break;

         case 6:
            ulex[i] = c;
            i++;
            c = getchar();
            while(esblanco(c) != TRUE && c != 32){
               ulex[i] = c;
               i++;
               c = getchar();
            }
            ulex[i] = 0;
            printf("Ulex = (%s) - Directiva del preprocesador\n",ulex);
            break;

         default:
            c = getchar();
      }
   }

	return 0;
}

// incluir constantes reales

// ****************** Descripción de funciones ******************
int esalfanum(char c){
   int tf = FALSE;

   if((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
      tf = TRUE;

   return tf;
}

int esletra(char c){
   int tf = FALSE;

   if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
      tf = TRUE;

   return tf;
}

int esdigito(char c){
   int tf = FALSE;

   if(c >= 48 && c <= 57)
      tf = TRUE;

   return tf;
}

int esblanco(char c){
   int tf = FALSE;

   if(c == '\b' || c == '\n' || c == '\t' || c == 10)
      tf = TRUE;

   return tf;
}
