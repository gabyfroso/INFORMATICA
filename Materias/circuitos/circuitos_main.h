#pragma once
#include "need_circuitos.h"

char *char_tipo_de_circuitos[3] =
    {"1- Serie",
     "2- Paralelo",
     "3- Mixto"};

int ir_al_;

float Vr = 0, Ir = 0, Rr = 0;

/// @brief El mismisimo infierno
void main_circuitos()
{

    printf("¿con que tipo de circuitos se presenta?\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", char_tipo_de_circuitos[i]);
    }
    scanf("%d", &ir_al_);

    printf("\nrecuerde poner 0 cuando no sepa el resultado\n");

    switch (ir_al_)
    {
    case 1:

        printf("datos que conoce del circuito:\n");
        printf("Al ser en serie, se usará el primer valor agregado de I distinto de 0\n\n");
        circuitos_escaneo();
        circuitos_enSerie();
        circuitos_say_resultados();

        printf("\nGraficos\n");
        visualmente_void_SerieResistor(I,V,R);
        visualmente_void_SerieResistor(I2,V2,R2);
        break;
    case 2:

        printf("datos que conoce del circuito:\n");
        printf("Recuerde que se va a usar la primera tension distinta de 0:\n\n");
        circuitos_escaneo();
        circuitos_enParalelo();
        circuitos_say_resultados();
        printf("\nGraficos\n");
        visualmente_void_ParaleloResistor(I,V,R);
        visualmente_void_ParaleloResistor(I2,V2,R2);
        break;
    case 3:

        circuitos_Mixtos();
        break;
    default:
        printf("\nNo existe, finalizando...");
        break;
    }

    printf("\n\nResultado\n");
    visualmente_void_SerieResistor(Ir, Vr, Rr);
}

// Ley Ohm, la intensidad es proporcional a la tensión, e inversamente proporcional a la resistencia
//
//              |V|
//            |I | R|

// %%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%% //
//   C I R C U I T O S   : T I P O     SERIE    //
// %%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%% //

void circuitos_enSerie()
{
    for (int i = 0; i < 4; i++)
    {
        if (I != 0)
        {
            I2 = I;
        }
        if (I2 != 0)
        {
            I = I2;
        }
        if (I != 0)
        {
            I2 = I;
        }

        circuitos_recompletar();
    }

    // SERIE PRIMERO. entonces usaremos las propiedades del serie
    // Rr = R + R2 + ... + Rn
    // Ir = I = I2 = ... = In
    // Vr = -(V + V2 + ... + Vn)

    Rr = R + R2;
    Ir = I;
    Vr = V + V2;
}

// %%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%% //
//   C I R C U I T O S   : T I P O     PARALELO //
// %%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%% //

void circuitos_enParalelo()
{
    for (int i = 0; i < 4; i++)
    {
        if (V != 0)
        {
            V2 = V;
        }
        if (V2 != 0)
        {
            V = V2;
        }
        if (V != 0)
        {
            V2 = V;
        }
        circuitos_recompletar();
    }

    // PARALELO PRIMERO. entonces usaremos las propiedades del paralelo
    // Rr = 1/(1/R + 1/R2 + ... + 1/n)
    // Vr = V = V2 = ... Vn
    // Ir = I + I2 + ... + In

    Rr = 1 / (1 / R + 1 / R2);
    Vr = V;
    Ir = I + I2;
}

// %%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%% //
//   C I R C U I T O S   : T I P O     MIXTO    //
// %%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%% //

char *verdad = "v";

void circuitos_Mixtos()
{
    printf("Elija el caso donde SOLO tenga 2 resistencias en un tipo de circuito:\n");

    for (int i = 0; i < 2; i++)
    {
        printf("Primero fue el %s \n", char_tipo_de_circuitos[i]);
    }

    scanf("%d", &ir_al_);

    switch (ir_al_)
    {
    case 1:
        printf("\nBien, resuelvamos el serie primero\n");
        circuitos_escaneo();
        circuitos_enSerie();
        break;

    case 2:
        printf("\nBien, resuelvamos el paralelo primero\n");
        circuitos_escaneo();
        circuitos_enParalelo();
        break;
    default:
        printf("Error: instruccion no valida, \nFinalizando...");
        goto fin;
        break;
    }

    // SERIE PRIMERO. entonces usaremos las propiedades del serie
    // Rr = R + R2 + ... + Rn
    // Ir = I = I2 = ... = In
    // Vr = -(V + V2 + ... + Vn)

    if (ir_al_ == 1)
    {
        printf("Resultados de circuito en serie:\n");
        circuitos_say_resultados();
        printf("\n\nLos usaremos en el circuito paralelo; \n\n");

        V = Vr;
        I = Ir;
        I2 = 0;
        R = Rr;
        R2 = 0;

        do
        {
            printf("Se debe tener al menos uno de los siguientes 2 valores\n");
            printf("poner 0 si no se sabe\n");

            printf("Intensidad del otro resistor: ");
            scanf("%f", &I2);
            printf("Resistencia del otro resistor: ");
            scanf("%f", &R2);

            if (I2 != 0 && R2 != 0)
            {
                if (I2 != r_intensidad(V2, 0, R2) || R2 != r_resistencia(V2, I2, 0))
                {
                    printf("Error en uno de sus datos, vuelvamoslo a intentar.\n\n");
                    verdad = "F";
                }
            }
            else
            {
                verdad = "V";
            }

        } while (verdad == "F");

        printf("cuente con que V, I y R son de la otra resistencia resultante");
        circuitos_enParalelo();
        circuitos_say_resultados();
    }

    // PARALELO PRIMERO. entonces usaremos las propiedades del paralelo
    // Rr = 1/(1/R + 1/R2 + ... + 1/n)
    // Vr = V = V2 = ... Vn
    // Ir = I + I2 + ... + In
    if (ir_al_ == 2)
    {
        printf("Resultados de circuito en paralelo:\n");
        circuitos_say_resultados();
        printf("\n\nLos usaremos en el circuito Serie; \n");

        V = Vr;
        V2 = 0;
        I = Ir;
        R = Rr;
        R2 = 0;

        do
        {
            printf("Se debe tener al menos uno de los siguientes 2 valores\n");
            printf("poner 0 si no se sabe\n");

            printf("Tension del otro resistor: ");
            scanf("%f", &V2);
            printf("Resistencia del otro resistor: ");
            scanf("%f", &R2);

            if (V2 != 0 && R2 != 0)
            {
                if (V2 != r_intensidad(0, I2, R2) || R2 != r_resistencia(V2, I2, 0))
                {
                    printf("Error en uno de sus datos, vuelvamoslo a intentar.\n\n");
                    verdad = "F";
                }
            } else
            {
                verdad = "V";
            }
            

        } while ( verdad == "F");

        printf("\n\nCuente con que V, I y R son de la otra resistencia resultante\n");
        circuitos_enSerie();
        circuitos_say_resultados();
    }

fin:
}

// %%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%% //
//   C I R C U I T O S :  S O L O _ A Y U D A S //
// %%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%% //

void circuitos_say_resultados()
{
    printf("\nResultados\n");



    printf("\nV = %f", V);
    printf("\nI = %f", I);
    printf("\nR = %f", R);

    printf("\n");

    printf("\nV2 = %f", V2);
    printf("\nI2 = %f", I2);
    printf("\nR2 = %f", R2);

    printf("\n");

    printf("\nVR = %f", Vr);
    printf("\nIR = %f", Ir);
    printf("\nRR = %f", Rr);

    printf("\n\n");
}