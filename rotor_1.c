//rotor_1.c

#include <stdio.h>
#include <stdlib.h>
#include "enigmalib.h"

char rotor_1 (char ch, char direction)
{
    char rotor_right_side []  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char rotor_left_side []   = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    char *in = NULL;
    char *out = NULL;

    if (direction == RIGHT) {
        in = rotor_right_side;
        out = rotor_left_side;
    }
    else {
        in = rotor_left_side;
        out = rotor_right_side;
    }

    for (int i = 0; i < N_LETTERS; ++i) {
        if (in [i] == ch) {
            ch = out [i];
            break;
        }
    }

    return ch;
}
