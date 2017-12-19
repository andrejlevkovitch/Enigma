//init_blokR.c

#include <stdlib.h>
#include "enigmalib.h"

struct blok_R *init_blokR (void)
{
    struct blok_R *blok = NULL;

    blok = malloc (sizeof *blok);

    blok->rotor_1 = init_rotor (STP_MECH_1, PERMUTATION_R1);
    blok->rotor_2 = init_rotor (STP_MECH_2, PERMUTATION_R2);
    blok->rotor_3 = init_rotor (STP_MECH_3, PERMUTATION_R3);

    return blok;
}
