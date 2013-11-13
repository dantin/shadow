#include <iostream>

int main( void )
{
  unsigned u = 10, u2 = 42;
  std::cout << u2 - u << std::endl;
  std::cout << u - u2 << std::endl;

  int i = 10, i2 = 42;
  std::cout << i2 - i << std::endl;
  std::cout << i - i2 << std::endl;

  u = 42;
  i = 10;
  std::cout << i - u << std::endl;
  std::cout << u - i << std::endl;

  u = 10;
  i = -42;
  std::cout << i + i << std::endl;
  std::cout << u + i << std::endl;

  i = 10;
  std::cout << "good" << std::endl;
  while( i >= 0 ) {
    std::cout << i << std::endl;
    --i;
  }

  for( i = 10; i >= 0; --i ) {
    std::cout << i << std::endl;
  }

  for( unsigned u = 0; u <= 10; ++u ) {
    std::cout << u << std::endl;
  }

  /*
   * for( unsigned u = 10; u >= 0; --u ) {
   *     std::cout << u << std::endl;
   * }
   */
  u = 11;
  while( u > 0 ) {
    --u;
    std::cout << u << std::endl;
  }

  u = 10;
  i = -42;
  if( i < u ) {
    std::cout << i << std::endl;
  } else {
    std::cout << u << std::endl;
  }

  u = 42; u2 = 10;
  std::cout << u - u2 << std::endl;
  std::cout << u2 - u << std::endl;

  return 0;
}
