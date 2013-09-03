#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "polynomial.h"

static Status clear_polynomial_element( void *element )
{
  if( element ) {
    free( ( PolynomialTerm * ) element );
    return true;
  } else {
    return false;
  }
}

void print_polynomial( Polynomial *polynomial )
{
  PolynomialElement *p;
  PolynomialTerm *term;
  int i;

  if( !is_empty_list( polynomial ) ) {
    for( p = get_list_tail( polynomial ), i = 0; p; p = p->previous, i++ ) {
      term = ( PolynomialTerm * ) get_list_node_content( p );
      if( i > 0 ) {
	printf( " %c ", term->coef >= 0 ? '+' : '-' );
      } else if( i == 0 && term->coef < 0 ) {
	printf( "-" );
      }

      printf( "%.2f", ( term->coef >= 0 ) ? term->coef : -( term->coef ) );
      if( term->expn > 1 ) {
	printf( "X^%d", term->expn );
      } else if( term->expn == 1 ) {
	printf( "X" );
      }
    }
  } else {
    printf( "NAN" );
  }
  printf( "\n" );
}

int compare( const void *src, const void *target )
{
  PolynomialTerm *s = ( PolynomialTerm * ) src;
  PolynomialTerm *t = ( PolynomialTerm * ) target;

  if( s->expn < t->expn ) {
    return -1;
  } else if( s->expn == t->expn ) {
    return 0;
  } else {
    return 1;
  }
}

Status locate_polynomial_element( Polynomial *polynomial, PolynomialTerm *e, PolynomialElement **node, int ( * compare )( const void *src, const void * target ) )
{
  PolynomialElement *p;
  bool found = false;

  for( p = get_list_head( polynomial ); p; p = p->next ) {
    if( compare( p->data, e ) == 0 ) {
      found = true;
      break;
    } else if( compare( p->data, e ) == 1 ) {
      break;
    }
  }

  *node = p;
  if( found ) {
    return true;
  } else {
    return false;
  }
}

Polynomial *create_polynomial( int size )
{
  Polynomial *polynomial = NULL;
  PolynomialElement *node, *p;
  PolynomialTerm *term;
  int i;

  init_list( &polynomial );

  for( i = 0; i < size; i++ ) {
    float coef;
    int expn;

    scanf( "%f %d", &coef, &expn );
    term = ( PolynomialTerm * ) malloc( sizeof( PolynomialTerm ) );
    term->coef = coef;
    term->expn = expn;
    
    if( !locate_polynomial_element( polynomial, term, &p, compare ) ) {
      if( make_list_node( &node, term ) ) {
	if( p ) {
	  insert_before_list_node( polynomial, &p, &node );
	} else {
	  append_list_tail( polynomial, &node );
	}
      }
    } else {
      PolynomialTerm *target = ( PolynomialTerm * ) get_list_node_content( p );
      target->coef += term->coef;
      clear_polynomial_element( term );
    }
  }

  if( !is_empty_list( polynomial ) ) {
    return polynomial;
  } else {
    destroy_list( &polynomial );
    return NULL;
  }
}

void destroy_polynomial( Polynomial **polynomial )
{
  if( !polynomial || !*polynomial ) {
    return;
  }

  clear_list( *polynomial, clear_polynomial_element );
  destroy_list( polynomial );
}

long polynomial_size( Polynomial *polynomial )
{
  return list_size( polynomial );
}

Polynomial *add_polynomial( Polynomial *pa, Polynomial *pb )
{
  Polynomial *polynomial = NULL;
  PolynomialElement *node, *p, *q;
  PolynomialTerm *ta, *tb, *term;

  init_list( &polynomial );

  for( p = get_list_head( pa ), q = get_list_head( pb ); p && q; ) {
    ta = ( PolynomialTerm * ) get_list_node_content( p );
    tb = ( PolynomialTerm * ) get_list_node_content( q );

    term = ( PolynomialTerm * ) malloc( sizeof( PolynomialTerm ) );
    assert( term );
    if( ta->expn < tb->expn ) {
      term->expn = ta->expn;
      term->coef = ta->coef;
      if( make_list_node( &node, term ) ) {
	append_list_tail( polynomial, &node );
      }
      p = p->next;
    } else if( ta->expn == tb->expn ) {
      term->expn = ta->expn;
      term->coef = ta->coef + tb->coef;
      if( term->coef - 0 > 0.00001F ) {
	if( make_list_node( &node, term ) ) {
	  append_list_tail( polynomial, &node );
	}
      } else {
	clear_polynomial_element( term );
      }
      p = p->next;
      q = q->next;
    } else {
      term->expn = tb->expn;
      term->coef = tb->coef;
      if( make_list_node( &node, term ) ) {
	append_list_tail( polynomial, &node );
      }
      q = q->next;
    }
  }

  while( p ) {
    ta = ( PolynomialTerm * ) get_list_node_content( p );

    term = ( PolynomialTerm * ) malloc( sizeof( PolynomialTerm ) );
    assert( term );
    term->expn = ta->expn;
    term->coef = ta->coef;
    if( make_list_node( &node, term ) ) {
      append_list_tail( polynomial, &node );
    }

    p = p->next;
  }

  while( q ) {
    tb = ( PolynomialTerm * ) get_list_node_content( q );

    term = ( PolynomialTerm * ) malloc( sizeof( PolynomialTerm ) );
    assert( term );
    term->expn = tb->expn;
    term->coef = tb->coef;
    if( make_list_node( &node, term ) ) {
      append_list_tail( polynomial, &node );
    }

    q = q->next;
  }

  if( !is_empty_list( polynomial ) ) {
    return polynomial;
  } else {
    destroy_list( &polynomial );
    return NULL;
  }
}

static Polynomial *multiply_polynomial_element( Polynomial *p, PolynomialElement *element )
{
  Polynomial *multiply = NULL;
  PolynomialElement *node, *q;
  PolynomialTerm *term, *cur, *factor;

  factor = ( PolynomialTerm * ) get_list_node_content( element );

  init_list( &multiply );

  for( q = get_list_head( p ); q; q = q->next ) {
    cur = ( PolynomialTerm * ) get_list_node_content( q );

    term = ( PolynomialTerm * ) malloc( sizeof( PolynomialTerm ) );
    assert( term );
    term->expn = cur->expn + factor->expn;
    term->coef = cur->coef * factor->coef;
    if( make_list_node( &node, term ) ) {
      append_list_tail( multiply, &node );
    }
  }

  if( !is_empty_list( multiply ) ) {
    return multiply;
  } else {
    destroy_list( &multiply );
    return NULL;
  }
}

Polynomial *multiply_polynomial( Polynomial *pa, Polynomial *pb )
{
  Polynomial *sum = NULL, *temp;
  PolynomialElement *p;

  init_list( &sum );

  for( p = get_list_head( pa ); p; p = p->next ) {
    Polynomial *multiply = multiply_polynomial_element( pb, p );
    if( is_empty_list( sum ) ) {
      destroy_polynomial( &sum );
      sum = multiply;
    } else {
      temp = sum;
      sum = add_polynomial( temp, multiply );
      destroy_polynomial( &temp );
      destroy_polynomial( &multiply );
    } 
  }

  if( !is_empty_list( sum ) ) {
    return sum;
  } else {
    destroy_list( &sum );
    return NULL;
  }
}
