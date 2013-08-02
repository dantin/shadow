#include <stdio.h>
#include <stdlib.h>

#include "fibonacci.h"

int main( void )
{
  for( long i = 0; i <= 20; i++ ) {
    printf( "fibonacci(%ld) = %ld\n", i, fibonacci( i ) );
  }

  return 0;
}
