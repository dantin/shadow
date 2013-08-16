#include <stdio.h>
#include <stdlib.h>

#include "big_integer.h"

int main( void )
{
  BigInteger *number1, *number2;

  number1 = read_big_integer();
  print_big_integer( number1 );
  number2 = read_big_integer();
  print_big_integer( number2 );

  BigInteger *sum = add( number1, number2 );
  print_big_integer( sum );

  BigInteger *multi = multiply( number1, number2 );
  print_big_integer( multi );

  destroy_big_integer( &number1 );
  destroy_big_integer( &number2 );
  destroy_big_integer( &sum );
  destroy_big_integer( &multi );
  
  return 0;
}
