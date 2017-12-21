//free_rotor.c

#include <stdlib.h>
#include "enigmalib.h"

int free_rotor (struct rotor *rotor)
{
    struct rotor *help_st = NULL;

    rotor->prev->next = NULL;

    for (int i = 0; i < N_LETTERS; ++i) {
        help_st = rotor;
        rotor = (rotor->next) ? rotor->next: NULL;
        free (help_st);
    }

    help_st = NULL;

    return 0;
}
