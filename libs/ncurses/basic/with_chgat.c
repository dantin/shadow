#include <ncurses.h>

int main( int argc, char *argv[] )
{
  initscr();          // start CURSES mode
  start_color();      // start color functionality

  init_pair( 1, COLOR_CYAN, COLOR_BLACK );
  printw( "A Big string which i didn't care to type fully " );
  /*
   * First two parameters specify the position at which to start
   * Third parameter specify number of characters to update
   *   -1 means till end of line
   * Forth parameter is the normal attribute you wanted to give to the character
   * Fifth parameter is the color index
   *   It is the index given during init_pair(), use 0 if you didn't want color
   * Sixth one is always NULL
   */
  mvchgat( 0, 0, -1, A_BLINK, 1, NULL );
  refresh();

  getch();
  endwin();           // end CURSES mode
  return 0;
}
