//kom_panel.c

#include <curses.h>
#include "enigmalib.h"

char kom_panel (char ch, char *replace, char kurs)
{
    if (kurs == IN) {
        ch = replace [ch - 'A'];
    }
    else
        if (kurs == OUT)
            for (int i = 0; i < N_LETTERS; ++i) {
                if (replace [i] == ch) {
                    ch = 'A' + i;
                    break;
                }
            }

    return ch;
}
