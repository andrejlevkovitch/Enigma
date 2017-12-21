#ifdef linux
    #include <curses.h>
#else
    #include <conio.h>
#endif

char mygetch (void)
{
    return (getch ());
}
