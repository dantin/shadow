#include "factorial.h"

long factorial( long num )
{
  if( num <= 0) {
    return 1;
  } else {
    return num * factorial( num - 1 );
  }
}
