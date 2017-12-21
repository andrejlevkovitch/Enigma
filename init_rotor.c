//init_rotor.c

#include <stdlib.h>
#include "enigmalib.h"

struct rotor *init_rotor (char begin, char *permutations)
{
    struct rotor *value_1 = NULL;
    struct rotor *value_2 = NULL;
    struct rotor *first = NULL;

    char cur_letter = begin;

    value_1 = malloc (sizeof *value_1);
    first = value_1;

    value_1->prev = NULL;

    for (int i = 0; i < N_LETTERS - 1; ++i) {
        value_1->cur_position = value_1->number = i;
        value_1->letter = (cur_letter > 'Z') ? cur_letter = 'A', cur_letter++: cur_letter++;

        value_2 = NULL;
        value_2 = malloc (sizeof *value_2);
        value_1->next = value_2;
        value_2->prev = value_1;
        value_1 = value_2;
    }

    value_1->cur_position = value_1->number = N_LETTERS - 1;
    value_1->letter = cur_letter;
    value_1->next = first;
    first->prev = value_1;
    value_1 = value_2 = first;

    for (int i = 0; i < N_LETTERS; ++i) {
        while (value_2->letter != permutations [i])
            value_2 = value_2->next;
        value_1->output = value_2;
        value_1->output->input = value_1;
        value_1 = value_1->next;
    }

    return first;
}
