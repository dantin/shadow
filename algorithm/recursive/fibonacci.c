#include "fibonacci.h"

/*
 * fibonacci函数 递归实现
 */
long fibonacci( long number )
{
  if( number <= 1 ) {
    return 1;
  } else {
    return fibonacci( number - 1 ) + fibonacci( number - 2 );
  }
}
