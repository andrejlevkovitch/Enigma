//rotor_crypt.c

#include <stdlib.h>
#include "enigmalib.h"

char rotor_crypt (char ch, struct blok_R *blok)
{
    struct rotor *r = NULL;
    int n = ch - 'A';

    for (int i = 0; i < N_ROTORS; ++i) {
        switch (i) {
            case 0:
                r = blok->rotor_3;
                break;
            case 1:
                r = blok->rotor_2;
                break;
            case 2:
                r = blok->rotor_1;
                break;
        }

        for (int j = 0; j < n; ++j) {
            r = r->next;
        }
        n = r->output->cur_position;
    }

    for (int i = N_ROTORS; i >= 0; --i) {
        switch (i) {
            case 0:
                r = blok->rotor_3;
                break;
            case 1:
                r = blok->rotor_2;
                break;
            case 2:
                r = blok->rotor_1;
                break;
            case 3:
                r = blok->reflektor_B;
        }

        for (int j = 0; j < n; ++j) {
            r = r->next;
        }
        n = r->input->cur_position;
    }

    return n + 'A';
}
