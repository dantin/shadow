#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "circular_linked_list.h"

/*
 * 释放元素空间
 */
Status clear( void *elem )
{
  int *element = ( int * ) elem;

  if( element ) {
    free( element );
    return true;
  } else {
    return false;
  }
}

/*
 * 打印元素
 */
Status print_element( void *data ) {
  if( data == NULL ) {
    return false;
  }

  int *element = ( int * ) data;
  printf( "{%d} ", *element);
  return true;
}

/*
 * 打印列表内容
 */
void print( CircularLinkedList *list )
{
  printf( "[ " );
  if( !is_empty_list( list ) ) {
    list_traverse( list, print_element );
  } else {
    printf( "empty list " );
  }
  printf( "]\n" );
}

int main( void )
{
  CircularLinkedList *list = NULL;
  int size, step, count;
  CircularLinkedListNode *node, *p, *t;
  int *element;

  // 获得输入信息
  printf( "输入人数：" );
  scanf( "%d", &size );
  printf( "输入步长：" );
  scanf( "%d", &step );

  // 初始化循环链表
  init_list( &list );

  for( int i = 1; i <= size; i++ ) {
    element = ( int * ) malloc( sizeof( int ) );
    *element = i;
    if( make_list_node( &node, element ) ) {
      append_list_tail( list, &node );
    }
  }
  print( list );

  // 循环计算出列号码
  count = 0;

  p = get_list_head( list );
  while( true ) {
    t = p->next;

    if( count % step == 0 ) {
      node = p;
      if( delete_list_node( list, &node ) ) {
	element = ( int * ) get_list_node_content( node );
	print_element( element );
	clear( element );
	destroy_list_node( &node );
      }
      count = 0; // 重新计数
      step++;
    }
    count++;

    if( is_empty_list( list ) ) {
      break;
    } else {
      p = t;
    }
  }
  printf( "\n" );

  clear_list( list, clear );
  destroy_list( &list );

  return 0;
}
