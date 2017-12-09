//main.c

#include <stdio.h>
#include <stdlib.h>
#include "enigmalib.h"

#define SIZE 10

int main (void)
{
    printf ("IN\n");

    int mass [SIZE] = {5, 6, 1, 0, 2, 3, 9, 7, 4, 8};

    for (unsigned int i = 0; i < SIZE; ++i) {
        printf ("%i ", mass [i]);
    }
    printf ("\n");

    sortFun (mass, SIZE);

    printf ("OUT\n");

    for (unsigned int i = 0; i < SIZE; ++i) {
        printf ("%i ", mass [i]);
    }
    printf ("\n");

    return EXIT_SUCCESS;
}
