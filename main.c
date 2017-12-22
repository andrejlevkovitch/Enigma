//main.c

#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include "enigmalib.h"

int main (void)
{
    initscr ();

    noecho ();

    int ch = 0;
    int y = STR_TXT, x = 0;

    char *replace = NULL;

    struct blok_R *rotors_blok = NULL;

    FILE *fp = NULL;

    if ((fp = fopen ("crypt.dat", "a")) == NULL) {
        printf ("ERROR of open file crypt.dat\n");
        exit (EXIT_FAILURE);
    }

    if (!(rotors_blok = init_blokR ())) {
        ch = EOF_DOP;
        printf ("ERROR of memory!!!\n");
    }

    if (ch != EOF_DOP)
        ramka (rotors_blok);

    if (ch != EOF_DOP && !(replace = input_KP ()))
        ch = EOF_DOP;

    while (ch != EOF_DOP) {
            if (inputRV (rotors_blok))
                ch = EOF_DOP;
        move (y, x);
        refresh ();
        while (ch != EOF_DOP && (ch = toupper (mygetch ())) != EOF_DOP) {
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
                if (ch == ENTER) {
                    y++;
                    x = 0;
                    putc (ch, fp);
                    break;
                }
        }
    }

    putc ('\n', fp);

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
