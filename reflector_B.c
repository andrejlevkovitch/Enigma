//reflector_B.c

#include "enigmalib.h"

char reflector_B (char ch)
{
    char in []  = "AYBRCUDHEQFSGLIPJXKNMOTZVW";
    char out [] = "YARBUCHDQESFLGPIXJNKOMZTWV";

    for (int i = 0; i < N_LETTERS; ++i) {
        if (in [i] == ch) {
            ch = out [i];
            break;
        }
    }

    return ch;
}
