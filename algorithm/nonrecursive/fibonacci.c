#include "fibonacci.h"

/*
 * fibonacci函数 非递归实现
 */
long fibonacci( long number )
{
  long result;

  if( number <= 1 ) {
    result = 1;
  } else {
    long ppre = 1, pre = 1;
    for( long i = 2; i <= number; i++ ) {
      result = ppre + pre;
      ppre = pre;
      pre = result;
    }
  }

  return result;
}
