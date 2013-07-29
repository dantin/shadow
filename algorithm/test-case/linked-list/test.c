#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

typedef struct ElementNode {
  int intVal;
} Element;

void print_element( void *data ) {
  Element *elem = ( Element * ) data;
  printf( "int: %d\n", elem->intVal);
}

void print( LinkedList *list )
{
  if( !is_empty( list ) ) {
    list_traverse( list, print_element );
  } else {
    printf( " The list is empty.\n" );
  }
}

int main( void )
{
  LinkedList list;

  list_init( &list );

  Element e1 = { 10 };
  Element e2 = { 20 };
  Element e3 = { 30 };

  list_insert( &list, &e1 );
  list_insert( &list, &e2 );
  list_insert( &list, &e3 );
  print( &list );

  return 0;
}
