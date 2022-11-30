#include "Materias/incluyendo_todo.h"
#include <stdio.h>

void leer_todo(char *x[], int longo);

/////////////////////////////////////////
//               GLOBALS               //
/////////////////////////////////////////

const char *menu_inicio[] =
{
    "Circuitos","Quimica", "Matematicas"
};

int ir_al;

////////////////////////////////////////
//                MAIN                //
////////////////////////////////////////
void main(int argc, char const *argv[])
{
    printf("\n888888b.   d8b                                              d8b      888          \n888   88b  Y8P                                              Y8P      888          \n888  .88P                                                            888          \n8888888K.  888  .d88b.  88888b.  888  888  .d88b.  88888b.  888  .d88888  .d88b.  \n888   Y88b 888 d8P  Y8b 888  88b 888  888 d8P  Y8b 888  88b 888 d88  888 d88  88b \n888    888 888 88888888 888  888 Y88  88P 88888888 888  888 888 888  888 888  888 \n888   d88P 888 Y8b.     888  888  Y8bd8P  Y8b.     888  888 888 Y88b 888 Y88  88P \n8888888P   888   Y8888  888  888   Y88P     Y8888  888  888 888   Y88888  Y88P  \n\n888\n888                                                                      \n888                                                                      \n 8888b.  888      88888b.d88b.   .d88b.  88888b.  888  888                        \n     88b 888      888  888  88b d8P  Y8b 888  88b 888  888                        \n d888888 888      888  888  888 88888888 888  888 888  888                        \n888  888 888      888  888  888 Y8b.     888  888 Y88b 888                        \n Y888888 888      888  888  888   Y8888  888  888   Y888\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%d - %s\n", i+1, menu_inicio[i]);
    }
    printf("\n\n");

    scanf("%d", &ir_al);

    switch (ir_al)
    {
    case 1:
        printf("\n\n\n\n\n");
        main_circuitos();
        break;
    case 2:
        printf("\n\n\n\n\n");
        main_quimica();
        break;
    case 3:
        printf("\n\n\n\n\n");
        main_maths();
        break;
    default:
        break;
    }
    printf("\nPresione algo para finalizar el programa.\n");
    getch();
    printf("\n\n");
}



///////////////////////////////////////
//                UTIL               //
///////////////////////////////////////