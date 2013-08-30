#include <stdlib.h>
#include <assert.h>

#include "circular_linked_list.h"

Status make_list_node( CircularLinkedListNode **target, void *data )
{
  CircularLinkedListNode *node = ( CircularLinkedListNode * ) malloc( sizeof( CircularLinkedListNode ) );

  if( !node ) {
    return false;
  }

  node->data = data;
  node->next = NULL;

  *target = node;

  return true;
}

void destroy_list_node( CircularLinkedListNode **node )
{
  free( *node );
  *node = NULL;
}

Status init_list( CircularLinkedList **listp )
{
  if( !listp || *listp ) {
    return false;
  }

  CircularLinkedList *list = ( CircularLinkedList * ) malloc( sizeof( CircularLinkedList ) );
  assert( list );
  *listp = list;

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return true;
}

Status destroy_list( CircularLinkedList **listp )
{
  if( !listp || !*listp ) {
    return false;
  }

  free( *listp );
  *listp = NULL;

  return true;
}

Status clear_list( CircularLinkedList *list, Status ( *clear )( void * ) )
{
  Status status = true;
  CircularLinkedListNode *p, *t;

  p = get_list_head( list );
  while( list->size > 0 ) {
    t = p->next;

    if( clear ) {
      status = clear( p->data );
    }

    if( !status ) {
      break;
    }
    destroy_list_node( &p );
    list->size--;
    p = t;
    list->head = p;
    list->tail->next = p;
  }

  if( status ) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
  }

  return status;
}

bool is_empty_list( CircularLinkedList *list )
{
  return list->size == 0;
}

long list_size( CircularLinkedList *list )
{
  return list->size;
}

Status locate_list_node_by_position( CircularLinkedList *list, long index, CircularLinkedListNode **node )
{
  CircularLinkedListNode *p;
  long i;

  for( p = get_list_head( list ), i = 0; i < list_size( list ) && index > 0; p = p->next, i++ ) {
    index--;
  }

  if( i < list_size( list ) && 0 == index ) {
    *node = p;
    return true;
  } else {
    *node = NULL;
    return false;
  }
}

CircularLinkedListNode *locate_list_node_by_locator( CircularLinkedList *list, void *key, int ( *compare )( const void *, const void * ) )
{
  CircularLinkedListNode *p;
  long i;

  for( p = get_list_head( list ), i = 0; i < list_size( list ); p = p->next, i++ ) {
    if( compare && !compare( p->data, key ) ) {
      break;
    }
  }

  if( i < list_size( list ) ) {
    return p;
  } else {
    return NULL;
  }
}

CircularLinkedListNode *get_previous_node( CircularLinkedList *list, CircularLinkedListNode *pos )
{
  CircularLinkedListNode *p, *c;
  long i;

  for( p = NULL, c = get_list_head( list ), i = 0; i < list_size( list ); c = c->next, i++ ) {
    if( c == pos ) {
      break;
    }
    p = c;
  }

  if( i < list_size( list ) && c == pos ) {
    return p;
  } else {
    return NULL;
  }
}

CircularLinkedListNode *get_next_node( CircularLinkedList *list, CircularLinkedListNode *pos )
{
  CircularLinkedListNode *p;
  long i;

  for( p = get_list_head( list ), i = 0; i < list_size( list ); p = p->next, i++) {
    if( p == pos ) {
      break;
    }
  }

  if( i < list_size( list ) - 1 && p == pos ) {
    return p->next;
  } else {
    return NULL;
  }
}

Status insert_list_head( CircularLinkedList *list, CircularLinkedListNode **node )
{
  if( node == NULL || *node == NULL || ( *node )->next != NULL ) {
    return false;
  }

  // 当前线性表为空
  if( is_empty_list( list ) ) {
    list->head = *node;
    list->tail = *node;
    ( *node )->next = *node;
  } else { // 当前线性表不为空
    ( *node )->next = list->head;
    list->head = *node;
    list->tail->next = *node;
  }
  list->size++;

  return true;
}

Status append_list_tail( CircularLinkedList *list, CircularLinkedListNode **node )
{
  if( node == NULL || *node == NULL || ( *node )->next != NULL ) {
    return false;
  }

  if( is_empty_list( list ) ) {
    list->head = *node;
    list->tail = *node;
    ( *node )->next = *node;
  } else {
    ( *node )->next = list->head;
    list->tail->next = *node;
    list->tail = *node;
  }
  list->size++;

  return true;
}

Status insert_before_list_node( CircularLinkedList *list, CircularLinkedListNode **pos, CircularLinkedListNode **node )
{
  CircularLinkedListNode *previous;

  if( node == NULL || *node == NULL || ( *node )->next != NULL ) {
    return false;
  }

  if( *pos == get_list_head( list ) ) {
    return insert_list_head( list, node );
  } else if( ( previous = get_previous_node( list, *pos ) ) != NULL ) {
    ( *node )->next = previous->next;
    previous->next = *node;
    list->size++;

    return true;
  } else {
    return false;
  }
}

Status append_after_list_node( CircularLinkedList *list, CircularLinkedListNode **pos, CircularLinkedListNode **node )
{
  CircularLinkedListNode *next;

  if( node == NULL || *node == NULL || ( *node )->next != NULL ) {
    return false;
  }

  if( *pos == get_list_tail ( list ) ) {
    return append_list_tail( list, node );
  } else if( ( next = get_next_node( list, *pos ) ) != NULL ) {
    ( *node )->next = next;
    ( *pos )->next = *node;
    list->size++;

    return true;
  } else {
    return false;
  }
}

Status delete_list_head( CircularLinkedList *list, CircularLinkedListNode **node )
{
  if( is_empty_list( list ) || node == NULL ) {
    return false;
  }

  *node = list->head;
  list->head = ( *node )->next;
  list->tail->next = list->head;
  list->size--;
  if( is_empty_list( list ) ) {
    list->head = NULL;
    list->tail = NULL;
  }

  ( *node )->next = NULL;

  return true;
}

Status remove_list_tail( CircularLinkedList *list, CircularLinkedListNode **node )
{
  CircularLinkedListNode *previous;

  if( is_empty_list( list ) || node == NULL ) {
    return false;
  }

  *node = list->tail;

  if( *node == get_list_head( list ) ) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    ( *node )->next = NULL;

    return true;
  } else if( ( previous = get_previous_node( list, *node ) ) != NULL ) {
    list->tail = previous;
    previous->next = list->head;
    list->size--;
    ( *node )->next = NULL;

    return true;
  } else {
    return false;
  }
}

Status delete_list_node( CircularLinkedList *list, CircularLinkedListNode **pos )
{
  CircularLinkedListNode *previous;

  if( is_empty_list( list ) || pos == NULL || *pos == NULL ) {
    return false;
  }

  if( *pos == get_list_head( list ) ) {
    return delete_list_head( list, pos );
  } else if( *pos == get_list_tail( list ) ) {
    return remove_list_tail( list, pos );
  } else if( ( previous = get_previous_node( list, *pos ) ) != NULL ) {
    previous->next = ( *pos )->next;
    ( *pos )->next = NULL;
    list->size--;

    return true;
  } else {
    return false;
  }
}

CircularLinkedListNode *get_list_head( CircularLinkedList *list )
{
  return list->head;
}

CircularLinkedListNode *get_list_tail( CircularLinkedList *list )
{
  return list->tail;
}

Status set_list_node_content( CircularLinkedListNode *pos, void *data )
{
  if( pos == NULL || data == NULL ) {
    return false;
  }

  pos->data = data;
  return true;
}

void *get_list_node_content( CircularLinkedListNode *pos )
{
  return pos ? pos->data : NULL;
}

Status list_traverse( CircularLinkedList *list, Status ( *handle )( void * ) )
{
  CircularLinkedListNode *p;
  long i;
  Status status = true;

  for( p = get_list_head( list ), i = 0; i <  list_size( list ); p = p->next, i++ ) {
    if( handle ) {
      status = handle( p->data );
    }
    if( !status ) {
      break;
    }
  }

  return status;
}
