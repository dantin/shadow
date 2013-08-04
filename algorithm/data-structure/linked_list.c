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

