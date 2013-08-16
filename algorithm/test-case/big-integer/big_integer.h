#ifndef __BIG_INTEGER_H__
#define __BIG_INTEGER_H__

#include "doubly_linked_list.h"

typedef DoublyLinkedList BigInteger;

typedef DoublyLinkedListNode BigIntegerElement;

/*
 * 打印大数内容
 */
void print_big_integer( BigInteger *big_integer );

/*
 * 读取一个大数
 */
BigInteger *read_big_integer( void );

/*
 * 销毁一个大数
 */
void destroy_big_integer( BigInteger **big_integer );

/*
 * 大数相加
 */
BigInteger *add( BigInteger *number1, BigInteger *number2 );

#endif
