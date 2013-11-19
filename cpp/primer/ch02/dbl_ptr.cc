#include <iostream>

int main( void )
{
  int ival = 1024;
  int *pi = &ival;
  int **ppi = &pi;
  std::cout << "The value of ival\n"
	    << "direct value: " << ival << "\n"
	    << "indirect value: " << *pi << "\n"
	    << "doubly indirect value: " << **ppi
	    << std::endl;

  int i = 2;
  int *p1 = &i;
  *p1 = *p1 * *p1;
  std::cout << "i = " << i << std::endl;

  *p1 *= *p1;
  std::cout << "i = " << i << std::endl;

  return 0;
}
