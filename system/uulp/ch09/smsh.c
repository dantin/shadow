#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "smsh.h"

#define DFL_PROMPT ">"

void setup( void );

int main( void )
{
  char *cmdline, *prompt, **arglist;
  int result;

  prompt = DFL_PROMPT;
  setup();

  while( ( cmdline = next_cmd( prompt, stdin ) ) != NULL ) {
    if( ( arglist = splitline( cmdline ) ) != NULL ) {
      result = process( arglist );
      freelist( arglist );
    }
    free( cmdline );
  }

  return 0;
}

extern char **environ;
void setup( void )
{
  VLenviron2table( environ );
  signal( SIGINT, SIG_IGN );
  signal( SIGQUIT, SIG_IGN );
}
