#include <stdio.h>

int main( void )
{
  printpathto( get_inode( "." ) );
  putchar( '\n' );

  return 0;
}
