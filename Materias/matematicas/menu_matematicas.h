#include <stdio.h>
#include "need_maths.h"

int main()
{
    int opcion;
    float area, l1, l2, radio, h, base;

    printf("=================\n");
    printf(" 0- Calculadora Basica");
    printf(" 1- Cuadrado\n");
    printf(" 2- Rectangulo\n");
    printf(" 3- Triangulo\n");
    printf(" 4- Ciruclo\n");
    printf("===================\n");
    printf("Por favor introduce una opcion:");
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 0:
    {
        main_calc_basica();
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
        printf("Triangulo Rectangulo: ");
        main_triangulos();
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
        printf("ERROR: AGREGA BIEN NO TE CUESTA NADA");
    }
}