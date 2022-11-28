#pragma once
#include <stdio.h>
#include <math.h>
#include "need_maths.h"

float a = 0, b = 0, c = 0;
float alpha = 0, beta = 0;

float perimetro = 0, area = 0;
char mirar;

/////////////////////////////////////////////////////////
//        D  E    U  S  O    G  E  N  E  R  A  L       //
/////////////////////////////////////////////////////////

char demostrative[9][200] = {
    "            /|",
    "          /  |",
    "        /beta|",
    "    c /      |b",
    "    /        |",
    "  /___       |",
    " /alpha)      |",
    "-------------",
    "        a     \n\n"};

////////
// 1- Triangulo rectangulo
// SOH CAH TOA

void main_triangulos()
{
    printf("¿desea ver una demostracion del triangulo?\n(S/N)");
    scanf("%s", &mirar);

    if (mirar == 'S' || mirar == 's')
    {
        for (int i = 0; i < 9; i++)
        {
            printf("\n%s", demostrative[i]);
        }
    }

    printf("\nRecuerda poner 0 en el que no sepas, y en grados los de los extremos\n");

    printf("\nValor de:");
    printf("\na: ");
    scanf("%f", &a);
    printf("\n");

    printf("\nValor de:");
    printf("\nb: ");
    scanf("%f", &b);
    printf("\n");

    recompletar();
    if (c == 0)
    {
        printf("\nValor de:");
        printf("\nc: ");
        scanf("%f", &c);
        printf("\n");
    }
    recompletar();

    if (alpha == 0)
    {
        printf("\nValor de:");
        printf("\nalpha: ");
        scanf("%f", &alpha);
        alpha = de_grados_a_rad(alpha);
        printf("\n");
    }
    recompletar();
    if (beta == 0)
    {
        printf("\nValor de:");
        printf("\nbeta: ");
        scanf("%f", &beta);
        beta = de_grados_a_rad(beta);
        printf("\n");
    }
    recompletar();

    printf("\n");

    printf("/|\n");

    printf("valor de a= %f\nvalor de b=%f\nHipotenusa=%f", a, b, c);
    printf("\nAlpha= %.5f\nBeta= %.5f\n", de_rad_a_grados(alpha), de_rad_a_grados(beta));

    printf("\n\n Area= %f\n Perimetro= %f", area, perimetro);
}

void recompletar()
{
    for (int i = 0; i < 5; i++)
    {
        triangulo_rectangulo();
    }
}

void triangulo_rectangulo()
{

    if (a != 0 && b != 0 && c == 0)
    {
        c = pow(pow(a, 2) + pow(b, 2), 1 / 2);
    }
    if (c != 0 && b != 0 && a == 0)
    {
        a = pow(pow(b, 2) - pow(c, 2), 1 / 2);
    }
    if (c != 0 && a != 0 && b == 0)
    {
        b = pow(pow(a, 2) - pow(c, 2), 1 / 2);
    }

    if (b != 0 && c != 0 && alpha == 0)
    {
        alpha = asin(b / c);
    }
    if (a != 0 && c != 0 && alpha == 0)
    {
        alpha = acos(a / c);
    }
    if (b != 0 && c != 0 && alpha == 0)
    {
        alpha = atan(b / a);
    }

    if (b != 0 && c != 0 && beta == 0)
    {
        beta = asin(a / c);
    }
    if (a != 0 && c != 0 && beta == 0)
    {
        beta = acos(b / c);
    }
    if (b != 0 && c != 0 && beta == 0)
    {
        beta = atan(a / b);
    }

    if (alpha != 0 && c != 0 && a == 0 && b == 0)
    {
        b = sin(alpha) * c;
        a = cos(alpha) * c;
    }
    if (alpha != 0 && b != 0 && a == 0 && c == 0)
    {
        c = b / sin(alpha);
        a = b / tan(alpha);
    }

    if (beta != 0 && a != 0 && c == 0 && b == 0)
    {
        b = cos(beta) * c;
        c = a / sin(beta);
    }
    if (beta != 0 && b != 0 && a == 0 && c == 0)
    {
        c = b / cos(beta);
        a = tan(beta) * b;
    }

    if (a != 0 && b != 0 && c != 0)
    {
        perimetro = a + b + c;
        area = a * b / 2;
    }
}

float de_rad_a_grados(float valor)
{
    return valor * 180 / M_PI;
}
float de_grados_a_rad(float valor)
{
    return valor * M_PI / 180;
}