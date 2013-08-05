#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

typedef struct ElementNode {
  int intVal;
} Element;

void print_element( void *data ) {
  Element *elem = ( Element * ) data;
  printf( "{int: %d} ", elem->intVal);
}

void print( LinkedList *list )
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
  LinkedList list;
  Element array[10];
  Element *target;

  init_list( &list );

  print( &list );

  for( int i = 0; i < 10; i++ ) {
    array[i].intVal = i;
    printf( "insert element %d at tail\n", array[i].intVal );
    list_insert( &list, &array[i], list_size( &list ) );
    print( &list );
  }

  target = ( Element * ) malloc ( sizeof( Element ) );
  target->intVal = 10;
  printf( "make new element " );
  print_element( target );

  printf( "\ninsert at 8\n" );
  list_insert( &list, target, 8 );
  print( &list );

  printf( "get element at 8\n" );
  print_element( get_list_element( &list, 8 ) );

  printf( "\nget previous element at 8\n" );
  print_element( get_previous_element( &list, 8 ) );

  printf( "\nget next element at 8\n" );
  print_element( get_next_element( &list, 8 ) );

  printf( "\ndelete element at 1\n" );
  list_delete( &list, 1 );
  print( &list );

  return 0;
}
