#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char thisis_leer[6] = "true", ejecucion_n='+';
char compatibilidad = 'V';

char *char_valor_numer1, *char_valor_numero2;
float valor_numer1, valor_numero2;

/// @brief
/// @param this_ingreso ingresar todo el texto del usuario
/// @param value1 Te lo completo con el primer float
/// @param value2 Te lo completo con el segundo float
/// @param ejecucion Lo que debes hacer con esos 2 numeros
void thisis_main_return(char this_ingreso[], float value1, float value2, char ejecucion);

float integrar_numero(char x[], float valor_numero);
float negativizar(float val1);

void thisis_validar(char num[]);

//&&&&&&&&&&&&&&&       CON RETORNO       &&&&&&&&&&&&&&&

void thisis_main_return(char this_ingreso[], float value1, float value2, char ejecucion)
{
    thisis_validar(this_ingreso);

    value1 = valor_numer1;
    value2 = valor_numero2;

    printf("valores antes de:\n %f\n %f\n",valor_numer1, valor_numero2);
    
    printf("\nEsta es la ejecucion: %c\n", ejecucion_n);

    if (compatibilidad == 'n' || ejecucion_n == ' ')
    {
        ejecucion = 'n';
    }
    else
    {
        ejecucion = ejecucion_n;
    }
    
}

void thisis_validar(char num[])
{
    int puntos_presentados=0;
    int finalmente;

    
    char temp[25];

    for (int i = 0; i < strlen(num); i++)
    {
        if (!isdigit(num[i]))
        {
            finalmente = i+1;
        }
        
        if (isdigit(num[i]))
        {
            if (num[i+1] == '-' || num[i+1] == '+' || num[i+1] == '/'
             || num[i+1] == '*' || num[i+1] == ' ' || num[i+1] == '\0')
            {
                for (int no_es_i = finalmente; no_es_i < i+1; no_es_i++)
                {
                    
                    if (finalmente == 0 || finalmente == 1)
                    {
                        strncat(temp, &num[no_es_i], 1);

                    }
                    else
                    {
                        strncat(temp, &num[no_es_i], 1);
                    }
                }

                if (finalmente == 0 || finalmente == 1)
                {
                    char_valor_numer1 = temp;
                    valor_numer1 = integrar_numero(char_valor_numer1, valor_numer1);
                    if (num[i-1] == '-')
                    {
                        valor_numer1 = negativizar(valor_numer1);
                    }
                    
                    memset(temp, 0, sizeof temp);
                }
                else
                {
                    char_valor_numero2 = temp;
                    valor_numero2 = integrar_numero(char_valor_numero2, valor_numero2);
                    memset(temp, 0, sizeof temp);
                    if (num[i-1] == '-')
                    {
                        valor_numero2 = negativizar(valor_numero2);
                    }
                }

                finalmente = i + 2;
            }
        }

        printf("\nEsta es la ejecucion: %c\n", ejecucion_n);
    }

    // REEVALUAMOS LAS EJECUCIONES(simbologia)
    for (int i = 0; i < strlen(num); i++)
    {
        if (num[i] == '.')
        {
            puntos_presentados++;
        }

        if (num[i]== '*' || num[i] == '/')
        {
            ejecucion_n = num[i];
        }

        if (num[i] != '*' || num[i] != '/' || num[i] || '+')
        {
            ejecucion_n = 'n';   
        }
    }
    
    if (2 < puntos_presentados)
    {
        ejecucion_n = 'n';
    }

}

//&&&&&&&&&&&&&&&       Global used       &&&&&&&&&&&&&&&

float integrar_numero(char *x, float valor_numero)
{
    valor_numero = (float)strtod(x, NULL);
    return valor_numero;
}

float negativizar(float val1)
{
    return (-1) * val1;
}
