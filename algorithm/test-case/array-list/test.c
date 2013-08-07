#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"

typedef struct ElementNode {
  int intVal;
} Element;

int equal( const void *value1, const void *value2 )
{
  Element *value = ( Element * ) value1;
  Element *base = ( Element * ) value2;

  if( value->intVal == base->intVal ) {
    return 0;
  } else if( value->intVal < base->intVal ) {
    return -1;
  } else {
    return 1;
  }
}

void clear( void *elem )
{
  Element *element = ( Element * ) elem;

  if( element ) {
    free( element );
  }
}

void print_element( void *data ) {
  Element *elem = ( Element * ) data;
  printf( "{int: %d} ", elem->intVal);
}

void print( ArrayList *list )
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
  ArrayList list;
  Element *target;

  printf( "构造一个新的线性表\n" );
  init_list( &list );
  print( &list );

  printf( "在表尾部增加新节点\n" );
  for( int i = 0; i < 10; i++ ) {
    Element *element = ( Element * ) malloc( sizeof( Element ) );
    element->intVal = i;
    list_insert( &list, element, list_size( &list ) );
  }
  print( &list );

  target = ( Element * )malloc ( sizeof( Element ) );
  target->intVal = 10;
  printf( "新建节点 " );
  print_element( target );

  printf( "\n在表中部增加新节点，位置 8\n" );
  list_insert( &list, target, 8 );
  print( &list );

  printf( "在表头部增加新节点\n" );
  target = ( Element * ) malloc( sizeof( Element ) );
  target->intVal = 11;
  list_insert( &list, target, 0 );
  print( &list );

  printf( "取头节点\n" );
  print_element( get_list_element( &list, 0 ) );

  printf( "\n取尾节点\n" );
  print_element( get_list_element( &list, list_size( &list ) - 1 ) );

  printf( "\n取中间节点，位置：8\n" );
  print_element( get_list_element( &list, 8 ) );

  printf( "\n取前一个节点，基位置：8\n" );
  print_element( get_previous_element( &list, 8 ) );

  printf( "\n取前一个节点，基位置：1\n" );
  print_element( get_previous_element( &list, 1 ) );

  printf( "\n取前一个节点，基位置：表尾\n");
  print_element( get_previous_element( &list, list_size( &list ) - 1 ) );

  printf( "\n取下一个节点，基位置：8\n" );
  print_element( get_next_element( &list, 8 ) );

  printf( "\n取下一个节点，基位置：表头\n" );
  print_element( get_next_element( &list, 0 ) );

  printf( "\n取下一个节点，基位置：-2\n" );
  print_element( get_next_element( &list, list_size( &list ) - 2 ) );

  printf( "\n删除中间节点，位置：1\n" );
  list_delete( &list, 1 );
  print( &list );

  printf( "删除表尾节点\n" );
  list_delete( &list, list_size( &list ) - 1 );
  print( &list );

  printf( "删除表头节点\n" );
  list_delete( &list, 0 );
  print( &list );

  printf( "搜索线性表中值为10的元素\n" );
  target->intVal = 10;
  print_element( get_list_element( &list, locate_list_element( &list, target, equal ) ) );

  printf( "\n重置线性表\n" );
  clear_list( &list, clear );

  print( &list );

  clear( target );

  return 0;
}
