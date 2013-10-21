#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main( void )
{
  int fd;
  int newfd;
  char line[100];

  fgets( line, 100, stdin ); printf( "%s", line );
  fgets( line, 100, stdin ); printf( "%s", line );
  fgets( line, 100, stdin ); printf( "%s", line );

  fd = open( "data", O_RDONLY );
  newfd = dup2( fd, 0 );
  if( newfd != 0 ) {
    fprintf( stderr, "Could not duplicated fd to 0\n" );
    exit( 1 );
  }
  close( fd );

  fgets( line, 100, stdin ); printf( "%s", line );
  fgets( line, 100, stdin ); printf( "%s", line );
  fgets( line, 100, stdin ); printf( "%s", line );

  return 0;
}
