//input_rotor_values.c

#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include "enigmalib.h"

int inputRV (struct blok_R *blok)
{
    char ch = 0;
    int x = 0;

    move (STR_RV, x);

    while ((ch = getch ()) != '\n') {
        if (ch == 27) {
            if (getch () == 91) {
                switch (getch ()) {
                    case RIGHT:
                        if (x == N_ROTORS - 1)
                            x = 0;
                        else
                            x++;
                        move (STR_RV, x);
                        break;
                    case LEFT:
                        if (x == 0)
                            x = N_ROTORS - 1;
                        else
                            x--;
                        move (STR_RV, x);
                        break;
                    case UP:
                        switch (x) {
                            case 0:
                                blok->rotor_1 = blok->rotor_1->next;
                                addch (blok->rotor_1->letter);
                                move (STR_RV, x);
                                break;
                            case 1:
                                blok->rotor_2 = blok->rotor_2->next;
                                addch (blok->rotor_2->letter);
                                move (STR_RV, x);
                                break;
                            case 2:
                                blok->rotor_3 = blok->rotor_3->next;
                                addch (blok->rotor_3->letter);
                                move (STR_RV, x);
                                break;
                        }
                        break;
                    case DOWN:
                        switch (x) {
                            case 0:
                                blok->rotor_1 = blok->rotor_1->prev;
                                addch (blok->rotor_1->letter);
                                move (STR_RV, x);
                                break;
                            case 1:
                                blok->rotor_2 = blok->rotor_2->prev;
                                addch (blok->rotor_2->letter);
                                move (STR_RV, x);
                                break;
                            case 2:
                                blok->rotor_3 = blok->rotor_3->prev;
                                addch (blok->rotor_3->letter);
                                move (STR_RV, x);
                                break;
                        }
                        break;
                }
                refresh ();
            }
        }
        else
            if (ch == EOF_DOP)
                return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
