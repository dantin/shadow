#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#include "big_integer.h"

static Status clear_big_integer_element( void *elem )
{
  int *element = ( int * ) elem;

  if( element ) {
    free( element );
    return true;
  } else {
    return false;
  }
}

static Status print_big_integer_element( void *data ) {
  if( data == NULL ) {
    return false;
  }

  int *element = ( int * ) data;
  printf( "%d", *element);
  return true;
}

void print_big_integer( BigInteger *big_integer )
{
  if( !is_empty_list( big_integer ) ) {
    list_traverse( big_integer, print_big_integer_element );
  } else {
    printf( "NAN" );
  }
  printf( "\n" );
}

BigInteger *read_big_integer( void )
{
  int c;
  BigInteger *big_integer;
  
  printf( "Input big integer: " );
  big_integer = ( BigInteger * ) malloc( sizeof( BigInteger ) );
  init_list( big_integer );
  while( ( c = getchar() ) != EOF ) {
    if( !isdigit( c ) ) {
      break;
    }

    int *digit = ( int * ) malloc( sizeof( int ) );
    *digit = c - '0';
    BigIntegerElement *node;
    if( make_list_node( &node, digit ) ) {
      append_list_tail( big_integer, node );
    }
  }

  if( !is_empty_list( big_integer ) ) {
    return big_integer;
  } else {
    free( big_integer );
    return NULL;
  }
}

void destroy_big_integer( BigInteger **big_integer )
{
  clear_list( *big_integer, clear_big_integer_element );
  free( *big_integer );
  *big_integer = NULL;
}

BigInteger *add( BigInteger *number1, BigInteger *number2 )
{
  BigIntegerElement *a, *b;
  BigInteger *sum;
  int s;

  sum = ( BigInteger * ) malloc( sizeof( BigInteger ) );
  init_list( sum );
  for( s = 0, a = get_list_tail( number1 ), b = get_list_tail( number2 ); a || b; ) {
    int i, j;
    
    i = a ? * ( ( int * )get_list_node_content( a ) ) : 0;
    j = b ? * ( ( int * )get_list_node_content( b ) ) : 0;
    s = i + j + s;
    int *digit = ( int * ) malloc( sizeof( int ) );
    *digit = s % 10;
    BigIntegerElement *node;
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
    BigIntegerElement *node;
    if( make_list_node( &node, digit ) ) {
      insert_list_head( sum, node );
    }
    s = s / 10;
  }

  if( !is_empty_list( sum ) ) {
    return sum;
  } else {
    free( sum );
    return NULL;
  }
}
