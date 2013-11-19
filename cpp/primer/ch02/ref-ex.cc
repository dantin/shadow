#include <iostream>

int main( void )
{
  int i = 0, &ri = i;
  std::cout << i << " " << ri << std::endl;

  i = 5;
  std::cout << i << " " << ri << std::endl;

  ri = 10;
  std::cout << i << " " << ri << std::endl;

  return 0;
}
