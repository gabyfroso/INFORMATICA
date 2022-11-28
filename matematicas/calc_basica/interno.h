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
    int numero_procesado = 1;
    int final_del_numero=0;

    char temp[25];

    for (int i = 0; i < strlen(num) - 1; i++)
    {
        if (i == final_del_numero)
        {
            hasta_donde_almacenar(num, i, final_del_numero);

            for (int i_i = i; i_i < final_del_numero; i_i++)
            {
                strncat(temp, &num[i_i], 1);
            }
        }

        switch (numero_procesado)
        {
        case 1:
            printf("\nTemp: %s\n", temp);
            valor_numer1 = integrar_numero(temp, valor_numer1);
            memset(temp, 0, sizeof temp);

            numero_procesado++;
            break;
        case 2:
            valor_numero2 = integrar_numero(temp, valor_numero2);
            memset(temp, 0, sizeof temp);
            break;
        default:
            printf("Error 404");
            break;
        }
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

float integrar_numero(char *x, float valor_numero)
{
    printf("\nCaptado: %s\n", x);
    if (x[0] == '-')
    {
        for (int i = 0; i < strlen(x); i++)
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

// strncat(temp, &num[i], 1);
// almacena en temp si
//  [-]x
//   -[x]
// o [x]x
// o [x].x
// o x.[x]

// used
// (char_dat[nao_sei_i] != '-')
// !(!isdigit(char_dat[i-1]) && isdigit(char_dat[i]))
// !(isdigit(char_dat[i]) && isdigit(char_dat[i+1]))
// !(isdigit(char_dat[i]) && char_dat[i+1] == '.' && isdigit(char_dat[i+2]))
// !(isdigit(char_dat[i-2]) && char_dat[i-1] == '.' && isdigit(char_dat[i]))

int hasta_donde_almacenar(char *char_dat, int inicio, int fin)
{
    char seguir='v';

    for (int nao_sei_i = inicio; seguir='v'; nao_sei_i++)
    {
        if ( !(char_dat[nao_sei_i] != '-'))
        {
            seguir='f';
            fin == nao_sei_i;
        }
        if ( !(!isdigit(char_dat[nao_sei_i-1]) && isdigit(char_dat[nao_sei_i])) )
        {
            seguir='f';
            fin == nao_sei_i;
        }
        if ( !(isdigit(char_dat[nao_sei_i]) && isdigit(char_dat[nao_sei_i+1])) )
        {
            seguir='f';
            fin == nao_sei_i;
        }
        if ( !(isdigit(char_dat[nao_sei_i]) && char_dat[nao_sei_i+1] == '.' && isdigit(char_dat[nao_sei_i+2])) )
        {
            seguir='f';
            fin == nao_sei_i;
        }
        if ( !(isdigit(char_dat[nao_sei_i-2]) && char_dat[nao_sei_i-1] == '.' && isdigit(char_dat[nao_sei_i])) )
        {
            seguir='f';
            fin == nao_sei_i;
        }
    }
}