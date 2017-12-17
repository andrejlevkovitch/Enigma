//ramka.c

#include <curses.h>
#include "enigmalib.h"

void ramka (void)
{
    mvprintw (STR_RV - 1, 0, "Input values of rotors (%i)\n", N_ROTORS);
    mvprintw (STR_TXT - 1, 0, "Input text\n");
    refresh ();

    return;
}
