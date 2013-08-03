#include "ackerman.h"

/*
 * ackerman函数 递归实现
 */
long ackerman( long n, long m )
{
  long result;

  if( n == 1 && m == 0 ) {
    result = 2;
  } else if( m == 0 ) {
    result = n + 2;
  } else if( n == 0 ) {
    result = 1;
  } else {
    result = ackerman( ackerman( n - 1, m ), m - 1 );
  }

  return result;
}
