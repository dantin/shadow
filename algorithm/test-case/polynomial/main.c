#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"

int main( void )
{
  Polynomial *pa, *pb, *sum = NULL;
  int size;

  printf( "输入多项式项数: " );
  scanf( "%d", &size );
  pa = create_polynomial( size );
  print_polynomial( pa );

  printf( "输入多项式项数: " );
  scanf( "%d", &size );
  pb = create_polynomial( size );
  print_polynomial( pb );

  sum = add_polynomial( pa, pb );
  print_polynomial( sum );

  destroy_polynomial( &sum );
  destroy_polynomial( &pa );
  destroy_polynomial( &pb );

  return 0;
}
