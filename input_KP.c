//input_KP.c

#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include "enigmalib.h"

char* input_KP (void)
{
    char ch = 0;
    int x = 0;

    char *replace = NULL;

    replace = malloc ((N_LETTERS + 1) * sizeof *replace);
    for (int i = 0; i < N_LETTERS; ++i) {
        replace [i] = i + 'A';
    }
    replace [N_LETTERS] = '\0';

    move (STR_KP, x);

    while ((ch = getch ()) != '\n') {
        if (ch == 27) {
            if (getch () == 91) {
                ch = getch ();
                switch (ch) {
                    case 67:
                        if (x == N_LETTERS - 1)
                            x = 0;
                        else
                            ++x;
                        move (STR_KP, x);
                        break;
                    case 68:
                        if (!x)
                            x = N_LETTERS - 1;
                        else
                            --x;
                        move (STR_KP, x);
                        break;
                }
            }
        }
        else
            if (isalpha (ch)) {
                ch = toupper (ch);
                for (int i = 0; i < N_LETTERS; ++i) {
                    if (replace [i] == ch) {
                        replace [i] = replace [x];
                        break;
                    }
                }
                replace [x] = ch;
                mvprintw (STR_KP, 0, "%s", replace);
                move (STR_KP, x);
                refresh ();
            }
    }

    return replace;
}
