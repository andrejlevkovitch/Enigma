//input_rotor_values.c

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include "enigmalib.h"

char *inputRV (void)
{
    char *RV = NULL;

    RV = malloc (N_ROTORS * sizeof *RV);

    move (STR_RV, 0);

    for (int i = 0; i < N_ROTORS; ++i) {
        RV [i] = toupper (getch ());
        if (isupper (RV [i]))
            addch (RV [i]);
        else
            i--;
        refresh ();
    }

    return RV;
}
