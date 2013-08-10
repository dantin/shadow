#include <stdlib.h>

#include "doubly_linked_list.h"

Status make_list_node( DoublyLinkedListNode **target, void *data )
{
  DoublyLinkedListNode *node = ( DoublyLinkedListNode * ) malloc( sizeof( DoublyLinkedListNode ) );

  if( !node ) {
    return false;
  }

  node->data = data;
  node->next = NULL;
  node->previous = NULL;

  *target = node;

  return true;
}

void destroy_list_node( DoublyLinkedListNode **node )
{
  free( *node );
  *node = NULL;
}

Status init_list( DoublyLinkedList *list )
{
  if( !list ) {
    return false;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return true;
}

Status clear_list( DoublyLinkedList *list, Status ( *clear )( void * ) )
{
  Status status = true;
  DoublyLinkedListNode *p, *t;

  p = get_list_head( list );
  while( p ) {
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

bool is_empty_list( DoublyLinkedList *list )
{
  return list->size == 0;
}

long list_size( DoublyLinkedList *list )
{
  return list->size;
}

Status locate_list_node_by_position( DoublyLinkedList *list, long index, DoublyLinkedListNode **node )
{
  DoublyLinkedListNode *p;

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

DoublyLinkedListNode *locate_list_node_by_locator( DoublyLinkedList *list, void *key, int (*compare)(const void *, const void *) )
{
  DoublyLinkedListNode *p;

  for( p = get_list_head( list ); p; p = p->next ) {
    if( compare && !compare( p->data, key ) ) {
      break;
    }
  }

  return p;
}

DoublyLinkedListNode *get_previous_node( DoublyLinkedList *list, DoublyLinkedListNode *pos )
{
  DoublyLinkedListNode *p;

  for( p = get_list_head( list ); p; p = p->next ) {
    if( p == pos ) {
      break;
    }
  }

  if( p && p == pos ) {
    return p->previous;
  } else {
    return NULL;
  }
}

DoublyLinkedListNode *get_next_node( DoublyLinkedList *list, DoublyLinkedListNode *pos )
{
  DoublyLinkedListNode *p;

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

Status insert_list_head( DoublyLinkedList *list, DoublyLinkedListNode *node )
{
  if( node == NULL || !( node->next == NULL && node->previous == NULL ) ) {
    return false;
  }

  // 当前线性表为空
  if( list->size == 0 ) {
    list->head = node;
    list->tail = node;
  } else { // 当前线性表不为空
    node->next = list->head;
    list->head->previous = node;
    list->head = node;
  }
  list->size++;

  return true;
}

Status append_list_tail( DoublyLinkedList *list, DoublyLinkedListNode *node )
{
  if( node == NULL || !( node->next == NULL && node->previous == NULL ) ) {
    return false;
  }

  if( list->size == 0 ) {
    list->head = node;
    list->tail = node;
  } else {
    node->previous = list->tail;
    list->tail->next = node;
    list->tail = node;
  }
  list->size++;

  return true;
}

Status insert_before_list_node( DoublyLinkedList *list, DoublyLinkedListNode **pos, DoublyLinkedListNode *node )
{
  DoublyLinkedListNode *previous;
  if( node == NULL || !( node->next == NULL && node->previous == NULL ) ) {
    return false;
  }

  if( *pos == get_list_head( list ) ) {
    insert_list_head( list, node );
    return true;
  } else if( ( previous = get_previous_node( list, *pos ) ) != NULL ) {
    node->next = *pos;
    node->previous = previous;
    ( *pos )->previous = node;
    previous->next = node;
    list->size++;
    return true;
  } else {
    return false;
  }
}

Status append_after_list_node( DoublyLinkedList *list, DoublyLinkedListNode **pos, DoublyLinkedListNode *node )
{
  DoublyLinkedListNode *next;
  if( node == NULL || !( node->next == NULL && node->previous == NULL ) ) {
    return false;
  }

  if( *pos == get_list_tail ( list ) ) {
    append_list_tail( list, node );
    return true;
  } else if( ( next = get_next_node( list, *pos ) ) != NULL ) {
    node->previous = *pos;
    node->next = next;
    ( *pos )->next = node;
    next->previous = node;
    list->size++;
    return true;
  } else {
    return false;
  }
}

Status delete_list_head( DoublyLinkedList *list, DoublyLinkedListNode **node )
{
  if( is_empty_list( list ) || node == NULL ) {
    return false;
  }

  *node = list->head;
  list->head = ( *node )->next;
  list->head->previous = NULL;
  list->size--;
  if( list->size == 0 ) {
    list->tail = NULL;
  }

  ( *node )->next = NULL;

  return true;
}

Status remove_list_tail( DoublyLinkedList *list, DoublyLinkedListNode **node )
{
  if( is_empty_list( list ) || node == NULL ) {
    return false;
  }

  *node = list->tail;

  list->tail = ( *node )->previous;
  list->tail->next = NULL;
  list->size--;
  if( list->size == 0 ) {
    list->head = NULL;
  }

  ( *node )->previous = NULL;
  return true;
}

Status delete_list_node( DoublyLinkedList *list, DoublyLinkedListNode **pos )
{
  if( is_empty_list( list ) || pos == NULL || *pos == NULL ) {
    return false;
  }

  DoublyLinkedListNode *previous;
  if( *pos == get_list_head( list ) ) {
    return delete_list_head( list, pos );
  } else if( *pos == get_list_tail( list ) ) {
    return remove_list_tail( list, pos );
  } else if( ( previous = get_previous_node( list, *pos ) ) != NULL ) {
    previous->next = ( *pos )->next;
    ( *pos )->next->previous  = ( *pos )->previous;
    ( *pos )->next = NULL;
    ( *pos )->previous = NULL;
    list->size--;
    return true;
  } else {
    return false;
  }
}

DoublyLinkedListNode *get_list_head( DoublyLinkedList *list )
{
  return list->head;
}

DoublyLinkedListNode *get_list_tail( DoublyLinkedList *list )
{
  return list->tail;
}

Status set_list_node_content( DoublyLinkedListNode *pos, void *data )
{
  if( pos == NULL || data == NULL ) {
    return false;
  }

  pos->data = data;
  return true;
}

void *get_list_node_content( DoublyLinkedListNode *pos )
{
  return pos ? pos->data : NULL;
}

Status list_traverse( DoublyLinkedList *list, Status (*handle)(void *) )
{
  DoublyLinkedListNode *p;
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
