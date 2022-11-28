#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "need_calc_basica.h"

char thisis_leer[6] = "true", ejecucion_n = '+';
char compatibilidad = 'V';

float valor_numer1, valor_numero2;

//&&&&&&&&&&&&&&&       CON RETORNO       &&&&&&&&&&&&&&&

void thisis_main_return(char this_ingreso[], float value1, float value2, char ejecucion)
{
    thisis_validar(this_ingreso);

    value1 = valor_numer1;
    value2 = valor_numero2;

    ejecucion = ejecucion_n;
}

void thisis_validar(char num[])
{
    int puntos_presentados = 0;

    int n_process = 1;
    int inicio_del_numero = 0;

    char temp[25];

    // strncat(temp, &num[i], 1);
    // almacena en temp si
    //  [-]x
    //   -[x]
    // o [x]x
    // o [x].x
    // o x.[x]
    for (int i = 0; i < strlen(num); i++)
    {
        do
        {
            strncat(temp, &num[i], 1);
            i++;
        } while (isdigit(num[i]) && (isdigit(num[i+1]) || (num[i+1] == '.')));

        valor_numer1 = integrar_numero(temp);
        memset(temp, 0, sizeof temp);
        do
        {
            strncat(temp, &num[i], 1);
            i++;
        } while (isdigit(num[i]) && (isdigit(num[i+1]) || (num[i+1] == '.')));

        valor_numero2 = integrar_numero(temp);
        memset(temp, 0, sizeof temp);
    }
    

    printf("\n\n%f %c %f\n\n", valor_numer1, ejecucion_n, valor_numero2);
    // REEVALUAMOS LAS EJECUCIONES(simbologia)

    for (int i = 0; i < strlen(num); i++)
    {
        if (!isdigit(num[i]) && !isdigit(num[i + 1]))
        {
            ejecucion_n = num[i];
        }

        if (!isdigit(num[i]) && !isdigit(num[i + 1]) && !isdigit(num[i + 2]))
        {
            printf("\n%c\neste valor cancelara todo\n", num[i + 1]);
            ejecucion_n = 'n';
        }
    }

    printf("\n\n%f %c %f\n\n", valor_numer1, ejecucion_n, valor_numero2);

    if (2 < puntos_presentados)
    {
        ejecucion_n = 'n';
    }
}
//&&&&&&&&&&&&&&&       Global used       &&&&&&&&&&&&&&&

float integrar_numero(char *x)
{
    float valor_numero;
    printf("\nCaptado: %s\n", x);
    if (x[0] == '-')
    {
        for (int i = 1; i < strlen(x); i++)
        {
            valor_numero = (float)strtod(x, NULL);
        }
        valor_numero = negativizar(valor_numero);
    }
    else
    {
        valor_numero = (float)strtod(x, NULL);
    }

    return valor_numero;
}

float negativizar(float val1)
{
    return (-1) * val1;
}

// used
// (char_dat[nao_sei_i] != '-')
// !(!isdigit(char_dat[i-1]) && isdigit(char_dat[i]))
// !(isdigit(char_dat[i]) && isdigit(char_dat[i+1]))
// !(isdigit(char_dat[i]) && char_dat[i+1] == '.' && isdigit(char_dat[i+2]))
// !(isdigit(char_dat[i-2]) && char_dat[i-1] == '.' && isdigit(char_dat[i]))

int hasta_donde_almacenar(char *char_dat, int inicio, int fin)
{
    char seguir = 'v';

    for (int nao_sei_i = inicio; seguir = 'v'; nao_sei_i++)
    {
    }
}