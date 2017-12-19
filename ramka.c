//ramka.c

#include <curses.h>
#include "enigmalib.h"

void ramka (void)
{
    mvprintw (STR_RV - 1, 0, "Input values of rotors (%i)\n", N_ROTORS);
    mvprintw (STR_KP - 3, 0, "Input size of kom.panel\n");
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
