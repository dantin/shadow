#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utmplib.h"

#define SHOWHOST

void show_info( struct utmp * );
void show_time( time_t );

int main( void )
{
  struct utmp *utbufp;

  if( utmp_open( UTMP_FILE ) == -1 ) {
    perror( UTMP_FILE );
    exit( 1 );
  }

  while( ( utbufp = utmp_next() ) != ( ( struct utmp * ) NULL ) ) {
    show_info( utbufp );
  }

  utmp_close();
  return 0;
}

void show_info( struct utmp *utbufp )
{
  if( utbufp->ut_type != USER_PROCESS ) {
    return;
  }

  printf( "%-8.8s", utbufp->ut_name );
  printf( " " );
  printf( "%-8.8s", utbufp->ut_line );
  printf( " " );
  show_time( utbufp->ut_time );
  printf( " " );
#ifdef SHOWHOST
  if( utbufp->ut_host[0] != '\0' ) {
    printf( "( %s )", utbufp->ut_host );
  }
#endif
  printf( "\n" );
}

void show_time( long timeval )
{
  char *cp = ctime( &timeval );

  printf( "%12.12s", cp );
}
