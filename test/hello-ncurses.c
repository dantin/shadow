#include <ncurses.h>

/*
 * gcc <program file> -lncurses
 */
int main( void )
{
  initscr();
  printw( "Hello world!" );
  refresh();
  getch();
  endwin();

  return 0;
}
