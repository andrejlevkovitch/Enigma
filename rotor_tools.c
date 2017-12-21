//rotor_tools.c

#include <curses.h>
#include "enigmalib.h"

void rotor_tools (struct blok_R *blok)
{
    if (blok->rotor_3->number == N_LETTERS - 1 && blok->rotor_2->number == N_LETTERS - 1) {
        blok->rotor_1 =  blok->rotor_1->next;
        rotor_cikle (blok->rotor_1, UP);
    }

    if (blok->rotor_3->number == N_LETTERS - 1) {
        blok->rotor_2 = blok->rotor_2->next;
        rotor_cikle (blok->rotor_2, UP);
    }

    blok->rotor_3 = blok->rotor_3->next;
    rotor_cikle (blok->rotor_3, UP);

    move (STR_RV, 0);

    addch (blok->rotor_1->letter);
    addch (blok->rotor_2->letter);
    addch (blok->rotor_3->letter);

    return;
}
