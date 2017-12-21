//rotor_cikle.c

#include "enigmalib.h"

void rotor_cikle (struct rotor *r, char kurs)
{
    int temp = r->cur_value;

    if (kurs == DOWN)
        for (int i = 0; i < N_LETTERS - 1; ++i) {
            r->cur_value = r->next->cur_value;
            r = r->next;
        }
    else
        if (kurs == UP)
            for (int i = 0; i < N_LETTERS - 1; ++i) {
                r->cur_value = r->prev->cur_value;
                r = r->prev;
            }

    r->cur_value = temp;

    return;
}
