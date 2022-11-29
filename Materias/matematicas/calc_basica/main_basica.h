#pragma once
#include "need_calc_basica.h"
#include <stdio.h>

float valor1=0, valor2=0;
char char_val1[34], char_val2[34];

void main_calc_basica()
{
    char ejecucion;

    printf("ingresar la ecuacion\nrecordar solo usar 2 numeros (pueden ser float)\n");
    printf("\nusar:\nx = *\nd = /");
    printf("\n\nexample\n\n23\nx\n45\nempezar:\n");
    scanf("%s", &char_val1);
    scanf("%s", &ejecucion);
    scanf("%s", &char_val2);

    thisis_main_return();

    printf("\n%f %c %f\n",valor1,ejecucion,valor2);

    if (ejecucion == '+')
    {
        printf("Resultado: %f",valor1 + valor2);
    }
    if (ejecucion == '-')
    {
        printf("Resultado: %f",valor1 - valor2);
    }
    if (ejecucion == 'x' || ejecucion == '*')
    {
        printf("Resultado: %f", valor1 * valor2);
    }
    if (ejecucion == 'd' || ejecucion == '/')
    {
        if (valor2 != 0)
        {
            printf("Resultado: %f", valor1 / valor2);
        }
        else
        {
            printf("no se puede dividir entre nada");
        }
    }
}

void thisis_main_return()
{
    char temp[30];

    for (int i = 0; i < strlen(char_val1); i++)
    {
        if (char_val1[0] == '-')
        {
            for (int j = 1; j < strlen(char_val1); j++)
            {
                strncat(temp, &char_val1[j], 1);
            }   
        }
        else
        {
            strncat(temp, &char_val1[i], 1);
        }
    }
    valor1 = (float)strtod(temp, NULL);
    if (char_val2[0] == '-')
    {
        valor1 = negativizar(valor1);
    }

    memset(temp, 0, sizeof temp);

    for (int i = 0; i < strlen(char_val2); i++)
    {
        if (char_val2[0] == '-')
        {
            for (int j = 1; j < strlen(char_val2); j++)
            {
                strncat(temp, &char_val2[j], 1);
            }   
        }
        else
        {
            strncat(temp, &char_val2[i], 1);
        }
    }
    valor2 = (float)strtod(temp, NULL);
    if (char_val2[0] == '-')
    {
        valor2 = negativizar(valor2);
    }

    memset(temp, 0, sizeof temp);
}

float negativizar(float val1)
{
    return (-1) * val1;
}