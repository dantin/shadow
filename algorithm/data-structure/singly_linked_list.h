#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

/*
 * 通用单链线性表
 */

#include <stdbool.h>

/*
 * 单链节点结构
 */
typedef struct SinglyLinkedListNodeTag {
  void *data;
  struct SinglyLinkedListNodeTag *next;
} SinglyLinkedListNode;

/*
 * 单链线性表结构
 */
typedef struct {
  SinglyLinkedListNode *head;
  SinglyLinkedListNode *tail;
  long size;
} SinglyLinkedList;

typedef bool Status;

/*
 * 新建单链线性表节点，并由node返回
 *
 * node   返回的新建节点
 * data   实际数据
 */
Status make_list_node( SinglyLinkedListNode **node, void *data );

/*
 * 释放单链线性表节点
 *
 * node   释放后的节点地址
 */
void destroy_list_node( SinglyLinkedListNode **node );

/*
 * 构造一个空的单链线性表
 *
 * list   返回的空线性表指针
 */
Status init_list( SinglyLinkedList **list );

/*
 * 释放一个空的单链线性表
 *
 * list   返回的线性表指针地址
 */
Status destroy_list( SinglyLinkedList **list );

/*
 * 将单链线性表重置为空表，并释放原链表节点空间
 *
 * list   目标线性表指针
 * clear  清理函数，用户提供
 */
Status clear_list( SinglyLinkedList *list, Status ( *clear )( void * ) );

/*
 * 判断单链线性表是否为空表
 *
 *  空表返回TRUE
 *  否则返回FALSE
 *
 * list   目标线性表指针
 */
bool is_empty_list( SinglyLinkedList *list );

/*
 * 获取单链线性表大小
 *
 * 返回单链线性表中元素个数
 *
 * list   目标线性表指针
 */
long list_size( SinglyLinkedList *list );

/*
 * 获取单链线性表中某位置的节点地址
 *
 * 找到返回TRUE，若找不到，返回FALSE
 *
 * list   目标线性表指针
 * index  元素下标
 * node   返回的目标节点地址
 */
Status locate_list_node_by_position( SinglyLinkedList *list, long index, SinglyLinkedListNode **node );

/*
 * 搜索单链线性表中与key满足compare关系的的第一个数据节点地址
 *
 * 返回与key满足compare关系的第一个数据节点地址
 * 找不到返回NULL
 *
 * list      目标线性表指针
 * key       目标元素指针
 * compare   函数指针，定义目标元素和数据元素之间关系
 */
SinglyLinkedListNode *locate_list_node_by_locator( SinglyLinkedList *list, void *key, int (*compare)(const void *, const void *) );

/*
 * 搜索单链线性表中目标节点的前驱节点地址
 *
 * list   目标线性表指针
 * pos    目标节点指针
 */
SinglyLinkedListNode *get_previous_node( SinglyLinkedList *list, SinglyLinkedListNode *pos );

/*
 * 搜索单链线性表中目标节点的后继节点地址
 *
 * list   目标线性表指针
 * pos    目标节点指针
 */
SinglyLinkedListNode * get_next_node( SinglyLinkedList *list, SinglyLinkedListNode *pos );

/*
 * 将节点插入单链线性表表头，插入成功后，node为空
 *
 * list      目标线性表指针
 * node      待插节点指针地址
 */
Status insert_list_head( SinglyLinkedList *list, SinglyLinkedListNode **node );

/*
 * 将节点插入单链线性表表尾，插入成功后，node为空
 *
 * list      目标线性表指针
 * node      待插节点指针地址
 */
Status append_list_tail( SinglyLinkedList *list, SinglyLinkedListNode **node );

/*
 * 将节点插入单链线性表中某一位置之前，插入成功后，node为空
 *
 * list    目标线性表指针
 * pos     目标插入位置指针
 * node    目标节点指针地址
 */
Status insert_before_list_node( SinglyLinkedList *list, SinglyLinkedListNode **pos, SinglyLinkedListNode **node );

/*
 * 将节点插入单链线性表中某一位置之后，插入成功后，node为空
 *
 * list    目标线性表指针
 * pos     目标插入位置指针
 * node    目标节点指针地址
 */
Status append_after_list_node( SinglyLinkedList *list, SinglyLinkedListNode **pos, SinglyLinkedListNode **node );

/*
 * 删除单链线性表表头节点，并以node返回
 *
 * list    目标线性表指针
 * node    返回的表头节点
 */
Status delete_list_head( SinglyLinkedList *list, SinglyLinkedListNode **node );

/*
 * 删除单链线性表表尾节点，并以node返回
 *
 * list    目标线性表指针
 * node    返回的表尾节点
 */
Status remove_list_tail( SinglyLinkedList *list, SinglyLinkedListNode **node );

/*
 * 删除一个节点，并以node返回
 *
 * list   目标线性表指针
 * node   待删除节点位置指针
 */
Status delete_list_node( SinglyLinkedList *list, SinglyLinkedListNode **node );

/*
 * 返回单链线性表的表头位置
 *
 * list   目标线性表指针
 */
SinglyLinkedListNode *get_list_head( SinglyLinkedList *list );

/*
 * 返回单链线性表的表尾位置
 *
 * list   目标线性表指针
 */
SinglyLinkedListNode *get_list_tail( SinglyLinkedList *list );

/*
 * 设置节点内容
 *
 * node   目标节点
 * data   数据内容
 */
Status set_list_node_content( SinglyLinkedListNode *node, void *data );

/*
 * 获取节点内容
 *
 * node   目标节点
 */
void *get_list_node_content( SinglyLinkedListNode *node );

/*
 * 单链线性表遍历
 *
 * list    目标线性表指针
 * handle  函数句柄，对线性表中的每一个元素做相应的操作
 */
Status list_traverse( SinglyLinkedList *list, Status (*handle)(void *) );

#endif
