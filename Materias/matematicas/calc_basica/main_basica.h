#pragma once
#include "need_calc_basica.h"
#include <stdio.h>

void main_calc_basica()
{
    float valor1=0, valor2=0, Resultado;
    char char_ingresado[60];
    char ejecucion;

    printf("ingresar la ecuacion\nrecordar solo usar 2 numeros (pueden ser float)\n");
    printf("\nno usar espacios, por favor\n");
    scanf("%s", &char_ingresado);

    thisis_main_return(char_ingresado, valor1, valor2, ejecucion);

    printf("\n%f %c %f\nR= %f",valor1,ejecucion,valor2, Resultado);


    if (ejecucion == '+')
    {
        Resultado = suma(valor1,valor2);
    }
    if (ejecucion == '*')
    {
        Resultado = multiplicacion(valor1,valor2);
    }
    if (ejecucion == '/')
    {
        if (valor2 != 0)
        {
            Resultado = division(valor1,valor2);
        }
        else
        {
            printf("no se puede dividir entre nada");
        }
    }

    printf("\n%f %c %f\nR= %f",valor1,ejecucion,valor2, Resultado);
}

float multiplicacion(float val1, float val2)
{   
    return val1 * val2;
}

float division(float val1, float val2)
{
    return val1 / val2;
}

float suma(float val1, float val2)
{
    return val1 + val2;
}