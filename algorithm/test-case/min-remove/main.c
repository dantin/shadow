#include <stdio.h>
#include <stdlib.h>

#include "singly_linked_list.h"

int compare( const void *data, const void *key )
{
  int *value = ( int * ) data;
  int *base = ( int * ) key;

  if( *value == *base ) {
    return 0;
  } else if ( *value > *base ) {
    return 1;
  } else {
    return -1;
  }
}

/*
 * 释放元素空间
 */
Status clear( void *element )
{
  if( element ) {
    free( ( int * ) element );
    return true;
  } else {
    return false;
  }
}

/*
 * 打印元素
 */
Status print_element( void *data ) {
  int *element;

  if( data == NULL ) {
    return false;
  }

  element = ( int * ) data;
  printf( "{%d} ", *element);
  return true;
}

/*
 * 打印列表内容
 */
void print( SinglyLinkedList *list )
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
  SinglyLinkedList *list = NULL;
  SinglyLinkedListNode *node, *min, *p;
  int i;

  // 初始化循环链表
  init_list( &list );

  // 读入输入数据
  while( scanf( "%d", &i ) != EOF ) {
    int *element = ( int * ) malloc( sizeof( int ) );
    *element = i;
    if( make_list_node( &node, element ) ) {
      append_list_tail( list, &node );
    }
  }
  print( list );

  // 从链表中查找最小的节点，删除它
  while( true ) {
    if( is_empty_list( list ) ) {
      break;
    }

    for( p = get_list_head( list ), min = p; p; p = p->next ) {
      // *p < *min
      if( compare( get_list_node_content( p ), get_list_node_content( min ) ) == -1 ) {
	min = p;
      }      
    }

    if( delete_list_node( list, &min ) ) {
      printf( "delete " );
      print_element( get_list_node_content( min ) );
      clear( get_list_node_content( min ) );
      destroy_list_node( &min );
      printf( "\n" );
    }
    print( list );
  }

  clear_list( list, clear );
  destroy_list( &list );

  return 0;
}
