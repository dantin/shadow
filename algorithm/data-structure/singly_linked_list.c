#include <stdlib.h>
#include <assert.h>

#include "singly_linked_list.h"

Status make_list_node( SinglyLinkedListNode **target, void *data )
{
  SinglyLinkedListNode *node = ( SinglyLinkedListNode * ) malloc( sizeof( SinglyLinkedListNode ) );

  if( !node ) {
    return false;
  }

  node->data = data;
  node->next = NULL;

  *target = node;

  return true;
}

void destroy_list_node( SinglyLinkedListNode **node )
{
  free( *node );
  *node = NULL;
}

Status init_list( SinglyLinkedList **listp )
{
  if( !listp || *listp ) {
    return false;
  }

  SinglyLinkedList *list = ( SinglyLinkedList * ) malloc( sizeof( SinglyLinkedList ) );
  assert( list );

  *listp = list;
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return true;
}

Status destroy_list( SinglyLinkedList **listp )
{
  if( !listp || !*listp ) {
    return false;
  }

  free( *listp );
  *listp = NULL;

  return true;
}

Status clear_list( SinglyLinkedList *list, Status ( *clear )( void * ) )
{
  Status status = true;
  SinglyLinkedListNode *p, *t;

  p = get_list_head( list );
  while( p ) {
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
  }

  if( status ) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
  }

  return status;
}

bool is_empty_list( SinglyLinkedList *list )
{
  return list->size == 0;
}

long list_size( SinglyLinkedList *list )
{
  return list->size;
}

Status locate_list_node_by_position( SinglyLinkedList *list, long index, SinglyLinkedListNode **node )
{
  SinglyLinkedListNode *p;

  for( p = get_list_head( list ); p && index > 0; p = p->next ) {
    index--;
  }

  if( p && 0 == index ) {
    *node = p;
    return true;
  } else {
    *node = NULL;
    return false;
  }
}

SinglyLinkedListNode *locate_list_node_by_locator( SinglyLinkedList *list, void *key, int ( *compare )( const void *, const void * ) )
{
  SinglyLinkedListNode *p;

  for( p = get_list_head( list ); p; p = p->next ) {
    if( compare && !compare( p->data, key ) ) {
      break;
    }
  }

  return p;
}

SinglyLinkedListNode *get_previous_node( SinglyLinkedList *list, SinglyLinkedListNode *pos )
{
  SinglyLinkedListNode *p, *c;

  for( p = NULL, c = get_list_head( list ); c; c = c->next ) {
    if( c == pos ) {
      break;
    }
    p = c;
  }

  if( c && c == pos ) {
    return p;
  } else {
    return NULL;
  }
}

SinglyLinkedListNode *get_next_node( SinglyLinkedList *list, SinglyLinkedListNode *pos )
{
  SinglyLinkedListNode *p;

  for( p = get_list_head( list ); p; p = p->next) {
    if( p == pos ) {
      break;
    }
  }

  if( p && p == pos ) {
    return p->next;
  } else {
    return NULL;
  }
}

Status insert_list_head( SinglyLinkedList *list, SinglyLinkedListNode **node )
{
  if( node == NULL || *node == NULL || ( *node )->next != NULL ) {
    return false;
  }

  // 当前线性表为空
  if( is_empty_list( list ) ) {
    list->head = *node;
    list->tail = *node;
  } else { // 当前线性表不为空
    ( *node )->next = list->head;
    list->head = *node;
  }
  list->size++;

  return true;
}

Status append_list_tail( SinglyLinkedList *list, SinglyLinkedListNode **node )
{
  if( node == NULL || *node == NULL || ( *node )->next != NULL ) {
    return false;
  }

  if( is_empty_list( list ) ) {
    list->head = *node;
    list->tail = *node;
  } else {
    list->tail->next = *node;
    list->tail = *node;
  }
  list->size++;

  return true;
}

Status insert_before_list_node( SinglyLinkedList *list, SinglyLinkedListNode **pos, SinglyLinkedListNode **node )
{
  SinglyLinkedListNode *previous;

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

Status append_after_list_node( SinglyLinkedList *list, SinglyLinkedListNode **pos, SinglyLinkedListNode **node )
{
  SinglyLinkedListNode *next;

  if( node == NULL || *node == NULL || ( *node )->next != NULL ) {
    return false;
  }

  if( *pos == get_list_tail( list ) ) {
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

Status delete_list_head( SinglyLinkedList *list, SinglyLinkedListNode **node )
{
  if( is_empty_list( list ) || node == NULL ) {
    return false;
  }

  *node = list->head;
  list->head = ( *node )->next;
  list->size--;
  if( is_empty_list( list ) ) {
    list->tail = NULL;
  }

  ( *node )->next = NULL;

  return true;
}

Status remove_list_tail( SinglyLinkedList *list, SinglyLinkedListNode **node )
{
  SinglyLinkedListNode *previous;

  if( is_empty_list( list ) || node == NULL ) {
    return false;
  }

  *node = list->tail;

  if( *node == get_list_head( list ) ) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
 
    return true;
  } else if( ( previous = get_previous_node( list, *node ) ) != NULL ) {
    list->tail = previous;
    previous->next = NULL;
    list->size--;

    return true;
  } else {
    return false;
  }
}

Status delete_list_node( SinglyLinkedList *list, SinglyLinkedListNode **pos )
{
  SinglyLinkedListNode *previous;

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

SinglyLinkedListNode *get_list_head( SinglyLinkedList *list )
{
  return list->head;
}

SinglyLinkedListNode *get_list_tail( SinglyLinkedList *list )
{
  return list->tail;
}

Status set_list_node_content( SinglyLinkedListNode *pos, void *data )
{
  if( pos == NULL || data == NULL ) {
    return false;
  }

  pos->data = data;
  return true;
}

void *get_list_node_content( SinglyLinkedListNode *pos )
{
  return pos ? pos->data : NULL;
}

Status list_traverse( SinglyLinkedList *list, Status ( *handle )( void * ) )
{
  SinglyLinkedListNode *p;
  Status status = true;

  for( p = get_list_head( list ); p; p = p->next ) {
    if( handle ) {
      status = handle( p->data );
    }
    if( !status ) {
      break;
    }
  }

  return status;
}
