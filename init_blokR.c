//init_blokR.c

#include <stdlib.h>
#include "enigmalib.h"

struct blok_R *init_blokR (void)
{
    struct blok_R *blok = NULL;

    if (!(blok = malloc (sizeof *blok)))
        return NULL;

    blok->rotor_1 = init_rotor (STP_MECH_1, PERMUTATION_R1);
    blok->rotor_2 = init_rotor (STP_MECH_2, PERMUTATION_R2);
    blok->rotor_3 = init_rotor (STP_MECH_3, PERMUTATION_R3);
    blok->reflektor_B = init_rotor ('A', PERMUTATION_RB);

    return blok;
}
