#include <stdio.h>
#include <stdlib.h>

#include "factorial.h"

int main( void )
{
  for( long i = 0; i < 10; i++ ) {
    printf( "%ld! = %ld\n", i, factorial( i ) );
  }

  return 0;
}
