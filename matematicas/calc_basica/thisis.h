#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

float this_tipo_a = 0, this_tipo_b = 0;

int this_int = 0;
float this_float = 0;
char *this_string = "0";
char thisis_leer[6] = "true";
char *simbolo;

int thisis_main_return(char this_ingreso[]);
void thisis_validar(char num[]);
void thisis(char this_valor[]);
int thisis_return();

//&&&&&&&&&&&&&&&       Global used       &&&&&&&&&&&&&&&

void thisis(char this_valor[])
{
    this_tipo_a = (float)strtod(this_valor, NULL);
    this_tipo_b = (int)strtod(this_valor, NULL);

    if ((this_tipo_a - this_tipo_b) > 0)
    {
        this_float = 1;
    }
    else
    {
        this_int = 1;
    }
}

//&&&&&&&&&&&&&&&       CON RETORNO       &&&&&&&&&&&&&&&

/// @brief 
/// @param this_ingreso add type char to return some value.
/// @return int(1) float(2) string(3)
int thisis_main_return(char this_ingreso[])
{

    thisis_validar(this_ingreso);
    return thisis_return();
}

void thisis_validar(char num[])
{
    for (int i = 0; i < strlen(num) && num[i] != " "; i++)
    {
        if (!isdigit(num[i]))
        {
            if (num[i] == "-")
            {
                simbolo = "-";
            }

            if (num[i] == "*")
            {
                simbolo = "*";
            }
            
            if (num[i] == "+")
            {
                simbolo = "+";
            }

            if (num[i] == "/")
            {
                simbolo = "/";
            }
            
            if (num[i] != "-" && num[i] != "+" && num[i] != "/" && num[i] != "+")
            {
                simbolo = "n";
            }

        }

        if (isdigit(num[strlen(num) - 1]))
        {
            thisis(num);
        }
    }
}

int thisis_return()
{
    if (this_int == 1)
    {
        return (1);
    }

    if (this_float == 1)
    {
        return (2);
    }

    if (this_string == "1")
    {
        return (3);
    }
}