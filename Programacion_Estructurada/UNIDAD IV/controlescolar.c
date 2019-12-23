/*********************************************
Nombre: controlescolar.c
Objetivo: Registrar informacion sobre alumnos
Autor: Iván Pérez Maldonado
Fecha: 4/4/19
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AMAX 100
#define NCAL 200
#define MMAX 20

int main(){
   struct alumnos{
      char matricula[9];
      char nombre[100];
      int edad;
      int semestre;
   } alumnos[AMAX];

   struct materias {
      char clvmat[15];
      char nommat[50];
      int ncred;
   }
	materias[MMAX] = {
		{"CCaint01","Algebra intermedia",8}, {"CCalg01","Algoritmia",7}, {"CCavan02","Algebra Avanzada",8},
		{"CCas01","Algebra superior",5}, {"CCgean01","Geometria Analitica",8}, {"CCcalc02","Calculo diferencial",8},
		{"CCprog02","Programacion estructurada",7}, {"CCdis02","Matematicas discretas",7}, {"CCalin03","Algebra lineal",8},
		{"CCcalc03","Calculo integral",8}, {"CCestr03","Estructuras de datos",8}, {"CCtcomp03","Teoria de la computacion",8},
		{"CCcalc04","Calculo vectorial",8}, {"CCalg04","Analisis de algoritmos",6}, {"CCprog04","Prog. orientada a objetos",8},
		{"CCalg04","Analisis de algoritmos",6}, {"CCprob05","Probabilidad",8}, {"CCedif05","Ecuaciones diferenciales",8},
		{"CCmdat05","Modelado de datos",7}, {"CCos06","Sistemas operativos",7}
	};

	struct calificaciones {
		char mat[20][9];
		char clvmat[20][8];
		int calif[20];
		int periodo[20];
	} calific[AMAX];

   char mattemp[9], clavem[8], *ptr;
   int pos, i, sumapr = 0, sumacr = 0;
   double pp;
   struct materias *p;

	for(i = 0; i < 100; i++)
		alumnos[i].semestre = 0;

   gets(mattemp);
   while( strcmp(mattemp,"Fin") != 0){
      ptr = &mattemp[0] + 6; pos = atoi(ptr);
      strcpy(alumnos[pos].matricula,mattemp);
	   strcpy(calific[pos].mat,alumnos[pos].matricula);

      gets(alumnos[pos].nombre);

      scanf("%d",&alumnos[pos].edad);

      scanf("%d",&alumnos[pos].semestre); getchar();
      printf("\nMatricula: %-2s%s\nNombre: %-5s%s\nEdad: %-7s%d\nSemestre: %-3s%d\n","",alumnos[pos].matricula,"",alumnos[pos].nombre,"",alumnos[pos].edad,"",alumnos[pos].semestre);

      printf("\nClave%-8sMateria%-25sCalificacion\n","","");
      printf("==========================================================\n");
      gets(clavem);

      sumapr = 0; sumacr = 0;
      while(strcmp(clavem,"Fin") != 0){
         p = &materias[0];
         for(i = 0; i < MMAX; i++){
            if( strcmp(p->clvmat,clavem) == 0 )
               break;
            else
               p++;
         }

         if(i != MMAX) {
            scanf("%d",&calific[pos].calif);
            sumapr += calific[pos].calif * p->ncred;
            sumacr += p->ncred;

            printf("%-12s %-32s%d\n",p->clvmat,p->nommat,calific[pos].calif);
         }
         gets(clavem);
      }
      printf("\nPromedio ponderado = %.2lf\n\n",(float)sumapr / (float)sumacr);

      gets(mattemp);
   }

	return 0;
}
