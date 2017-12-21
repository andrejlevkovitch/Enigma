#ifdef linux
    #include <curses.h>
#else
    #include <conio.h>
#endif

int mygetch (void)
{
    return (getch ());
}
