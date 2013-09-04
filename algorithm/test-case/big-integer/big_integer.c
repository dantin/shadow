#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdio.h>

#include "big_integer.h"

static Status clear_big_integer_element( void *element )
{
  if( element ) {
    free( ( char * ) element );
    return true;
  } else {
    return false;
  }
}

static Status make_big_integer_element( char **ppc, char ch )
{
  if( ppc == NULL || *ppc == NULL || *!isdigit( ch ) ) {
    return false;
  }

  char *c = ( char * ) malloc( sizeof( char ) );
  assert( c );
  *c = ch;
  *ppc = c;

  return true;
}

static Status print_big_integer_element( void *data ) {
  if( data == NULL ) {
    return false;
  }

  char *element = ( char * ) data;
  printf( "%c", *element );
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
  DoublyLinkedList *numbers = NULL;
  DoublyLinkedListNode *node;
  char *digit;

  BigInteger *big_integer = ( BigInteger * ) malloc( sizeof( BigInteger ) );
  init_list( &numbers );

  // handle heading '-' or '+'
  c = getchar();
  if( c == '-' || c == '+' ) {
    digit = ( char * ) malloc( sizeof( char ) );
    *digit = c;
    if( make_list_node( &node, digit ) ) {
      append_list_tail( big_integer, &node );
    }
  }

  while( c != EOF ) {
    if( !isdigit( c ) ) {
      break;
    }

    digit = ( char * ) malloc( sizeof( char ) );
    *digit = c;
    if( make_list_node( &node, digit ) ) {
      append_list_tail( big_integer, &node );
    }
    c = getchar();
  }

  if( !is_empty_list( big_integer ) && !( list_size( big_integer ) == 1 && ( *( ( char * ) get_list_node_content( get_list_head( big_integer ) ) ) == '-' || *( ( char * ) get_list_node_content( get_list_head( big_integer ) ) ) == '+' ) ) ) {
    return big_integer;
  } else {
    destroy_list( &big_integer );
    return NULL;
  }
}

BigInteger *init_big_integer( int value )
{
  BigInteger *big_integer = NULL;
  BigIntegerElement *node;
  char *digit;

  init_list( &big_integer );

  if( value < 0 ) {
    digit = ( char * ) malloc( sizeof( char ) );
    *digit = '-';
    if( make_list_node( &node, digit ) ) {
      append_list_tail( big_integer, &node );
    }

    value = -value;
  }

  do {
    digit = ( char * ) malloc( sizeof( char ) );
    *digit = value % 10 + '0';

    if( make_list_node( &node, digit ) ) {
      append_list_tail( big_integer, &node );
    }

    value /= 10;
  } while( value > 0 );

  if( !is_empty_list( big_integer ) ) {
    return big_integer;
  } else {
    destroy_list( &big_integer );
    return NULL;
  }
}

void destroy_big_integer( BigInteger **big_integer )
{
  clear_list( *big_integer, clear_big_integer_element );
  destroy_list( big_integer );
}

BigInteger *add( BigInteger *number1, BigInteger *number2 )
{
  BigIntegerElement *a, *b, *node;
  BigInteger *sum = NULL;
  char *digit;
  int s;

  init_list( &sum );
  for( s = 0, a = get_list_tail( number1 ), b = get_list_tail( number2 ); a || b; ) {
    int i, j;
    
    i = a ? *( ( char * )get_list_node_content( a ) ) - '0' : 0;
    j = b ? *( ( char * )get_list_node_content( b ) ) - '0' : 0;
    s = i + j + s;
    digit = ( char * ) malloc( sizeof( char ) );
    *digit = s % 10 + '0';
    
    if( make_list_node( &node, digit ) ) {
      insert_list_head( sum, &node );
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
    digit = ( char * ) malloc( sizeof( char ) );
    *digit = s % 10 + '0';

    if( make_list_node( &node, digit ) ) {
      insert_list_head( sum, &node );
    }
    s = s / 10;
  }

  if( !is_empty_list( sum ) ) {
    return sum;
  } else {
    destroy_list( &sum );
    return NULL;
  }
}

static BigInteger *multiply_int( BigInteger *number1, int value )
{
  BigInteger *multiply = NULL;
  BigIntegerElement *p, *node;
  char *digit;
  int remaining;

  init_list( &multiply );
  for( remaining = 0, p = get_list_tail( number1 ); p; p = p->previous ) {
    int i = *( ( char * ) get_list_node_content( p ) ) - '0';
    int t = i * value + remaining;

    digit = ( char * ) malloc( sizeof( char ) );
    *digit = t % 10 + '0';

    if( make_list_node( &node, digit ) ) {
      insert_list_head( multiply, &node );
    }
    remaining = t / 10;
  }

  while( remaining ) {
    digit =  ( char * ) malloc( sizeof( char ) );
    *digit = remaining % 10 + '0';

    if( make_list_node( &node, digit ) ) {
      insert_list_head( multiply, &node );
    }
    remaining /= 10;
  }

  if( !is_empty_list( multiply ) ) {
    return multiply;
  } else {
    destroy_list( &multiply );
    return NULL;
  }
}

BigInteger *multiply( BigInteger *number1, BigInteger *number2 )
{
  BigInteger *sum = NULL;
  BigInteger *temp;
  int scale = 0;
  BigIntegerElement *p, *node;

  init_list( &sum );

  for( p = get_list_tail( number2 ), scale = 0; p; p = p->previous, scale++ ) {
    int i = *( ( char * ) get_list_node_content( p ) ) - '0';
    temp = multiply_int( number1, i );

    if( is_empty_list( sum ) ) {
      destroy_list( &sum );
      sum = temp;
    } else {
      for( int s = 0; s < scale; s++ ) {
	char *digit = ( char * ) malloc( sizeof( char ) );
	*digit = '0';

	if( make_list_node( &node, digit ) ) {
	  append_list_tail( temp, &node );
	}
      }

      BigInteger *result = add( sum, temp );
      destroy_big_integer( &sum );
      destroy_big_integer( &temp );
      sum = result;
    }
  }

  if( !is_empty_list( sum ) ) {
    return sum;
  } else {
    destroy_big_integer( &sum );
    return NULL;
  }
}

BigInteger *absolute( BigInteger *number )
{
  BigInteger *abs = NULL;
  BigIntegerElement *p, *node;
  char c;

  init_list( &abs );

  for( p = get_list_head( number ); p; p = p->next ) {
    if( isdigit( c = *( ( char * ) get_list_node_content( p ) ) ) ) {
      char *digit = ( char * ) malloc( sizeof( char ) );
      *digit = c;
      if( make_list_node( &node, digit ) ) {
	append_list_tail( abs, &node );
      }
    }
  }

  if( !is_empty_list( abs ) ) {
    return abs;
  } else {
    destroy_big_integer( &abs );
    return NULL;
  }
}
