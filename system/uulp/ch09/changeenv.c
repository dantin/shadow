#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main( void )
{
  char *table[3];

  table[0] = "TERM=vt100";
  table[1] = "HOME=/on/the/range";
  table[2] = 0;

  environ = table;

  execlp( "env", "env", NULL );

  return 0;
}
