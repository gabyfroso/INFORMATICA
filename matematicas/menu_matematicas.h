#include <stdio.h>
#include "need_maths.h"

int main()
{
    int opcion;
    float area, l1, l2, radio, h, base;

   printf(" \n >>Welcome to los pollo hermanos<<  \n  ");
       printf("\n     ===================\n ");
      printf(" \n     ===================\n ");
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
