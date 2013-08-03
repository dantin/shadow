#include <stdio.h>
#include <stdlib.h>

#include "ackerman.h"

int main( void )
{
  for( long m = 0; m < 4; m++ ) {
    printf( "m = %ld:\n", m );
    for( long n = 1; n < 5; n++ ) {
      printf( "ackerman( %ld, %ld ) = %ld\n", n, m, ackerman( n, m ) );
    }
    printf( "\n" );
  }

  return 0;
}
