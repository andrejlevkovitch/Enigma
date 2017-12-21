//rotor_cikle.c

#include "enigmalib.h"

void rotor_cikle (struct rotor *r, char kurs)
{
    int temp = r->cur_position;

    if (kurs == DOWN)
        for (int i = 0; i < N_LETTERS - 1; ++i) {
            r->cur_position = r->next->cur_position;
            r = r->next;
        }
    else
        if (kurs == UP)
            for (int i = 0; i < N_LETTERS - 1; ++i) {
                r->cur_position = r->prev->cur_position;
                r = r->prev;
            }

    r->cur_position = temp;

    return;
}
