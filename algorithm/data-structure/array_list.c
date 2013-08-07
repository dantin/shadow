#include <stdlib.h>
#include <assert.h>

#include "array_list.h"

/*
 * 构造一个空的线性表
 *
 * list   目标线性表指针
 */
void init_list( ArrayList *list )
{
  list->elements = ( ArrayListNode * ) malloc( ARRAY_LIST_INIT_SIZE * sizeof( ArrayListNode ) );
  assert( list->elements );
  list->size = 0;
  list->limit = ARRAY_LIST_INIT_SIZE;
}

/*
 * 销毁线性表，调用后list不能再被使用
 *
 * list   目标线性表指针
 * clear  清理函数，用户提供
 */

void destroy_list( ArrayList *list, void (*clear)(void *) )
{
  clear_list( list, clear );
  free( list->elements );
  list = NULL;
}

/*
 * 重置线性表，将线性表重置为空表
 *
 * list   目标线性表指针
 * clear  清理函数，用户提供
 */
void clear_list( ArrayList *list, void (*clear)(void *) )
{
  for( ArrayListNode *p = list->elements; p < list->elements + list_size( list ); p++ ) {
    if( clear ) {
      clear( p->data );
    }
    p->data = NULL;
  }
  list->size = 0;
  list->limit = ARRAY_LIST_INIT_SIZE;
}

/*
 * 判断线性表是否为空表
 *
 *  空表返回TRUE
 *  否则返回FALSE
 *
 * list   目标线性表指针
 */
bool is_empty_list( ArrayList *list )
{
  return list->size == 0;
}

/*
 * 线性表大小
 *
 *  返回线性表中元素个数
 *
 * list   目标线性表指针
 */
long list_size( ArrayList *list )
{
  return list->size;
}

/*
 * 获取线性表中某位置的数据
 *
 *  返回该位置的元素，若找不到，返回空
 *
 * list   目标线性表指针
 * i      元素下标, 定义域为 [0, list_size( list )]
 */
void * get_list_element( ArrayList *list, long i )
{
  if( i >= 0 && i < list_size( list ) ) {
    return ( list->elements + i )->data;
  } else {
    return NULL;
  }
}

/*
 * 搜索线性表中与key满足compare关系的的第一个数据元素位置
 *
 *  返回与key满足compare关系的第一个元素的位置
 *  找不到返回-1
 *
 * list      目标线性表指针
 * key       目标元素
 * compare   函数指针，定义目标元素和数据元素之间关系
 */
long locate_list_element( ArrayList *list, void *key, int (*compare)(const void *, const void *) )
{
  for( ArrayListNode *p = list->elements; p < list->elements + list_size( list ); p++ ) {
    if( compare && !compare( p->data, key ) ) {
      return p - list->elements;
    }
  }

  return -1;
}

/*
 * 搜索线性表中前驱节点
 *
 *   返回前驱节点数据
 *   无前驱节点返回空
 *
 * list       目标线性表指针
 * location   元素下标, 定义域为 [1, list_size( list )]
 */
void * get_previous_element( ArrayList *list, long location )
{
  return get_list_element( list, --location );
}

/*
 * 搜索线性表中的后继节点
 *
 *   返回后继结点数据
 *   无后继结点返回空
 *
 * list       目标线性表指针
 * location   元素下标，定义域为[0, list_size( list ) - 1 ]
 */
void * get_next_element( ArrayList *list, long location )
{
  return get_list_element( list, ++location );
}

/*
 * 在index前插入一个节点
 *
 * list    目标线性表指针
 * data    元素数据指针
 * index   元素下标，定义域为[0, list_size( list )]
 */
void list_insert( ArrayList *list, void *data, long index )
{
  if( index < 0 || index > list_size( list ) ) {
    return;
  }

  if( list_size( list ) >= list->limit ) {
    ArrayListNode *base = ( ArrayListNode * ) realloc( list->elements, ( list_size( list ) + ARRAY_LIST_INCREMENT ) * sizeof( ArrayListNode ) );
    assert( base );
    list->elements = base;
    list->limit += ARRAY_LIST_INCREMENT;
  }

  ArrayListNode *p, *location = list->elements + index;
  for( p = list->elements + list_size( list ) - 1; p >= location; p-- ) {
    *( p + 1 ) = *p;
  }
  location->data = data;
  ++list->size;
}

/*
 * 删除一个节点
 *
 *   返回删除节点数据
 *   若未找到待删除节点，返回空
 *
 * list   目标线性表指针
 * index  待删除节点下标，定义域为[0, list_size( list ) - 1]
 */
void *list_delete( ArrayList *list, long index )
{
  if( index < 0 || index > list_size( list ) ) {
    return NULL;
  }

  ArrayListNode *p, *q;
  void *result;
  p = list->elements + index;
  result = p->data;
  for( q = list->elements + list_size( list ), ++p; p < q; ++p ) {
    *( p - 1 ) = *p;
  }
  --list->size;

  return result;
}

/*
 * 链表遍历
 *
 * list    目标线性表指针
 * handle  函数句柄，对线性表中的每一个元素做相应的操作
 */
void list_traverse( ArrayList *list, void (*handle)(void *) )
{
  for( long i = 0; i < list_size( list ); i++ ) {
    if( handle ) {
      handle( ( list->elements + i )->data );
    }
  }
}
