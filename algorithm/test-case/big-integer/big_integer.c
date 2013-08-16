#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdio.h>

#include "big_integer.h"

static Status clear_big_integer_element( void *elem )
{
  char *element = ( char * ) elem;

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

  char *element = ( char * ) data;
  printf( "%c", *element);
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
  BigIntegerElement *node;

  big_integer = ( BigInteger * ) malloc( sizeof( BigInteger ) );
  assert( big_integer );
  init_list( big_integer );

  // handle heading '-' or '+'
  c = getchar();
  if( c == '-' || c == '+' ) {
    char *digit = ( char * ) malloc( sizeof( char ) );
    *digit = c;
    if( make_list_node( &node, digit ) ) {
      append_list_tail( big_integer, node );
    }
  }

  while( c != EOF ) {
    if( !isdigit( c ) ) {
      break;
    }

    char *digit = ( char * ) malloc( sizeof( char ) );
    *digit = c;
    if( make_list_node( &node, digit ) ) {
      append_list_tail( big_integer, node );
    }
    c = getchar();
  }

  if( !is_empty_list( big_integer ) && !( list_size( big_integer ) == 1 && ( *( ( char * ) get_list_node_content( get_list_head( big_integer ) ) ) == '-' || *( ( char * ) get_list_node_content( get_list_head( big_integer ) ) ) == '+' ) ) ) {
    return big_integer;
  } else {
    free( big_integer );
    return NULL;
  }
}

BigInteger *init_big_integer( int value )
{
  BigInteger *big_integer;
  BigIntegerElement *node;

  big_integer = ( BigInteger * ) malloc( sizeof( BigInteger ) );
  assert( big_integer );

  init_list( big_integer );

  if( value < 0 ) {
    char *digit = ( char * ) malloc( sizeof( char ) );
    *digit = '-';
    if( make_list_node( &node, digit ) ) {
      append_list_tail( big_integer, node );
    }

    value = -value;
  }

  do {
    char *digit = ( char * ) malloc( sizeof( char ) );
    *digit = value % 10 + '0';

    if( make_list_node( &node, digit ) ) {
      append_list_tail( big_integer, node );
    }

    value /= 10;
  } while( value > 0 );

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
    
    i = a ? *( ( char * )get_list_node_content( a ) ) - '0' : 0;
    j = b ? *( ( char * )get_list_node_content( b ) ) - '0' : 0;
    s = i + j + s;
    char *digit = ( char * ) malloc( sizeof( char ) );
    *digit = s % 10 + '0';
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
    char *digit = ( char * ) malloc( sizeof( char ) );
    *digit = s % 10 + '0';
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

static BigInteger *multiply_int( BigInteger *number1, int value )
{
  BigInteger *multiply;
  BigIntegerElement *p;
  int remaining;

  multiply = ( BigInteger * ) malloc( sizeof( BigInteger ) );
  assert( multiply );

  init_list( multiply );
  for( remaining = 0, p = get_list_tail( number1 ); p; p = p->previous ) {
    int i = *( ( char * ) get_list_node_content( p ) ) - '0';
    int t = i * value + remaining;

    char *digit = ( char * ) malloc( sizeof( char ) );
    *digit = t % 10 + '0';
    BigIntegerElement *node;
    if( make_list_node( &node, digit ) ) {
      insert_list_head( multiply, node );
    }
    remaining = t / 10;
  }

  while( remaining ) {
    char *digit =  ( char * ) malloc( sizeof( char ) );
    *digit = remaining % 10 + '0';
    BigIntegerElement *node;
    if( make_list_node( &node, digit ) ) {
      insert_list_head( multiply, node );
    }
    remaining /= 10;
  }

  if( !is_empty_list( multiply ) ) {
    return multiply;
  } else {
    free( multiply );
    return NULL;
  }
}

BigInteger *multiply( BigInteger *number1, BigInteger *number2 )
{
  BigInteger *sum = init_big_integer( 0 );
  BigInteger *temp;
  int scale = 0;
  BigIntegerElement *p;
  for( p = get_list_tail( number2 ), scale = 0; p; p = p->previous, scale++ ) {
    int i = *( ( char * ) get_list_node_content( p ) ) - '0';
    temp = multiply_int( number1, i );
    for( int s = 0; s < scale; s++ ) {
      char *digit = ( char * ) malloc( sizeof( char ) );
      *digit = '0';
      BigIntegerElement *node;
      if( make_list_node( &node, digit ) ) {
	append_list_tail( temp, node );
      }
    }

    BigInteger *result = add( sum, temp );
    destroy_big_integer( &sum );
    destroy_big_integer( &temp );
    sum = result;
  }

  if( !is_empty_list( sum ) ) {
    return sum;
  } else {
    destroy_big_integer( &sum );
    return NULL;
  }
}
