//ramka.c

#include <curses.h>
#include "enigmalib.h"

void ramka (struct blok_R *blok)
{
    mvprintw (STR_RV - 1, 0, "Input values of rotors (%i)\n", N_ROTORS);
    mvprintw (STR_RV, 0, "%c%c%c", blok->rotor_1->letter, blok->rotor_2->letter, blok->rotor_3->letter);
    mvprintw (STR_KP - 3, 0, "Input replaces for kom.panel\n");
    for (int i = 0; i < N_LETTERS; ++i) {
        mvprintw (STR_KP - 1, 0, "%s", ALFABETO);
    }
    for (int i = 0; i < N_LETTERS; ++i) {
        mvprintw (STR_KP, 0, "%s", ALFABETO);
    }
    mvprintw (STR_TXT - 1, 0, "Input text\n");

    refresh ();

    return;
}
