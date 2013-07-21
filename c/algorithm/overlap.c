/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : overlap.c
 * version     : 1.0
 * author      : david
 * date        : 2013-07-21
 * description : 找出一段时间内不同任务的重叠时间
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} bool;

typedef struct Node
{
  int position;
  bool is_begin ;
  bool is_end;
  struct Node *next;
} Time;

Time *read(void);
void insert(Time **list, Time *elem);
void print(Time *list);

int main(void)
{
  Time *nodes = read();

  print( nodes );

  return 0;
}

void print( Time *list )
{
  while( list != NULL ) {
    printf( "%d\n", list->position );
    list = list->next;
  }
}

Time *read(void)
{
  int start;
  int end;

  Time *nodes = NULL;

  while( scanf( "%d %d", &start, &end) != EOF ) {

    Time *node_s = (Time *) malloc (sizeof(Time));
    node_s->position = start;
    node_s->is_begin = TRUE;
    node_s->is_end = FALSE;
    node_s->next = NULL;

    insert( &nodes, node_s );

    Time *node_e = (Time *) malloc (sizeof(Time));
    node_e->position = end;
    node_e->is_begin = FALSE;
    node_e->is_end = TRUE;
    node_e->next = NULL;

    insert( &nodes, node_e );
  }

  return nodes;
}

void insert(Time **list, Time *target)
{
  if( *list == NULL) {
    *list = target;
  } else {
    Time *p = *list;
    while( p->next != NULL ) {
      if( p->position < target->position ) {
	p = p->next;
      } else {
	break;
      }
    }
    target->next = p->next;
    p->next = target;
  }
}
