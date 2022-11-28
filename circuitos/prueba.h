#pragma once
#include "need_circuitos.h"

void main_prueba();

void main_prueba()
{
    float a = 4364.2;
    float b = 324.4;
    float c = r_resistencia(a, b, 0);
    visualmente_void_ParaleloResistor(4, 346.5, a);
    visualmente_void_ParaleloResistor(67, 346.5, b);
    visualmente_void_ParaleloResistor(2, 346.5, c);

    visualmente_void_SerieResistor(4, 346.5, a);
    visualmente_void_SerieResistor(67, 346.5, b);
    visualmente_void_SerieResistor(2, 346.5, c);

    getch();
}
