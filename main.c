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
    int y = STR_TXT, x = 0;

    char *replace = NULL;

    struct blok_R *rotors_blok = NULL;

    FILE *fp = NULL;

    if ((fp = fopen ("crypt.dat", "w")) == NULL) {
        printf ("ERROR of open file crypt.dat\n");
        exit (EXIT_FAILURE);
    }

    if (!(rotors_blok = init_blokR ())) {
        ch = EOF_DOP;
        printf ("ERROR of memory!!!\n");
    }

    while (ch != EOF_DOP) {
        if (ch != EOF_DOP) {
            ramka (rotors_blok);

            if (inputRV (rotors_blok))
                ch = EOF_DOP;
        }

        if (ch != EOF_DOP && !(replace = input_KP ()))
            ch = EOF_DOP;

        move (y, x);
        while (ch != EOF_DOP && (ch = toupper (getch ())) != EOF_DOP) {
            if (isupper (ch)) {
                getyx (curscr, y, x);
                rotor_tools (rotors_blok);
                move (y, x);

                ch = kom_panel (ch, replace, IN);
                ch = rotor_crypt (ch, rotors_blok);
                ch = kom_panel (ch, replace, OUT);

                addch (ch);
                putc (ch, fp);
                refresh ();
            }
            else
                if (ch == '\n') {
                    y++;
                    x = 0;
                    putc (ch, fp);
                    break;
                }
        }
    }

    if (fclose (fp) != 0) {
        printf ("ERROR of exit from file crypt.dat\n");
        exit (EXIT_FAILURE);
    }


    endwin ();

    free (replace);
    replace = NULL;
    free_rotor (rotors_blok->rotor_1);
    free_rotor (rotors_blok->rotor_2);
    free_rotor (rotors_blok->rotor_3);
    free_rotor (rotors_blok->reflektor_B);
    free (rotors_blok);
    rotors_blok = NULL;

    return EXIT_SUCCESS;
}
