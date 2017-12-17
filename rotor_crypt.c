//rotor_crypt.c

#include "enigmalib.h"

char rotor_crypt (char ch, char *rotor_values)
{
    ch += rotor_values [2] - 'A';
    ch = (ch > 'Z') ? ch - 'Z' + 'A' - 1: ch;
    ch = rotor_3 (ch, RIGHT);
    ch -= rotor_values [2] - 'A';
    ch = (ch < 'A') ? ch - 'A' + 'Z' + 1: ch;

    ch += rotor_values [1] - 'A';
    ch = (ch > 'Z') ? ch - 'Z' + 'A' - 1: ch;
    ch = rotor_2 (ch, RIGHT);
    ch -= rotor_values [1] - 'A';
    ch = (ch < 'A') ? ch - 'A' + 'Z' + 1: ch;

    ch += rotor_values [0] - 'A';
    ch = (ch > 'Z') ? ch - 'Z' + 'A' - 1: ch;
    ch = rotor_1 (ch, RIGHT);
    ch -= rotor_values [0] - 'A';
    ch = (ch < 'A') ? ch - 'A' + 'Z' + 1: ch;

    ch = reflector_B (ch);

    ch += rotor_values [0] - 'A';
    ch = (ch > 'Z') ? ch - 'Z' + 'A' - 1: ch;
    ch = rotor_1 (ch, LEFT);
    ch -= rotor_values [0] - 'A';
    ch = (ch < 'A') ? ch - 'A' + 'Z' + 1: ch;

    ch += rotor_values [1] - 'A';
    ch = (ch > 'Z') ? ch - 'Z' + 'A' - 1: ch;
    ch = rotor_2 (ch, LEFT);
    ch -= rotor_values [1] - 'A';
    ch = (ch < 'A') ? ch - 'A' + 'Z' + 1: ch;

    ch += rotor_values [2] - 'A';
    ch = (ch > 'Z') ? ch - 'Z' + 'A' - 1: ch;
    ch = rotor_3 (ch, LEFT);
    ch -= rotor_values [2] - 'A';
    ch = (ch < 'A') ? ch - 'A' + 'Z' + 1: ch;

    return ch;
}
