//input_KP.c

#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include "enigmalib.h"

char* input_KP (void)
{
    int ch = 0;
    int x = 0;

    char *replace = NULL;

    replace = malloc ((N_LETTERS + 1) * sizeof *replace);
    for (int i = 0; i < N_LETTERS; ++i) {
        replace [i] = i + 'A';
    }
    replace [N_LETTERS] = '\0';

    move (STR_KP, x);
    refresh ();

    while ((ch = mygetch ()) != ENTER) {
        move (STR_KP + 2, 0);
        clrtoeol ();
        if (ch == ESC) {
#ifdef linux
            if (mygetch () == 91) {
#endif
                switch (mygetch ()) {
                    case RIGHT:
                        if (x == N_LETTERS - 1)
                            x = 0;
                        else
                            ++x;
                        move (STR_KP, x);
                        break;
                    case LEFT:
                        if (!x)
                            x = N_LETTERS - 1;
                        else
                            --x;
                        move (STR_KP, x);
                        break;
                }
                refresh ();
#ifdef linux
            }
#endif
        }
        else
            if (isalpha (ch)) {
                ch = toupper (ch);
                for (int i = 0; i < N_LETTERS; ++i) {
                    if (replace [i] == ch) {
                        if ((i + 'A') == ch || (x + 'A') == ch) {
                            replace [i] = replace [x];
                            replace [x] = ch;
                            break;
                        }
                        else
                            mvprintw (STR_KP + 2, 0, "%s", "NO-NO-NOOOO... ITS IMPASSIBLE");
                    }
                }
                mvprintw (STR_KP, 0, "%s", replace);
                move (STR_KP, x);
                refresh ();
            }
            else
                if (ch == EOF_DOP)
                    return NULL;
    }

    return replace;
}
