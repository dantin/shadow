#include <stdlib.h>

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

Status init_list( CircularLinkedList *list )
{
  if( !list ) {
    return false;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return true;
}

Status clear_list( CircularLinkedList *list, Status ( *clear )( void * ) )
{
  Status status = true;
  CircularLinkedListNode *p, *t;

  p = get_list_head( list );
  while( list->size > 0 ) {
    t = p->next;
    list->head = p;

    if( clear ) {
      status = clear( p->data );
    }

    if( !status ) {
      break;
    }
    destroy_list_node( &p );
    list->size--;
    p = t;
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

  for( p = get_list_head( list ); p->next != get_list_head( list ) && index > 0; p = p->next ) {
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

CircularLinkedListNode *locate_list_node_by_locator( CircularLinkedList *list, void *key, int (*compare)(const void *, const void *) )
{
  CircularLinkedListNode *p;

  for( p = get_list_head( list ); p->next != get_list_head( list ); p = p->next ) {
    if( compare && !compare( p->data, key ) ) {
      break;
    }
  }

  return p;
}

CircularLinkedListNode *get_previous_node( CircularLinkedList *list, CircularLinkedListNode *pos )
{
  CircularLinkedListNode *p, *c;

  for( p = NULL, c = get_list_head( list ); c->next != get_list_head( list ); c = c->next ) {
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

CircularLinkedListNode *get_next_node( CircularLinkedList *list, CircularLinkedListNode *pos )
{
  CircularLinkedListNode *p;

  for( p = get_list_head( list ); p->next != get_list_head( list ); p = p->next) {
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

Status insert_list_head( CircularLinkedList *list, CircularLinkedListNode *node )
{
  if( node == NULL || node->next != NULL ) {
    return false;
  }

  // 当前线性表为空
  if( list->head == NULL ) {
    list->head = node;
    list->tail = node;
    node->next = node;
  } else { // 当前线性表不为空
    node->next = list->head;
    list->head = node;
    list->tail->next = node;
  }
  list->size++;

  return true;
}

Status append_list_tail( CircularLinkedList *list, CircularLinkedListNode *node )
{
  if( node == NULL || node->next != NULL ) {
    return false;
  }

  if( list->head == NULL ) {
    list->head = node;
    list->tail = node;
    node->next = node;
  } else {
    list->tail->next = node;
    list->tail = node;
    node->next = list->head;
  }
  list->size++;

  return true;
}

Status insert_before_list_node( CircularLinkedList *list, CircularLinkedListNode **pos, CircularLinkedListNode *node )
{
  CircularLinkedListNode *previous;
  if( node == NULL || node->next != NULL ) {
    return false;
  }

  if( *pos == get_list_head( list ) ) {
    insert_list_head( list, node );
    return true;
  } else if( ( previous = get_previous_node( list, *pos ) ) != NULL ) {
    node->next = previous->next;
    previous->next = node;
    list->size++;
    return true;
  } else {
    return false;
  }
}

Status append_after_list_node( CircularLinkedList *list, CircularLinkedListNode **pos, CircularLinkedListNode *node )
{
  CircularLinkedListNode *next;
  if( node == NULL || node->next != NULL ) {
    return false;
  }

  if( *pos == get_list_tail ( list ) ) {
    append_list_tail( list, node );
    return true;
  } else if( ( next = get_next_node( list, *pos ) ) != NULL ) {
    node->next = next;
    ( *pos )->next = node;
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
  if( list->size == 0 ) {
    list->head = NULL;
    list->tail = NULL;
  }

  ( *node )->next = NULL;

  return true;
}

Status remove_list_tail( CircularLinkedList *list, CircularLinkedListNode **node )
{
  if( is_empty_list( list ) || node == NULL ) {
    return false;
  }

  *node = list->tail;

  CircularLinkedListNode *previous;
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
  if( is_empty_list( list ) || pos == NULL || *pos == NULL ) {
    return false;
  }

  CircularLinkedListNode *previous;
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

Status list_traverse( CircularLinkedList *list, Status (*handle)(void *) )
{
  CircularLinkedListNode *p;
  Status status = true;

  for( p = get_list_head( list ); p->next != get_list_head( list ); p = p->next ) {
    if( handle ) {
      status = handle( p->data );
    }
    if( !status ) {
      break;
    }
  }

  return status;
}
