//rotor_tools.c

#include <curses.h>
#include "enigmalib.h"

void rotor_tools (struct blok_R *blok)
{
    blok->rotor_1 = (blok->rotor_3->number == N_LETTERS - 1 && blok->rotor_2->number == N_LETTERS - 1) ? blok->rotor_1->next: blok->rotor_1;
    blok->rotor_2 = (blok->rotor_3->number == N_LETTERS - 1) ? blok->rotor_2->next: blok->rotor_2;
    blok->rotor_3 = blok->rotor_3->next;

    move (STR_RV, 0);

    addch (blok->rotor_1->letter);
    addch (blok->rotor_2->letter);
    addch (blok->rotor_3->letter);

    return;
}
