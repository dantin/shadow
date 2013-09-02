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
  int size, step;

  // 获得输入信息
  printf( "输入人数：" );
  scanf( "%d", &size );
  printf( "输入步长：" );
  scanf( "%d", &step );

  // 初始化循环链表
  init_list( &list );

  for( int i = 1; i <= size; i++ ) {
    int *element = ( int * ) malloc( sizeof( int ) );
    *element = i;
    CircularLinkedListNode *node;
    if( make_list_node( &node, element ) ) {
      append_list_tail( list, &node );
    }
  }
  print( list );

  // 循环计算出列号码
  CircularLinkedListNode *p, *t;
  int count, inc;

  count = 0;
  inc = 0;
  p = get_list_head( list );
  while( true ) {
    t = p->next;

    if( count % ( step + inc ) == 0 ) {
      CircularLinkedListNode *pos = p;
      if( delete_list_node( list, &pos ) ) {
	print_element( get_list_node_content( pos ) );
	clear( get_list_node_content( pos ) );
	destroy_list_node( &pos );
      }
      count = 0;
      inc++;
    }
    count++;
    p = t;

    if( is_empty_list( list ) ) {
      break;
    }
  }
  printf( "\n" );

  clear_list( list, clear );
  destroy_list( &list );

  return 0;
}
