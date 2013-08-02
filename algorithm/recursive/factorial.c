#include "factorial.h"

/*
 * 阶乘 递归方式实现
 */
long factorial( long num )
{
  if( num <= 0) {
    return 1;
  } else {
    return num * factorial( num - 1 );
  }
}
