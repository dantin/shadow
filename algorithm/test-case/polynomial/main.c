#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"

int main( void )
{
  Polynomial *polya;
  int size;

  printf( "输入多项式项数: " );
  scanf( "%d", &size );
  polya = create_polynomial( size );

  print_polynomial( polya );

  destroy_polynomial( &polya );
  
  return 0;
}
