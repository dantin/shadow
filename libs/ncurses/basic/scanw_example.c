#include <ncurses.h>
#include <string.h>

int main( void )
{
  char mesg[] = "Enter a string: "; // message appeared on the screen
  char str[80];
  int row, col;                     // store the rows and columns of screen

  initscr();                        // start CURSES mode
  getmaxyx( stdscr, row, col );     // get rows and columns of the screen
  mvprintw( row / 2, ( col - strlen( mesg ) ) / 2, "%s", mesg );
  getstr( str );
  mvprintw( row - 2, 0, "You Entered: %s", str );
  getch();
  endwin();

  return 0;
}
