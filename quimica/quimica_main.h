#pragma once
#include "need_quimica.h"

int n, opcion, op1;
float pv = 0, x2, dpv, dtc, ke, kc, m, dte, posmo, t, molar, val_pH, val_pOH, cH, coH, w, q, dU, pre, vol, base;

void main_quimica()
{
  do
  {
    printf("\n   1. Propiedades coligativas .");
    printf("\n   2. Termodinamica .");
    printf("\n   3. Equilibrio ionico.");
    printf("\n   4. Salir.");
    printf("\n\n   Introduzca una opcion (1-4): ");

    scanf("%d", &opcion);

    /* Inicio del anidamiento */

    switch (opcion)
    {
    case 1:
      propiedades_coligativas();
    case 2:
      termodinamica();
    case 3:
      equilibrio_ionico();
    }

    printf("\n\n");
    /* Fin del anidamiento */
  } while (opcion != 4);
}

void propiedades_coligativas()
{
  do
  {
    printf("Eliga la opción que desea calcular");
    printf("\n   1. Presión de vapor  .");
    printf("\n   2. Descenso crioscopico.");
    printf("\n   3. Ascenso ebulloscopico.");
    printf("\n 4. Presión osmótica");
    printf("\n   5. Salir.");
    printf("\n\n   Introduzca opcion (1-5): ");
    scanf("%d", &op1);
    switch (op1)
    {
    case 1:
      printf("\n   Introduzca la presión de vapor del solvente:\n  ");
      scanf("%f", &pv);
      printf("\n Introduzca x2 :\n");
      scanf("%f", &x2);
      dpv = pv * x2;
      printf("\nEl delta de la presión de vapor es :%3.f", dpv);
      break;
    case 2:
      printf("\t\t Descenso crioscopico\t\t");
      printf("\n Introdusca Kc:\n");
      scanf("%f", &kc);
      printf("\n Introdusca m:\n");
      scanf("%f", &m);
      dtc = ke * m;
      printf("El valor de delta de TC es:\n %3.f", dtc);
      break;
    case 3:
      m = 0;
      printf("\t\t Ascenso ebulloscopico");
      printf("\n Introdusca ke:\n");
      scanf("%f", &ke);
      printf("\n Introdusca m:\n ");
      scanf("%f", &m);
      dte = ke * m;
      printf("\n Delta de te es:\n %3.f", dte);
      break;
    case 4:
      printf("\t\t Presión osmótica");
      printf("\nIntrodusca M:\n");
      scanf("%f", &molar);
      printf("\n Introdusca t:\n");
      scanf("%f", &t);
      posmo = molar * (R * t);
      printf("\n La presión osmótica es :%3.f", posmo);
      break;

    default:
      printf("\t\t ERROR LA OPCIÓN INGRESADA NO ES CORRECTA    ");
    }

    printf("\n\n");
  } while (op1 != 5);
}

void termodinamica()
{
  printf("\t\t Termodinámica \t\t");
  do
  {
    printf(" \n 1. calcular el trabajo");
    printf(" \n 2. Energía interna ");
    printf(" \n 3.salir\n");
    scanf("%d", &op1);
    switch (op1)
    {
    case 1:
      printf("\t\t Trabajo\t\t");
      printf("\n Ingrese la presión\n");
      scanf("%f", &pre);
      printf("\n Ingrese delta de volúmen\n");
      scanf("%f", &vol);
      w = pre * vol;
      printf("\n El trabajo es :%f", w);
      break;
    case 2:
      w = 0;
      printf("\t\t Variación de la energía interna\t\t");
      printf("\n Ingrese W");
      scanf("%f", &w);
      printf("\n Ingrese Q");
      scanf("%f", &q);
      dU = q + w;
      printf("\n La variación de energía es :%f", dU);
      break;
    default:
      printf("\t\t ERROR LA OPCIÓN INGRESADA NO ES CORRECTA\t\t");
    }

    printf("\n\n");
  } while (op1 != 3);
}

void equilibrio_ionico()
{
  op1 = 0;
  do
  {
    printf("\n   1. Calcular el pH.");
    printf("\n   2. Calcular el poH .");
    printf("\n   3. calcular concentración de [oh-].");
    printf("\n 4. Calcular la concentración de [H+]");
    printf("\n   5. Salir.");
    printf("\n\n   Introduzca opci%cn (1-5): ");
    scanf("%d", &op1);
    switch (op1)
    {
    case 1:
      pH();
    case 2:
      pOH();
      break;
    case 3:
      concentracion_OH();
    case 4:
      concentracion_H();
        break;
    default:
      printf("\t\t ERROR OPCIÓN INGRESADA INCORRECTA\t\t");
    }

    printf("\n\n");
  } while (op1 != 5);
}

////////////////////////////////////////////////////////////
//                      VALORES H OH                      //
////////////////////////////////////////////////////////////

void pH()
{
  printf("\t\t Calculo de pH\t\t");
  printf("\n Introdusca la concentración de [H]:\n");
  scanf("%f", &cH);
  double pH = (log10(cH) * (-1));
  printf("\n El valor del pH es :%f", val_pH);
}
void pOH()
{
  printf("\t\t Calculo del poH\t\t");
  printf("\n Introdusca [oH-]:\n");
  scanf("%f", &coH);
  double poH = (log10(coH) * (-1));
  printf("\n El poH es:%f", val_pOH);
}

////////////////////////////////////////////////////////////
//                   CONCENTRACION H OH                   //
////////////////////////////////////////////////////////////

void concentracion_OH()
{
  val_pOH = 0;
  coH = 0;
  base = 10;
  printf("\t\t Cálculo de la concentración de [oH-]");
  printf("\n Introdusca el valor del poH");
  scanf("%f", &val_pOH);
  coH= pow(10, -1 * val_pOH);
 
  printf("\n\n La concentración es de [oH]es: %f \n" , coH);
}
void concentracion_H()
{
  val_pH = 0;
  cH = 0;
  printf("\t\t Cálculo de la concentración de [oH-]");
  printf("\n Introdusca el valor del pH");
  scanf("%f", &val_pH);
  cH= pow(10, -1 * val_pH);

  printf("\n\nLa concentración es [H]:%f ", cH);
}
