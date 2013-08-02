#include "factorial.h"

/*
 * 阶乘 非递归方式实现
 */
long factorial( long number )
{
  long result = 1;

  for( long i = 1; i <= number; i++ ) {
    result *= i;
  }

  return result;
}
