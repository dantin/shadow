#include <stdlib.h>
#include <assert.h>

#include "array_list.h"

Status make_list_node( ArrayListNode **target, void *data )
{
  ArrayListNode *node = ( ArrayListNode * ) malloc( sizeof( ArrayListNode ) );

  if( !node ) {
    return false;
  }

  node->data = data;
  *target = node;

  return true;
}

void destroy_list_node( ArrayListNode **node )
{
  free( *node );
  *node = NULL;
}

Status init_list( ArrayList *list )
{
  if( !list ) {
    return false;
  }

  list->elements = ( ArrayListNode * ) malloc( ARRAY_LIST_INIT_SIZE * sizeof( ArrayListNode ) );
  assert( list->elements );
  list->size = 0;
  list->limit = ARRAY_LIST_INIT_SIZE;

  return true;
}

Status clear_list( ArrayList *list, void ( *clear )( void * ) )
{
  Status status = true;
  ArrayListNode *p, *t;

  for( p = list->elements + list->size - 1; p >= list->elements; p-- ) {
    t = p - 1;
    if( clear ) {
      status = clear( p->data );
    }

    if( !status ) {
      break;
    }
    destroy_list_node( &p );
    list->size--;
    p = t;
  }

  if( status ) {
    list->size = 0;
  }

  return status;
}

bool is_empty_list( ArrayList *list )
{
  return list->size == 0;
}

long list_size( ArrayList *list )
{
  return list->size;
}

Status locate_list_node_by_position( ArrayList *list, long index, ArrayListNode **node )
{
  if( index >= 0 && index < list_size( list ) ) {
    *node = list->elements + i ;
    return true;
  } else {
    *node = NULL;
    return false;
  }
}

ArrayListNode *locate_list_node_by_locator( ArrayList *list, void *key, int (*compare)(const void *, const void *) )
{
  ArrayListNode *p;
  for( p = list->elements; p < list->elements + list_size( list ); p++ ) {
    if( compare && !compare( p->data, key ) ) {
      break;
    }
  }

  if( p < list->elements + list_size( list ) ) {
    return p;
  } else {
    return NULL;
  }
}

ArrayListNode *get_previous_node( ArrayList *list, ArrayListNode *pos )
{
  if( pos >= 1 && pos < list->elements + list_size( list ) ) {
    return --pos;
  } else {
    return NULL;
  }
}

ArrayListNode *get_next_node( ArrayList *list, ArrayListNode *pos )
{
  if( pos >= 0 && pos <= list->element + list_size( list ) - 1 ) {
    return ++pos;
  } else {
    return NULL;
  }
}


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

  ArrayListNode *location = list->elements + index;
  for( ArrayListNode *p = list->elements + list_size( list ) - 1; p >= location; p-- ) {
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

  ArrayListNode *p;
  void *result;
  p = list->elements + index;
  result = p->data;
  for( p++; p < list->elements + list_size( list ); p++ ) {
    *( p - 1 ) = *p;
  }
  list->size--;

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
  for( ArrayListNode *p = list->elements; p < list->elements + list_size( list ); p++ ) {
    if( handle ) {
      handle( p->data );
    }
  }
}
