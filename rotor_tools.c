//rotor_tools.c

#include <curses.h>
#include "enigmalib.h"

void rotor_tools (char * rotor_values)
{
    if (rotor_values [1] == STP_MECH_2 - 1 && rotor_values [2] == STP_MECH_3 - 1)
        rotor_values [0] = (rotor_values [0] + 1 > 'Z') ? 'A': rotor_values [0] + 1;

    if (rotor_values [2] == STP_MECH_3 - 1)
        rotor_values [1] = (rotor_values [1] + 1 > 'Z') ? 'A': rotor_values [1] + 1;

    rotor_values [2] = (rotor_values [2] + 1 > 'Z') ? 'A': rotor_values [2] + 1;

    move (STR_RV, 0);

    addch (rotor_values [0]);
    addch (rotor_values [1]);
    addch (rotor_values [2]);

    return;
}
