#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/*
 * 通用链式线性表
 */

#include <stdbool.h>

/*
 * 节点结构
 */
typedef struct ListNodeTag {
  void *data;
  struct ListNodeTag *next;
} ListNode;

/*
 * 链表结构
 */
typedef struct {
  ListNode *head;
  ListNode *tail;
  long size;
} LinkedList;

/*
 * 构造一个空的线性表
 */
void init_list( LinkedList *list );

/*
 * 销毁线性表
 */
void destroy_list( LinkedList *list, void (*clear)(void *) );

/*
 * 重置线性表，将线性表重置为空表
 */
void clear_list( LinkedList *list, void (*clear)(void *) );

/*
 * 若list为空表，返回TRUE,否则返回FALSE
 */
bool is_empty_list( LinkedList *list );

/*
 * 返回线性表中元素的个数
 */
long list_size( LinkedList *list );

/*
 * 获取线性表中某位置的数据
 */
void * get_list_element( LinkedList *list, long index );

/*
 * 搜索线性表中第一个与key满足compare的数据元素的位序
 */
long locate_list_element( LinkedList *list, void *key, int (*compare)(const void *, const void *) );

/*
 * 搜索线性表中前驱节点
 */
void * get_previous_element( LinkedList *list, long location );

/*
 * 搜索线性表中的后继节点
 */
void * get_next_element( LinkedList *list, long location );

/*
 * 插入一个节点
 */
void list_insert( LinkedList *list, void *data, long index );

/*
 * 删除一个节点
 */
void *list_delete( LinkedList *list, long index );

/*
 * 链表遍历
 */
void list_traverse( LinkedList *list, void (*handle)(void *) );

#endif
