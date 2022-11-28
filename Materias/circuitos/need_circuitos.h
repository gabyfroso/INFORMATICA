#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief
/// @param data_intensidad intensidad
/// @param data_tension Fem || Tensión
/// @param data_resistencia Resistencia
void visualmente_void_ParaleloResistor(float data_intensidad, float data_tension, float data_resistencia);
void visualmente_void_SerieResistor(float data_intensidad, float data_tension, float data_resistencia);

void main_circuitos();
void circuitos_enSerie();
void circuitos_enParalelo();
void circuitos_Mixtos();
void circuitos_say_resultados();

float r_fem(float tension, float intensidad, float resistencia);
float r_intensidad(float tension, float intensidad, float resistencia);
float r_resistencia(float tension, float intensidad, float resistencia);

void circuitos_escaneo();
void circuitos_recompletar();

#include "circuitos_escaneo_y_recompletar.h"
#include "prueba.h"
#include "circuitos_main.h"
#include "visualmente.h"