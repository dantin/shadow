#include <ncurses.h>

WINDOW *create_newwin( int height, int width, int starty, int startx );
void destroy_win( WINDOW *local_win );

int main( int argc, char *argv[] )
{
  WINDOW *my_win;
  int startx, starty, width, height;
  int ch;

  initscr();              // start CURSES mode
  cbreak();               // disable line buffering
  keypad( stdscr, TRUE ); // enable Fx key
  noecho();

  height = 3;
  width = 10;
  starty = ( LINES - height ) / 2;
  startx = ( COLS - width ) / 2;

  printw( "Press F12 to exit" );
  refresh();

  my_win = create_newwin( height, width, starty, startx );

  while( ( ch = getch() ) != KEY_F( 12 ) ) {
    switch( ch ) {
    case KEY_LEFT:
      destroy_win( my_win );
      my_win = create_newwin( height, width, starty, --startx );
      break;
    case KEY_RIGHT:
      destroy_win( my_win );
      my_win = create_newwin( height, width, starty, ++startx );
      break;
    case KEY_UP:
      destroy_win( my_win );
      my_win = create_newwin( height, width, --starty, startx );
      break;
    case KEY_DOWN:
      destroy_win( my_win );
      my_win = create_newwin( height, width, ++starty, startx );
      break;
    }
  }

  endwin();      // end CURSES mode

  return 0;
}

WINDOW *create_newwin( int height, int width, int starty, int startx )
{
  WINDOW *local_win;

  local_win = newwin( height, width, starty, startx );
  box( local_win, 0, 0 );   // 0, 0 gives default characters for vertical and horizontal lines
  wrefresh( local_win );    // show box

  return local_win;
}

void destroy_win( WINDOW *local_win )
{
  /*
   * box( local_win, ' ', ' ' );
   * won't produce the desired result of erasing the window.
   * it'll leave its four corners
   *
   * 1. win: the window on which to operate
   * 2. ls: character used on the left side of the window
   * 3. rs: character used on the right side of the window
   * 4. ts: character used on the top side of the window
   * 5. bs: character used on the bottom side of the window
   * 6. tl: character used on the top left corner of the window
   * 7. tr: character used on the top right corner of the window
   * 8. bl: character used on the bottom left corner of the window
   * 9. br: character used on the bottom right corner of the window
   */
  wborder( local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' );
  wrefresh( local_win );
  delwin( local_win );
}
