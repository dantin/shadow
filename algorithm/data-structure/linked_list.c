#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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
 * 插入一个节点，默认采用尾插法
 */
void list_insert( LinkedList *list, void *data )
{
  list_insert_tail( list, data );
}

/*
 * 删除一个节点
 *
 * key     删除关键字
 * compare 比较函数，用户自行编写
 */
void *list_delete( LinkedList *list, void *key, int (*compare)(const void *, const void *) )
{
  void *data;
  ListNode *p, *t;

  p = list->head;

  // 如果要删除的节点为首节点
  if( !compare( p->data, key ) ) {
    t = p;
    data = p->data;
    list->head = p->next;
    free( t );
    list->size--;

    return data;
  }

  // 遍历查找符合条件的节点
  while( p->next != NULL ) {
    // 只删除第一个符合条件的节点
    if( !compare( p->next->data, key ) ) {
      t = p->next;
      if( p->next == list->tail ) {
	list->tail = p;
      }
      p->next = t->next;
      data = t->data;
      free( t );
      list->size--;

      return data;
    }
    p = p->next;
  }

  return NULL;
}

/*
 * 链表遍历
 *
 * list   待遍历的线性列表，已存在
 * handle 节点遍历函数，用户编写
 */
void list_traverse( LinkedList *list, void (*handle)(void *) )
{
  ListNode *p;

  p = list->head;
  while( p ) {
    handle( p->data );
    p = p->next;
  }
}

/*
 * 搜索
 */
void *list_search( LinkedList *list, void *key, int (*compare)(const void *, const void *) )
{
  ListNode *p;

  p = list->head;
  while( p ) {
    // 找到，返回找到的数据
    if( !compare( p->data, key ) ) {
      return p->data;
    }
    p = p->next;
  }

  // 找不到，返回NULL
  return NULL;
}

/*
 * 获取链表某节点的数据
 */
void * get_element( LinkedList *list, long index )
{
  long i = 0;
  ListNode *p;

  p = list->head;
  while( p && i < index ) {
    i++;
    p = p->next;
  }

  if( p ) {
    return p->data;
  }

  return NULL;
}

/*
 * 求长度
 */
long get_length( LinkedList *list )
{
  return list->size;
}

/*
 * 销毁线性表
 *
 * list    待销毁的线性列表，已存在
 * destroy 销毁节点数据的函数，用户自己编写
 */
void list_destroy( LinkedList *list, void (*destroy)(void *) )
{
  ListNode *p, *t;

  p = list->head;
  while( p ) {
    t = p->next;
    if( destroy ) {
      destroy( p->data );
    }
    free( p );
    p = t;
  }

  list->size = 0;
}
