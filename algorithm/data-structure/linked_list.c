#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "linked_list.h"

/*
 * 构造一个空的线性表
 */
void init_list( LinkedList *list )
{
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

/*
 * 销毁线性表
 */
void destroy_list( LinkedList *list, void (*clear)(void *) )
{
  clear_list( list, clear );
  free( list );
  list = NULL;
}

/*
 * 重置线性表
 *
 * list    待重置的线性列表，已存在
 * clear   销毁节点数据的函数，用户自己编写
 */
void clear_list( LinkedList *list, void (*clear)(void *) )
{
  ListNode *p, *t;

  p = list->head;
  while( p ) {
    t = p->next;
    if( clear ) {
      clear( p->data );
    }
    free( p );
    p = t;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

/*
 * 初始条件：线性表list已存在
 *
 * 若list为空表，返回TRUE，否则返回FALSE
 */
bool is_empty_list( LinkedList *list )
{
  return ( list->head == NULL );
}

/*
 * 返回线性表中元素的个数
 */
long list_length( LinkedList *list )
{
  return list->size;
}

/*
 * 获取线性表中某位置的数据
 */
void * get_list_element( LinkedList *list, long index )
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
 * 搜索线性表中第一个与key满足compare的数据元素的位序
 */
long locate_list_element( LinkedList *list, void *key, int (*compare)(const void *, const void *) )
{
  ListNode *p;
  long index = 0;

  p = list->head;
  while( p ) {
    // 找到，返回找到的数据元素的位序
    if( !compare( p->data, key ) ) {
      index = index;
      break;
    }
    p = p->next;
    index++;
  }

  return index;
}

/*
 * 搜索线性表中前驱节点
 */
void * get_previous_element( LinkedList *list, long location )
{
  ListNode *previous, *current;

  if( location <= 0 || location > list_size( list ) ) {
    return NULL;
  }

  previous = current = NULL;
  for( current = list->head; location > 0; current = current->next ) {
    previous = current;
  }

  if( previous != NULL ) {
    return previous->data;
  } else {
    return NULL;
  }
}

/*
 * 搜索线性表中的后继节点
 */
void * get_next_element( LinkedList *list, long location )
{
  ListNode *current;

  if( location < 0 || location >= list_size( list ) ) {
    return NULL;
  }

  for( current = list->head; location > 0; current = current->next )
    ;

  if( current != NULL && current->next != NULL ) {
    return current->next->data;
  } else {
    return NULL;
  }
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
static void list_insert_head( LinkedList *list, void *data )
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
static void list_insert_tail( LinkedList *list, void *data )
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
 * 插入一个节点
 *
 * 位置index之前，0 <= index <= list_size( list )
 */
void list_insert( LinkedList *list, void *data, long index )
{
  long i = 0;
  ListNode *p, *node;

  // 越界
  if( index < 0 || index > list_size( list ) ) {
    return;
  }

  // 线性表头部插入
  if( index == 0 ) {
    list_insert_head( list, data );
    return;
  }

  // 线性表尾部插入
  if( index == list_size( list ) ) {
    list_insert_tail( list, data );
    return;
  }

  p = list->head;

  while( p && i < index - 1 ) {
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
 * 删除一个节点
 *
 * key     删除关键字
 * compare 比较函数，用户自行编写
 */
void *list_delete( LinkedList *list, long index )
{
  void *data;
  ListNode *p, *t;

  p = list->head;

  // 如果要删除的节点为首节点
  if( index == 0 ) {
    t = p;
    data = p->data;
    list->head = p->next;
    free( t );
    list->size--;
    if( list->size == 0 ) {
      list->tail = NULL;
    }

    return data;
  }

  // 遍历查找符合条件的节点
  //TODO
  
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

