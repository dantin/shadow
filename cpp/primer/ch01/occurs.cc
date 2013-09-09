#include <iostream>

int main( void )
{
  // curr is the number we're counting
  // new values will be store into val
  int curr = 0, val = 0;

  if( std::cin >> curr ) {
    int cnt = 1; // count of current value

    while( std::cin >> val ) {
      if( val == curr ) {
	++cnt;
      } else {
	std::cout << curr << " occurs " << cnt << " times" << std::endl;
	curr = val;
	cnt = 1;
      }
    }
    std::cout << curr << " occurs " << cnt << " times" << std::endl;
  }

  return 0;
}

