//rotor_crypt.c

#include <stdlib.h>
#include "enigmalib.h"

char rotor_crypt (char ch, struct blok_R *blok)
{
    struct rotor *r = NULL;
    struct rotor *r_b = NULL;
    int n = 0;

    for (int i = 0; i < N_ROTORS; ++i) {
        switch (i) {
            case 0:
                r_b = r = blok->rotor_3;
                break;
            case 1:
                r_b = r = blok->rotor_2;
                break;
            case 2:
                r_b = r = blok->rotor_1;
                break;
        }

        n = ch - 'A';
        for (int j = 0; j < n; ++j) {
            r = r->next;
        }
        ch = r->output->letter;
        ch -= (r_b->letter - 'A');
        ch = (ch < 'A') ? ch - 'A' + 'Z' + 1: ch;
    }

    ch = reflector_B (ch);

    for (int i = N_ROTORS - 1; i >= 0; --i) {
        switch (i) {
            case 0:
                r_b = r = blok->rotor_3;
                break;
            case 1:
                r_b = r = blok->rotor_2;
                break;
            case 2:
                r_b = r = blok->rotor_1;
                break;
        }

        n = ch - 'A';
        for (int j = 0; j < n; ++j) {
            r = r->next;
        }
        ch = r->input->letter;
        ch -= (r_b->letter - 'A');
        ch = (ch < 'A') ? ch - 'A' + 'Z' + 1: ch;
    }

    return ch;
}
