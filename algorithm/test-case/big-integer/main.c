#include <stdio.h>
#include <stdlib.h>

#include "big_integer.h"

int main( void )
{
  BigInteger *number1, *number2, *number3;

  number1 = read_big_integer();
  print_big_integer( number1 );
  number2 = read_big_integer();
  print_big_integer( number2 );

  number3 = add( number1, number2 );
  print_big_integer( number3 );

  destroy_big_integer( &number1 );
  destroy_big_integer( &number2 );
  destroy_big_integer( &number3 );
  
  return 0;
}
