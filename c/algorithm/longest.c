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
int forward( Node *p, Node **end, Node **next );

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

/*
 * 查找最长的两个不同字符的子串
 */
void longest( Node *string )
{
  Node *max_begin, *max_end;
  int max_length = 0;

  while( string != NULL ) {
    Node *end, *next;
    end = next = NULL;
    int size = forward( string, &end, &next );

    if( size > max_length ) {
      max_length = size;
      max_begin = string;
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

/*
 * 从p开始前向搜索含两个不同字符的最长子串
 * end:  子串结尾的后一个字符
 * next: 下次一开始搜索的位置，即首字符的最后开始位置
 *
 * 例如
 *       abaacccaade第一次搜索
 *         ^ ^
 *         1 2
 *
 *    1) next
 *    2) end
 */
int forward( Node *p, Node **end, Node **next )
{
  char set[2];
  int size = 0;
  int count = 0;

  set[0] = p->c;
  set[1] = 0;

  while( p != NULL ) {
    if( set[0] != 0 && set[1] != 0 && p->c != set[0] && p->c != set[1] ) {
      break;
    }

    if( p->c == set[0] ) {
      count++;
    } else {
      count = 0;
    }

    if( p->c != set[0] && set[1] == 0 ) {
      set[1] = p->c;
    }

    if( p->c == set[0] && set[1] != 0 && count == 1) {
      *next = p;
    }

    if( p->c == set[0] || p->c == set[1] ) {
      p = p->next;
      size++;
    }
  }

  *end = p;

  return size;
}
