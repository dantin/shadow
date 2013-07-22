/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : longest.c
 * version     : 1.0
 * author      : david
 * date        : 2013-07-22
 * description : 找字符串中最长连续两字符子串
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
  char c;
  struct Element *next;
} Node;

Node *read(void);
void longest(Node *string);
int try( Node *p, Node **end, Node **next );

int main(void)
{
  Node *string = read();

  printf( "\n" );

  longest( string );

  printf( "\n" );

  return 0;
}

/*
 * 读入字符串内容，返回字符链表
 */
Node *read(void)
{
  Node *head, *tail;
  int c;

  head = tail = NULL;
  while( ( c = getchar() ) != EOF ) {
    Node *node = ( Node * ) malloc ( sizeof( Node ) );
    node->c = c;
    node->next = NULL;

    if( head == NULL ) {
      head = tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }

  return head;
}

void longest( Node *string )
{
  Node *max_begin, *max_end;
  int max_length = 0;

  while( string != NULL ) {
    Node *begin = string;
    Node *end, *next;
    int size = try( begin, &end, &next );

    if( size > max_length ) {
      max_length = size;
      max_begin = begin;
      max_end = end;
    }

    string = next;
  }

  printf( "Max Length: %d\n", max_length);

  while( max_begin != max_end ) {
    putchar(max_begin->c);
    max_begin = max_begin->next;
  }
}

int try( Node *p, Node **end, Node **next )
{
  char set[2];
  Node *n;
  int size = 0;

  set[0] = p->c;
  set[1] = 0;

  n = p;
  while( n != NULL ) {
    if( n->c == set[0] ) {
      n = n->next;
      size++;
    } else {
      if( set[1] == 0 ) {
	set[1] = n->c;
	n = n->next;
	size++;
      } else if( n->c == set[1] ) {
	n = n->next;
	*next = n;
	size++;
      } else {
	break;
      }
    }
  }

  *end = n;
  return size;
}
