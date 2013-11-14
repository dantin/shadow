#include <iostream>
#include <string>

int main( void )
{
  int v1( 1024 );
  int v2{ 1024 };
  int v3 = 1024;
  int v4 = { 1024 };

  std::string titleA = "C++ Primer, 5th Ed.";
  std::string titleB =( "C++ Primer, 5th Ed." );
  std::string all_nines( 10, '9' );

  return 0;
}
