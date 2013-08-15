#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "doubly_linked_list.h"

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
  printf( "%d", *element);
  return true;
}

/*
 * 打印列表内容
 */
void print( DoublyLinkedList *list )
{
  if( !is_empty_list( list ) ) {
    list_traverse( list, print_element );
  } else {
    printf( "NAN" );
  }
  printf( "\n" );
}

DoublyLinkedList *read_big_integer( void )
{
  int c;
  DoublyLinkedList *big_integer;
  
  printf( "Input big integer: " );
  big_integer = ( DoublyLinkedList * ) malloc( sizeof( DoublyLinkedList ) );
  init_list( big_integer );
  while( ( c = getchar() ) != '\n' ) {
    if( isdigit( c ) ) {
      int *digit = ( int * ) malloc( sizeof( int ) );
      *digit = c - '0';
      DoublyLinkedListNode *node;
      if( make_list_node( &node, digit ) ) {
	append_list_tail( big_integer, node );
      }
    }
  }

  if( !is_empty_list( big_integer ) ) {
    return big_integer;
  } else {
    return NULL;
  }
}

void destroy_big_integer( DoublyLinkedList **list )
{
  clear_list( *list, clear );
  free( *list );
  *list = NULL;
}

DoublyLinkedList *add( DoublyLinkedList *number1, DoublyLinkedList *number2 )
{
  DoublyLinkedListNode *a, *b;
  DoublyLinkedList *sum;
  int s;

  sum = ( DoublyLinkedList * ) malloc( sizeof( DoublyLinkedList ) );
  init_list( sum );
  for( s = 0, a = get_list_tail( number1 ), b = get_list_tail( number2 ); a || b; ) {
    int i, j;
    
    i = a ? * ( ( int * )get_list_node_content( a ) ) : 0;
    j = b ? * ( ( int * )get_list_node_content( b ) ) : 0;
    s = i + j + s;
    int *digit = ( int * ) malloc( sizeof( int ) );
    *digit = s % 10;
    DoublyLinkedListNode *node;
    if( make_list_node( &node, digit ) ) {
      insert_list_head( sum, node );
    }
    s = s / 10;
    if( a ) {
      a = a->previous;
    }
    if( b ) {
      b = b->previous;
    }
  }

  while( s ) {
    int *digit = ( int * ) malloc( sizeof( int ) );
    *digit = s % 10;
    DoublyLinkedListNode *node;
    if( make_list_node( &node, digit ) ) {
      insert_list_head( sum, node );
    }
    s = s / 10;
  }

  destroy_big_integer( &number1 );
  destroy_big_integer( &number2 );

  if( !is_empty_list( sum ) ) {
    return sum;
  } else {
    return NULL;
  }
}

int main( void )
{
  DoublyLinkedList *number1, *number2, *number3;

  number1 = read_big_integer();
  print( number1 );
  number2 = read_big_integer();
  print( number2 );

  number3 = add( number1, number2 );
  print( number3 );

  destroy_big_integer( &number3 );
  
  return 0;
}
