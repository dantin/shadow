#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"

/*
 * 构造一个空的线性表
 */
void list_init( LinkedList *list )
{
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

/*
 * 初始条件：线性表list已存在
 *
 * 若list为空表，返回TRUE，否则返回FALSE
 */
bool is_empty( LinkedList *list )
{
  return ( list->head == NULL );
}

/*
 * 把用户传递来的数据打包为一个链表节点
 */
static ListNode *make_node( void *data )
{
  ListNode *node = (ListNode *) malloc( sizeof( ListNode ) );
  assert( node != NULL );

  node->next = NULL;
  node->data = data;

  return node;
}

/*
 * 头插法
 */
void list_insert_head( LinkedList *list, void *data )
{
  ListNode *node = make_node( data );

  if( list->head == NULL ) {
    // 当前链表为空
    list->head = node;
    list->tail = node;
  } else {
    // 当前链表不为空
    node->next = list->head;
    list->head = node;
  }
  list->size++;
}

/*
 * 尾插法
 */
void list_insert_tail( LinkedList *list, void *data )
{
  ListNode *node = make_node( data );

  if( list->head == NULL ) {
    // 当前链表为空
    list->head = node;
    list->tail = node;
  } else {
    // 当前链表不为空
    list->tail->next = node;
    list->tail = node;
  }
  list->size++;
}

/*
 * 随插法
 */
void list_insert_index( LinkedList *list, void *data, long index )
{
  long i = 1;
  ListNode *p, *node;

  p = list->head;

  while( p && i < index ) {
    p = p->next;
    i++;
  }

  if( p ) {
    node = make_node( data );
    node->next = p->next;
    p->next = node;
    list->size++;
  }
}

/*
 * 初始条件：线性表list已存在
 *
 * 销毁线性表
 */
void list_destroy( LinkedList *list, void (*destroy)(void *) )
{

}
