#pragma once

void main_calc_basica();
float multiplicacion(float val1, float val2);
float division(float val1, float val2);
float suma(float val1, float val2);

/// @brief
/// @param this_ingreso ingresar todo el texto del usuario
/// @param value1 Te lo completo con el primer float
/// @param value2 Te lo completo con el segundo float
/// @param ejecucion Lo que debes hacer con esos 2 numeros
void thisis_main_return(char this_ingreso[], float value1, float value2, char ejecucion);

float integrar_numero(char *x);
float negativizar(float val1);

void thisis_validar(char num[]);
int hasta_donde_almacenar(char dat[], int inicio, int fin);

#include "main_basica.h"
#include "interno.h"