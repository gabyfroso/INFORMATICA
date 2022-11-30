#pragma once
#include "need_circuitos.h"

char partir_punto= 'F';
char vis_buf[100], vis_buf2[100];

void visualmente_void_ParaleloResistor(float data_intensidad, float data_tension, float data_resistencia)
{    
    gcvt(data_resistencia, 7, vis_buf);

    int linea = strlen(vis_buf)+4;

    // DEl dibujo
    //         V=         .
    
    printf("\n         V= %.4f", data_tension);
    printf("\n         I= %.4f", data_intensidad);
    printf("\n      ");

    //  ____________
    printf(" ");
    for (int i = 0; i < linea*2; i++)
    {
        printf("_");
    }

    //---| R=       |---
    printf("\n  ---| R= %.5f", data_resistencia);
    for (int i = 0; i < linea-5; i++)
    {
        printf(" ");
    }
    printf("|---\n      ");



    for (int i = 0; i < linea*2+1; i++)
    {
        printf("-");
    }
    printf("\n");
    printf("\n");
}

void visualmente_void_SerieResistor(float data_intensidad, float data_tension, float data_resistencia)
{   
    gcvt(data_resistencia, 7, vis_buf);
    gcvt(data_tension, strlen(vis_buf), vis_buf2);

    printf("\n  |   I = %.4f", data_intensidad);
    printf("\n|¯¯¯|\n");
    printf("| R |  V");
    for (int i = 0; i < strlen(vis_buf); i++)
    {
        printf("\n| %c |  %c", vis_buf[i], vis_buf2[i]);
    }
    for (int i = 0; i < 8-strlen(vis_buf); i++)
    {
        printf("\n|   |");
    }
    
    printf("\nL___| ");
    printf("\n  |  ");

    memset(vis_buf, 0, sizeof(vis_buf));
    memset(vis_buf, 0, sizeof(vis_buf2));
}