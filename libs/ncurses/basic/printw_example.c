#include <ncurses.h>
#include <string.h>

int main( void )
{
  char mesg[] = "Just a string";  // message appeared on the screen
  int row, col;                   // store rows and columns of the screen

  initscr();                      // start CURSES mode

  getmaxyx( stdscr, row, col );   // get rows and columns of the screen
  mvprintw( row / 2, ( col - strlen( mesg ) ) / 2, "%s", mesg ); // print message in the middle
  // print message at bottom
  mvprintw( row - 2, 0, "This screen has %d rows and %d columns\n", row, col );
  printw( "Try resizing your window( if possible ) and then run this program again" );
  refresh();

  getch();
  endwin();

  return 0;
}
