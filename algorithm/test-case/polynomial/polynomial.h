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
 * 若有序链表polynomial中存在与*e满足判定函数compare取值为0的函数，则*p指向polynomial中第一个值为*e的节点位置，并返回true
 * 否则，*p指向第一个与*e满足判定函数compare取值>0的元素的位置，并返回false
 */
Status locate_polynomial_element( Polynomial *polynomial, PolynomialTerm *e, PolynomialElement **p, int ( * compare )( const void *src, const void * target) );

/*
 * 读取一个多项式
 */
Polynomial *create_polynomial( int size );

/*
 * 销毁一个多项式
 */
void destroy_polynomial( Polynomial **polynomial );

/*
 * 返回多项式项数
 */
long polynomial_size( Polynomial *polynomial );

/*
 * 依src的指数值<（或=）（或>）target的指数值，分别返回-1, 0, 1
 */
int compare( const void *src, const void *target );

/*
 * 多项式加法
 */
Polynomial *add_polynomial( Polynomial *pa, Polynomial *pb );

/*
 * 多项式乘法
 */
Polynomial *multiply_polynomial( Polynomial *pa, Polynomial *pb );

#endif
