#include <stdio.h>
#include <stdlib.h>

#include "singly_linked_list.h"

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

Status clear( void *elem )
{
  Element *element = ( Element * ) elem;

  if( element ) {
    free( element );
    return true;
  } else {
    return false;
  }
}

Status print_element( void *data ) {
  if( data == NULL ) {
    return false;
  }

  Element *elem = ( Element * ) data;
  printf( "{int: %d} ", elem->intVal);
  return true;
}

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
  SinglyLinkedList list;

  printf( "构造一个新的线性表\n" );
  init_list( &list );
  print( &list );

  printf( "在表头部增加新节点\n" );
  Element *element = ( Element * ) malloc( sizeof( Element ) );
  element->intVal = 1;
  SinglyLinkedListNode *node;
  if( make_list_node( &node, element ) ) {
    insert_list_head( &list, node );
  }
  print( &list );

  clear_list( &list, clear );

  print( &list );

  return 0;
}
