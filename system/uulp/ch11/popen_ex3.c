#include <stdio.h>

int main( void )
{
  FILE *fp;

  fp = popen( "mail david", "w" );
  fprintf( fp, "Error with backup!!\n" );

  pclose( fp );

  return 0;
}
