#pragma once
#include <stdio.h>
#include "need_maths.h"

void main_calc_basica();
void main_maths()
{
    int opcion;
    float area, l1, l2, radio, h, base;
    printf("              _____      _            _           _\n             / ____|    | |          | |         | |\n            | |     __ _| | ___ _   _| | __ _  __| | ___  _ __ __ _ \n");
    printf("            | |    / _` | |/ __| | | | |/ _` |/ _` |/ _ \\| '__/ _` |\n            | |___| (_| | | (__| |_| | | (_| | (_| | (_) | | | (_| |\n             \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__,_|\\___/|_|  \\__,_|\n\n\n");
    printf("                    _____ _            _   _  __ _ \n                   / ____(_)          | | (_)/ _(_)\n                  | |     _  ___ _ __ | |_ _| |_ _  ___ __ _ \n");
    printf("                  | |    | |/ _ \\ '_ \\| __| |  _| |/ __/ _` |\n                  | |____| |  __/ | | | |_| | | | | (_| (_| |\n                   \\_____|_|\\___|_| |_|\\__|_|_| |_|\\___\\__,_|\n\n\n");
   printf(" \n >>Welcome to los pollo hermanos<<  \n  ");
       printf("\n     ===================\n ");
       printf("\n   0- Calculadora Basica\n");
      printf(" \n     ===================\n \n");
    printf("  \n      1- Cuadrado\n", 163);
    printf(" \n      2- Rectangulo\n", 163);
    printf(" \n      3- Triangulo\n", 163);
    printf("  \n      4- Ciruclo\n", 163);
      printf("\n     ===================\n ");
       printf("\n     ===================\n ");
    printf("\n Por favor introduce una opcion:");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 0:
    {
        main_calc_basica();
        break;
    }
    case 1:
    {
        printf("Introduzca el lado de cuadrado: ");
        scanf("%f", &l1);

        area = l1 * l1;
        printf("El area es de: %f", area);

        break;
    }

    case 2:
    {
        printf("Introduzca el lado 1 del Rectangulo: ");
        scanf("%f", &l1);

        printf("Introduzca el lado 2 del Rectangulo: ");
        scanf("%f", &l2);

        area = l1 * l2;
        printf("El area es de: %f", area);

        break;
    }

    case 3:
    {
        printf("\n\n\n\n\n");
        printf("\nTriangulo Rectangulo: \n");
        main_triangulos();

        break;
    }
    case 4:
    {
        printf("Introduzca el radio del circulo: ");
        scanf("%f", &radio);

        area = (radio * radio) * 3.14;
        printf("El area es de: %f", area);

        break;
    }

    default:
        printf("ERROR: no fue valido");
    }
}
