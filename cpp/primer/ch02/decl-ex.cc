#include <iostream>

int main( void )
{
  int a = 0;
  decltype( a ) c = a;
  decltype( ( a ) ) d = a;

  ++c;
  std::cout << "a: " << a << " c: " << c << " d: " << d << std::endl;
  ++d;
  std::cout << "a: " << a << " c: " << c << " d: " << d << std::endl;

  int A = 0, B = 0;
  decltype( ( A ) ) C = A;
  decltype( A = B ) D = A;
  ++C;
  std::cout << "A: " << A << " C: " << C << " D: " << D << std::endl;
  ++D;
  std::cout << "A: " << A << " C: " << C << " D: " << D << std::endl;

  return 0;
}
