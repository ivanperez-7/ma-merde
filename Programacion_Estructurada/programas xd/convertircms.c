/*
Nombre: convertircms.c
Objetivo: Convertir una medida dada en centímetros a otras unidades de medida
Autor: Iván Pérez Maldonado
Fecha: 29/01/19
*/

#include <stdio.h>

int main(){
  double cms,yrd,in,ft,mts,miles;

  printf("Introduzca la medida en centimetros: ");
  scanf("%lf",&cms);

  in = cms/2.54;
  ft = cms/(2.54*12);
  yrd = cms/(2.54*36);
  mts = cms/100;
  miles = cms/(1.609*100000);

  printf("\nPulgadas = %.2lf\nPies = %.2lf\nYardas = %.2lf\nMillas = %.5lf\nMetros = %.2lf",in,ft,yrd,miles,mts);

  return 0;
}
