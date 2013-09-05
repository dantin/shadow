/*
 * print a c file with comment in attribute
 */
#include <ncurses.h>
#include <stdlib.h>

int main( int argc, char *argv[] )
{
  int ch, prev, row, col;
  FILE *fp;
  int x, y;

  if( argc != 2 ) {
    printf( "Usage: %s <a c file name>\n", argv[0] );
    exit( 1 );
  }
  fp = fopen( argv[1], "r" );
  if( fp == NULL ) {
    perror( "Can't open input file" );
    exit( 1 );
  }

  initscr();                           // start CURSES mode
  getmaxyx( stdscr, row, col );        // find boundaries of the screen
  prev = EOF;
  while( ( ch = fgetc( fp ) ) != EOF ) {
    getyx( stdscr, y, x );             // get the current curser position
    if( y == ( row - 1 ) ) {           // end of the screen
      printw( "<- Press Any Key ->" ); // notice
      getch();
      clear();                         // clear the screen
      move( 0, 0 );                    // re-start at the beginning of the screen
    }
    if( prev == '/' && ch == '*' ) {   // meet '/' and '*'
      attron( A_BOLD );                // switch bold on
      getyx( stdscr, y, x );           // get the current curser position
      move( y, x - 1 );                // move back one space
      printw( "%c%c", '/', ch );       // re-print '/' in bold
    } else {
      printw( "%c", ch );
    }
    refresh();
    if( prev == '*' && ch == '/' ) {   // switch bold off
      attroff( A_BOLD );
    }
    prev = ch;
  }
  getch();
  endwin();                            // end CURSES mode
  fclose( fp );

  return 0;
}
