#include <stdlib.h>
#include <assert.h>

#include "linked_list.h"

/*
 * 构造一个空的线性表
 *
 * list  目标线性表指针
 */
void init_list( LinkedList *list )
{
  assert( list != NULL );

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

/*
 * 销毁线性表，调用后list不能再被使用
 *
 * list   目标线性表指针
 * clear  清理函数，用户提供
 */
void destroy_list( LinkedList *list, void (*clear)(void *) )
{
  clear_list( list, clear );
  free( list );
  list = NULL;
}

/*
 * 重置线性表，将线性表重置为空表
 *
 * list 目标线性表指针
 * clear 清理函数，用户提供
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
 * 判断线性表是否为空表
 *
 * 空表返回TRUE
 * 否则返回FALSE
 *
 * list 目标线性表指针
 */
bool is_empty_list( LinkedList *list )
{
  return ( list->head == NULL && list->tail == NULL && list->size == 0 );
}

/*
 * 线性表大小
 *
 * 返回线性表中元素个数
 *
 * list 目标线性表指针
 */
long list_size( LinkedList *list )
{
  return list->size;
}

/*
 * 获取线性表中某位置的数据
 *
 * 返回该位置的元素，若找不到，返回空
 *
 * list 目标线性表指针
 * i    元素下标, 定义域为 [0, list_size( list )]
 */
void * get_list_element( LinkedList *list, long i )
{
  ListNode *p;

  assert( i >= 0 );

  p = list->head;
  for( p = list->head; p && i-- > 0; p = p->next )
    ;

  if( p ) {
    return p->data;
  }

  return NULL;
}

/*
 * 搜索线性表中与key满足compare关系的的第一个数据元素位置
 *
 * 返回与key满足compare关系的第一个元素的位置
 * 找不到返回-1
 *
 * list 目标线性表指针
 * key 目标元素
 * compare 函数指针，定义目标元素和数据元素之间关系
 */
long locate_list_element( LinkedList *list, void *key, int (*compare)(const void *, const void *) )
{
  ListNode *p;
  long i = 0;
  long result = -1;

  p = list->head;
  while( p ) {
    // 找到，返回找到的数据元素的位序
    if( compare && !compare( p->data, key ) ) {
      result = i;
      break;
    }
    p = p->next;
    i++;
  }

  return result;
}

/*
 * 搜索线性表中前驱节点
 *
 * 返回前驱节点数据
 * 无前驱节点返回空
 *
 * list 目标线性表指针
 * i 元素下标，定义域为 [1, list_size( list )]
 */
void * get_previous_element( LinkedList *list, long i )
{
  ListNode *prev, *curr;

  assert( i > 0 );

  for( prev = NULL, curr = list->head; curr && i-- > 0; curr = curr->next ) {
    prev = curr;
  }

  if( curr && prev ) {
    return prev->data;
  } else {
    return NULL;
  }
}

/*
 * 搜索线性表中的后继节点
 *
 * 返回后继结点数据
 * 无后继结点返回空
 *
 * list 目标线性表指针
 * location 元素下标，定义域为[0, list_size( list ) - 1 ]
 */
void * get_next_element( LinkedList *list, long i )
{
  ListNode *curr;

  assert( i >= 0 );

  for( curr = list->head; curr && i-- > 0; curr = curr->next )
    ;

  if( curr && curr->next ) {
    return curr->next->data;
  } else {
    return NULL;
  }
}
/*
 * 把用户数据打包成一个线性表节点
 *
 *   返回线性表节点
 *
 * data  用户数据
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
 * 在线性表头部插入用户数据
 *
 * list  目标线性表指针
 * data  用户数据
 */
static void list_insert_head( LinkedList *list, void *data )
{
  ListNode *node = make_node( data );

  // 当前线性表为空
  if( list->head == NULL ) {
    list->head = node;
    list->tail = node;
  } else { // 当前线性表不为空
    node->next = list->head;
    list->head = node;
  }
  list->size++;
}

/*
 * 在线性表尾部插入用户数据
 *
 * list  目标线性表指针
 * data  用户数据
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
 * 在index前插入一个节点
 *
 * list 目标线性表指针
 * data 元素数据指针
 * index 元素下标，定义域为[0, list_size( list )]
 */
void list_insert( LinkedList *list, void *data, long i )
{
  ListNode *p, *node;

  // 线性表头部插入
  if( i == 0 ) {
    list_insert_head( list, data );
    return;
  }

  // 线性表尾部插入
  if( i == list_size( list ) ) {
    list_insert_tail( list, data );
    return;
  }

  // 线性表中部插入
  for( i--, p = list->head; p && i-- > 0; p = p->next )
    ;

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
 * 返回删除节点数据
 * 若未找到待删除节点，返回空
 *
 * list 目标线性表指针
 * index 待删除节点下标，定义域为[0, list_size( list ) - 1]
 */
void *list_delete( LinkedList *list, long i )
{
  void *data;
  ListNode *p, *t;

  p = list->head;

  // 如果要删除的节点为首节点
  if( i == 0 ) {
    data = p->data;
    list->head = p->next;
    free( p );
    list->size--;
    if( list->size == 0 ) {
      list->tail = NULL;
    }

    return data;
  }

  // 遍历查找目标节点
  while( p && i-- > 0 ) {
    t = p;
    p = p->next;
  }

  if( p ) {
    data = p->data;
    t->next = p->next;
    free( p );
    list->size--;
    if( t->next == NULL ) {
      list->tail = t;
    }
    return data;
  }
  
  return NULL;
}

/*
 * 链表遍历
 *
 * list 目标线性表指针
 * handle 函数句柄，对线性表中的每一个元素做相应的操作
 */
void list_traverse( LinkedList *list, void (*handle)(void *) )
{
  ListNode *p;

  for( p = list->head; p ; p = p->next ) {
    if( handle ) {
      handle( p->data );
    }
  }
}

