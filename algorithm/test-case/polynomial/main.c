#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"

int main( void )
{
  Polynomial *pa, *pb, *sum, *multiply;
  int size;

  printf( "输入多项式项数: " );
  scanf( "%d", &size );
  pa = create_polynomial( size );
  printf( "多项式A: \n" );
  print_polynomial( pa );

  printf( "输入多项式项数: " );
  scanf( "%d", &size );
  pb = create_polynomial( size );
  printf( "多项式B: \n" );
  print_polynomial( pb );

  sum = add_polynomial( pa, pb );
  printf( "A + B = " );
  print_polynomial( sum );

  multiply = multiply_polynomial( pa, pb );
  printf( "A * B = " );
  print_polynomial( multiply );

  destroy_polynomial( &multiply );
  destroy_polynomial( &sum );
  destroy_polynomial( &pa );
  destroy_polynomial( &pb );

  return 0;
}
