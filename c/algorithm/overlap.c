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

typedef enum {BEGIN, END} Tag;

typedef struct Node
{
  int position;
  Tag flag;
  struct Node *next;
} Time;

Time *read(void);
Time *make_node(int position, Tag flag);
void insert(Time **list, Time *elem);
void find_overlap(Time *list);

int main(void)
{
  // read lines, get sorted nodes
  Time *nodes = read();

  find_overlap( nodes );

  return 0;
}

/*
 * 读入线段信息，返回排序后的线段节点列表
 */
Time *read(void)
{
  int start;
  int end;

  Time *nodes = NULL;

  while( scanf( "%d %d", &start, &end) != EOF ) {
    insert( &nodes, make_node( start, BEGIN ) );
    insert( &nodes, make_node( end, END ) );
  }

  return nodes;
}

/*
 * 创建节点
 */
Time *make_node(int position, Tag flag)
{
  Time *node = (Time *) malloc (sizeof(Time));
  node->position = position;
  node->flag = flag;
  node->next = NULL;

  return node;
}

/*
 * 插入排序
 */
void insert(Time **list, Time *target)
{
  Time *pre, *cur;

  pre = NULL;
  cur = *list;

  while( cur != NULL ) {
    if( cur->position < target->position ) {
      pre = cur;
      cur = cur->next;
    } else {
      break;
    }
  }

  if( pre != NULL ) {
    target->next = pre->next;
    pre->next = target;
  } else {
    *list = target;
    ( *list )->next = NULL;
  }
  
}

/*
 * 找重叠时间
 */
void find_overlap( Time *list )
{
  int count = 0;
 
  while( list != NULL ) {
    if( list->flag == BEGIN ) {
      count++;
    }
    if( list->flag == END ) {
      count--;
    }

    if( count == 2 && list->flag == BEGIN ) {
      printf( "Overlap: < %d, ", list->position );
    } else if( count == 1 && list->flag == END ) {
      printf( "%d >\n", list->position );
    }

    list = list->next;
  }

  printf("\n");
}
