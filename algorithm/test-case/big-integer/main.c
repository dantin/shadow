#include <stdio.h>
#include <stdlib.h>

#include "big_integer.h"

int main( void )
{
  BigInteger *number1, *number2;

  printf( "输入正整数A: " );
  number1 = read_big_integer();
  print_big_integer( number1 );
  printf( "输入正整数B: " );
  number2 = read_big_integer();
  print_big_integer( number2 );

  printf( "A + B = " );
  BigInteger *sum = add( number1, number2 );
  print_big_integer( sum );

  printf( "A * B = " );
  BigInteger *multi = multiply( number1, number2 );
  print_big_integer( multi );

  printf( "| A | = " );
  BigInteger *abs = absolute( number1 );
  print_big_integer( abs );

  destroy_big_integer( &number1 );
  destroy_big_integer( &number2 );
  destroy_big_integer( &sum );
  destroy_big_integer( &multi );
  destroy_big_integer( &abs );
  
  return 0;
}
