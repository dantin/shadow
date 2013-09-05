#include <ncurses.h>

int main( void )
{
  int ch;

  initscr();               // start CURSES mode
  raw();                   // line buffering disabled
  keypad( stdscr, TRUE );  // get F1, F2, etc...
  noecho();                // don't echo() while we do getch()

  printw( "Type any character to see it in bold\n" );

  ch = getch();

  if( ch == KEY_F( 12 ) ) {
    printw( "F12 key pressed" );
  } else {
    printw( "The pressed key is " );
    attron( A_BOLD );
    printw( "%c", ch );
    attroff( A_BOLD );
  }
  refresh();        // print on the real screen

  getch();          // wait for user input
  endwin();         // end CURSES mode

  return 0;
}
