#pragma once
#include <stdio.h>

float V = 0, I = 0, R = 0;
float V2 = 0, I2 = 0, R2 = 0;

void circuitos_escaneo()
{
    printf("Del primer resistor:");
    printf("\nV: ");
    scanf("%f", &V);

    printf("\nI: ");
    scanf("%f", &I);

    printf("\nR: ");
    scanf("%f", &R);

    printf("Del segundo resistor:");
    printf("\nV2: ");
    scanf("%f", &V2);

    printf("\nI2: ");
    scanf("%f", &I2);

    printf("\nR2: ");
    scanf("%f", &R2);
}


void circuitos_recompletar()
{
    // caso I distinta de 0
    if (I != 0)
    {
        if (R != 0 && V == 0)
        {
            V = r_fem(V, I, R);
        }
        if (V != 0 && R == 0)
        {
            R = r_resistencia(V, I, R);
        }
    }

    if (I2 != 0)
    {
        if (R2 != 0 && V2 == 0)
        {
            V2 = r_fem(V2, I2, R2);
        }
        if (V2 != 0 && R2 == 0)
        {
            R2 = r_resistencia(V2, I2, R2);
        }
    }

    // caso R distinta de 0
    if (R != 0)
    {
        if (I != 0 && V == 0)
        {
            V = r_fem(0, I, R);
        }
        if (V != 0 && I == 0)
        {
            I = r_intensidad(V, I, R);
        }
    }

    if (R2 != 0)
    {
        if (I2 != 0 && V2 == 0)
        {
            V2 = r_fem(V2, I2, R2);
        }
        if (V2 != 0 && I2 == 0)
        {
            I2 = r_intensidad(V2, I, R2);
        }
    }

    // V distinta de 0
    if (V != 0)
    {
        if (R != 0 && I == 0)
        {
            I = r_intensidad(V, I, R);
        }
        if (I != 0 && R == 0)
        {
            R = r_resistencia(V, I, R);
        }
    }

    if (V2 != 0)
    {
        if (R2 != 0 && I2 == 0)
        {
            I2 = r_intensidad(V2, I2, R2);
        }
        if (I2 != 0 && R2 == 0)
        {
            R2 = r_resistencia(V2, I2, R2);
        }
    }
}


float r_fem(float tension, float intensidad, float resistencia)
{
    return intensidad * resistencia;
}
float r_intensidad(float tension, float intensidad, float resistencia)
{
    return tension / resistencia;
}
float r_resistencia(float tension, float intensidad, float resistencia)
{
    return tension / intensidad;
}