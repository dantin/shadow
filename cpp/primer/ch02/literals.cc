#include <iostream>

int main( void )
{
  std::cout << "Hello World!";
  std::cout << "";
  std::cout << "\nCC\toptions\tfile.[cC]\n";

  std::cout << "a really, really long string literal "
    "that spans two lines" << std::endl;

  std::cout << 'M' << " " << '\115' << " " << '\x4d' << std::endl;

  unsigned long long bigVal = -1ULL;
  std::cout << bigVal << std::endl;

  return 0;
}
