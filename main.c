//main.c

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include "enigmalib.h"

int main (void)
{
    initscr ();

    noecho ();

    signed char ch = 0;
    char *rotor_values = NULL;
    int y = 0, x = 0;

    ramka ();
    rotor_values = inputRV ();

    move (STR_TXT, 0);
    while ((ch = toupper (getch ())) != EOF_DOP) {
        if (isupper (ch)) {
            getyx (curscr, y, x);
            rotor_tools (rotor_values);
            move (y, x);

            ch = rotor_crypt (ch, rotor_values);

            addch (ch);
            refresh ();
        }
    }

    endwin ();

    free (rotor_values);
    rotor_values = NULL;

    return EXIT_SUCCESS;
}
