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
    for (int i = 0; i < 3; i++)
    {
        printf("%d - %s\n", i+1, menu_inicio[i]);
    }
    printf("\n\n");

    scanf("%d", &ir_al);

    switch (ir_al)
    {
    case 1:
        main_circuitos();
        break;
    case 2:
        main_quimica();
        break;
    case 3:
        main_maths();
        break;
    default:
        break;
    }
    
    printf("\n\n");
}



///////////////////////////////////////
//                UTIL               //
///////////////////////////////////////