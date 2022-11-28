/* Programa: Menú calculadora de números enteros */
#include <conio.h>
#include <stdio.h>
// Segundo intento Calculadora pero ahora con MEnu!!!
int main()
{
    char opcion;
    int n1, n2;

    // Menu de inicio//
    do
    {
        printf("\n   >>> WELCOME MY BROTHER <<<");
        printf("\n\n   1. Sumar dos numeros.", 163);
        printf("\n   2. Restar dos numeros.", 163);
        printf("\n   3. Multiplicar dos numeros.", 163);
        printf("\n   4. Dividir dos numeros.", 163);
        printf("\n   5. Salir.\n");

        // aqui hago la opcion para el sujeto//
        do
        {
            printf("\n   Introduzca opcion (1-5): ", 162);
            fflush(stdin);
            scanf("%c", &opcion);

        } while (opcion < '1' || opcion > '5');

        switch (opcion)
        {
            // suma//
        case '1':
            printf("\n   Introduzca primer sumando: ");
            scanf("%d", &n1);
            printf("\n   Introduzca segundo sumando: ");
            scanf("%d", &n2);
            printf("\n   %d + %d = %d\n", n1, n2, n1 + n2);
            break;

            // resta//
        case '2':
            printf("\n   Introduzca minuendo: ");
            scanf("%d", &n1);
            printf("\n   Introduzca sustraendo: ");
            scanf("%d", &n2);
            printf("\n   %d - %d = %d\n", n1, n2, n1 - n2);
            break;

            // MULTIPLICACION//
        case '3':
            printf("\n   Introduzca primer operando: ");
            scanf("%d", &n1);
            printf("\n   Introduzca segundo operando: ");
            scanf("%d", &n2);
            printf("\n   %d * %d = %d\n", n1, n2, n1 * n2);
            break;

            // divicion//
        case '4':
            printf("\n   Introduzca dividendo: ");
            scanf("%d", &n1);
            printf("\n   Introduzca divisor: ");
            scanf("%d", &n2);
            if (n2 != 0)
                printf("\n   %d div %d = %d ( Resto = %d )\n", n1, n2, n1 / n2, n1 % n2);
            else
                printf("\n   ERROR: LOCO NO SE PUEDE DIVIDIR ENTRE CEROS POR DIOS!! .\n");
        }

    } while (opcion != '5');

    return 0;
}