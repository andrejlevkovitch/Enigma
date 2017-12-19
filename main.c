//main.c

#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include "enigmalib.h"

int main (void)
{
    initscr ();

    noecho ();

    signed char ch = 0;
    int y = 0, x = 0;

    char *replace = NULL;

    struct blok_R *rotors_blok = NULL;

    ramka ();

    rotors_blok = init_blokR ();

    inputRV (rotors_blok);

    replace = input_KP ();

    move (STR_TXT, 0);
    while ((ch = toupper (getch ())) != EOF_DOP) {
        if (isupper (ch)) {
            getyx (curscr, y, x);
            rotor_tools (rotors_blok);
            move (y, x);

            ch = kom_panel (ch, replace, IN);
            ch = rotor_crypt (ch, rotors_blok);
            ch = kom_panel (ch, replace, OUT);

            addch (ch);
            refresh ();
        }
    }

    endwin ();

    free_rotor (rotors_blok->rotor_1);
    free_rotor (rotors_blok->rotor_2);
    free_rotor (rotors_blok->rotor_3);
    free (rotors_blok);
    rotors_blok = NULL;

    return EXIT_SUCCESS;
}
