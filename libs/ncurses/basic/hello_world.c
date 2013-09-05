#include <ncurses.h>

int main( void )
{
  initscr();                     // init CURSES mode
  printw( "Hello, world!" );     // print 'hello, world!' string
  refresh();                     // print it on the real screen
  getch();                       // wait for user input
  endwin();                      // end CURSES mode

  return 0;
}
