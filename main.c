#include "Materias/incluyendo_todo.h"
#include <stdio.h>

void leer_todo(char *x[], int longo);

/////////////////////////////////////////
//               GLOBALS               //
/////////////////////////////////////////

const char *menu_inicio[] =
{
    "Circuitos","Quimica", "Matematicas","Fisica"
};

int ir_al;

////////////////////////////////////////
//                MAIN                //
////////////////////////////////////////
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
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
        printf(" Esperando ");
        break;
    case 4:
        printf(" Esperando ");
        break;
    default:
        break;
    }
    
    printf("\n\n");
    return 0;
}



///////////////////////////////////////
//                UTIL               //
///////////////////////////////////////