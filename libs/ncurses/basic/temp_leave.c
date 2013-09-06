#include <ncurses.h>

int main( void )
{
  initscr();                   // start CURSES mode
  noecho();

  printw( "Hello world!\n" );  // print message
  refresh();                   // print it on the real screen
  getch();

  def_prog_mode();             // save the TTY mode
  endwin();                    // end CURSES mmode temporarily

  system( "/bin/sh" );         // back to cooked mode
  reset_prog_mode();           // return to previous TTY mode
  refresh();                   // restore the screen content
  getch();

  printw( "Another String\n" );// print more
  refresh();                   // show on the real screen
  getch();
  endwin();                    // end CURSES mode

  return 0;
}
