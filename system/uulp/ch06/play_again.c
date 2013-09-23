#include <stdio.h>
#include <termios.h>

#define QUESTION "Do you want another transaction"

void set_cr_noecho_mode( void );
void tty_mode( int );
int get_response( char * );

int main( void )
{
  int response;

  tty_mode( 0 );
  set_cr_noecho_mode();
  response = get_response( QUESTION );
  tty_mode( 1 );

  return response;
}

int get_response( char *question )
{
  printf( " %s(y/n)?", question );
  while( 1 ) {
    switch( getchar() ) {
    case 'y':
    case 'Y':
      return 0;
    case 'n':
    case 'N':
    case EOF:
      return 1;
    }
  }
}

void set_cr_noecho_mode( void )
{
  struct termios ttystate;

  tcgetattr( 0, &ttystate );
  ttystate.c_lflag    &= ~ICANON;
  ttystate.c_lflag    &= ~ECHO;
  ttystate.c_cc[VMIN] = 1;
  tcsetattr( 0, TCSANOW, &ttystate );
}

void tty_mode( int how )
{
  static struct termios original_mode;

  if( how == 0 ) {
    tcgetattr( 0, &original_mode );
  } else {
    tcsetattr( 0, TCSANOW, &original_mode );
  }
}
