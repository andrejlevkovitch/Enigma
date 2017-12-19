//input_rotor_values.c

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include "enigmalib.h"

void inputRV (struct blok_R *blok)
{
    char RV = 0;

    move (STR_RV, 0);

    for (int i = 0; i < N_ROTORS; ++i) {
        RV = toupper (getch ());
        if (isupper (RV)) {
            switch (i) {
                case 0:
                    while (blok->rotor_1->letter != RV)
                        blok->rotor_1 = blok->rotor_1->next;
                    addch (blok->rotor_1->letter);
                    break;
                case 1:
                    while (blok->rotor_2->letter != RV)
                        blok->rotor_2 = blok->rotor_2->next;
                    addch (blok->rotor_2->letter);
                    break;
                case 2:
                    while (blok->rotor_3->letter != RV)
                        blok->rotor_3 = blok->rotor_3->next;
                    addch (blok->rotor_3->letter);
                    break;
            }
        }
        else
            i--;
        refresh ();
    }

    return;
}
