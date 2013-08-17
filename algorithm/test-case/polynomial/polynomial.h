#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "doubly_linked_list.h"

typedef DoublyLinkedList Polynomial;

typedef DoublyLinkedListNode PolynomialElement;

typedef struct {
  float coef;
  int expn;
} PolynomialTerm;

/*
 * 打印多项式内容
 */
void print_polynomial( Polynomial *polynomial );

/*
 * 读取一个多项式
 */
Polynomial *create_polynomial( int size );

/*
 * 销毁一个多项式
 */
void destroy_polynomial( Polynomial **polynomial );

#endif
