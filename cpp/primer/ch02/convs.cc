#include <iostream>

int main( void )
{
  int i = 42;

  std::cout << i << std::endl;
  if( i ) {
    i = 0;
  }
  std::cout << i << std::endl;
  
  bool b = 42;
  std::cout << b << std::endl;

  int j = b;
  std::cout << j << std::endl;

  double pi = 3.14;
  std::cout << pi << std::endl;

  j = pi;
  std::cout << j << std::endl;

  unsigned char c = -1;
  i = c;
  std::cout << i << std::endl;

  return 0;
}
