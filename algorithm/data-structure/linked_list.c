#include <stdlib.h>
#include <stdbool.h>

#include "linked_list.h"

/*
 * 构造一个空的线性表
 */
void list_init( LinkedList *list )
{
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

/*
 * 初始条件：线性表list已存在
 *
 * 若list为空表，返回TRUE，否则返回FALSE
 */
bool is_empty( LinkedList *list )
{
  return ( list->head == NULL );
}

/*
 * 初始条件：线性表list已存在
 *
 * 销毁线性表
 */
void list_destroy( LinkedList *list, void (*destroy)(void *) )
{

}
