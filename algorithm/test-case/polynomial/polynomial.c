#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

#include "polynomial.h"

static Status clear_polynomial_element( void *element )
{
  PolynomialTerm *term = ( PolynomialTerm * ) element;

  if( term ) {
    free( term );
    return true;
  } else {
    return false;
  }
}

static Status print_polynomial_element( void *data ) {
  if( data == NULL ) {
    return false;
  }

  PolynomialTerm *term = ( PolynomialTerm * ) data;
  printf( " %c %fx^%d", term->coef >= 0 ? '+' : '-', term->coef, term->expn);
  return true;
}

void print_polynomial( Polynomial *polynomial )
{
  if( !is_empty_list( polynomial ) ) {
    list_traverse( polynomial, print_polynomial_element );
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

Status locate_polynomial_element( Polynomial *polynomial, PolynomialTerm *e, PolynomialElement **node, int ( * compare )( const void *src, const void * target) )
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
  Polynomial *polynomial;
  PolynomialElement *node;
  int i;

  polynomial = ( Polynomial * ) malloc( sizeof( Polynomial ) );
  assert( polynomial );
  init_list( polynomial );

  for( i = 0; i < size; i++ ) {
    float coef;
    int expn;
    PolynomialElement *p;

    scanf( "%f %d", &coef, &expn );
    PolynomialTerm *term = ( PolynomialTerm * ) malloc( sizeof( PolynomialTerm ) );
    term->coef = coef;
    term->expn = expn;
    
    if( !locate_polynomial_element( polynomial, term, &p, compare ) ) {
      if( make_list_node( &node, term ) ) {
	if( p ) {
	  insert_before_list_node( polynomial, &p, node );
	} else {
	  append_list_tail( polynomial, node );
	}
      }
    } else {
      PolynomialTerm *target = ( PolynomialTerm * ) p->data;
      target->coef += term->coef;
      free( term );
    }
  }

  if( !is_empty_list( polynomial ) ) {
    return polynomial;
  } else {
    free( polynomial );
    return NULL;
  }
}

void destroy_polynomial( Polynomial **polynomial )
{
  if( !( *polynomial ) ) {
    return;
  }

  clear_list( *polynomial, clear_polynomial_element );
  free( *polynomial );
  *polynomial = NULL;
}

long polynomial_size( Polynomial *polynomial )
{
  return list_size( polynomial );
}

Polynomial *add_polynomial( Polynomial *pa, Polynomial *pb )
{
  Polynomial *polynomial;
  PolynomialElement *node, *p, *q;
  PolynomialTerm *ta, *tb, *term;

  polynomial = ( Polynomial * ) malloc( sizeof( Polynomial ) );
  assert( polynomial );
  init_list( polynomial );

  for( p = get_list_head( pa ), q = get_list_head( pb ); p && q; ) {
    ta = ( PolynomialTerm * ) get_list_node_content( p );
    tb = ( PolynomialTerm * ) get_list_node_content( q );

    term = ( PolynomialTerm * ) malloc( sizeof( PolynomialTerm ) );
    assert( term );
    if( ta->expn < tb->expn ) {
      term->expn = ta->expn;
      term->coef = ta->coef;
      if( make_list_node( &node, term ) ) {
	append_list_tail( polynomial, node );
      }
      p = p->next;
    } else if( ta->expn == tb->expn ) {
      term->expn = ta->expn;
      term->coef = ta->coef + tb->coef;
      if( term->coef - 0 > 0.00001F ) {
	if( make_list_node( &node, term ) ) {
	  append_list_tail( polynomial, node );
	}
      } else {
	free( term );
      }
      p = p->next;
      q = q->next;
    } else {
      term->expn = tb->expn;
      term->coef = tb->coef;
      if( make_list_node( &node, term ) ) {
	append_list_tail( polynomial, node );
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
      append_list_tail( polynomial, node );
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
      append_list_tail( polynomial, node );
    }

    q = q->next;
  }

  if( !is_empty_list( polynomial ) ) {
    return polynomial;
  } else {
    free( polynomial );
    return NULL;
  }
}
