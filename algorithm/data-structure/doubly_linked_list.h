#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

/*
 * 通用双链线性表
 */

#include <stdbool.h>

/*
 * 双链节点结构
 */
typedef struct DoublyLinkedListNodeTag {
  void *data;
  struct DoublyLinkedListNodeTag *next;
  struct DoublyLinkedListNodeTag *previous;
} DoublyLinkedListNode;

/*
 * 双链线性表结构
 */
typedef struct {
  DoublyLinkedListNode *head;
  DoublyLinkedListNode *tail;
  long size;
} DoublyLinkedList;

typedef bool Status;

/*
 * 新建双链线性表节点，并由node返回
 *
 * node   返回的新建节点
 * data   实际数据
 */
Status make_list_node( DoublyLinkedListNode **node, void *data );

/*
 * 释放双链线性表节点
 *
 * node   释放后的节点地址
 */
void destroy_list_node( DoublyLinkedListNode **node );

/*
 * 构造一个空的双链线性表
 *
 * list   返回的空线性表指针
 */
Status init_list( DoublyLinkedList **list );

/*
 * 释放一个空的双链线性表
 *
 * list   返回的线性表指针地址
 */
Status destroy_list( DoublyLinkedList **list );

/*
 * 将双链线性表重置为空表，并释放原链表节点空间
 *
 * list   目标线性表指针
 * clear  清理函数，用户提供
 */
Status clear_list( DoublyLinkedList *list, Status ( *clear )( void * ) );

/*
 * 判断双链线性表是否为空表
 *
 *  空表返回TRUE
 *  否则返回FALSE
 *
 * list   目标线性表指针
 */
bool is_empty_list( DoublyLinkedList *list );

/*
 * 获取双链线性表大小
 *
 * 返回双链线性表中元素个数
 *
 * list   目标线性表指针
 */
long list_size( DoublyLinkedList *list );

/*
 * 获取双链线性表中某位置的节点地址
 *
 * 找到返回TRUE，若找不到，返回FALSE
 *
 * list   目标线性表指针
 * index  元素下标
 * node   返回的目标节点地址
 */
Status locate_list_node_by_position( DoublyLinkedList *list, long index, DoublyLinkedListNode **node );

/*
 * 搜索双链线性表中与key满足compare关系的的第一个数据节点地址
 *
 * 返回与key满足compare关系的第一个数据节点地址
 * 找不到返回NULL
 *
 * list      目标线性表指针
 * key       目标元素指针
 * compare   函数指针，定义目标元素和数据元素之间关系
 */
DoublyLinkedListNode *locate_list_node_by_locator( DoublyLinkedList *list, void *key, int ( *compare )( const void *, const void * ) );

/*
 * 搜索双链线性表中目标节点的前驱节点地址
 *
 * list   目标线性表指针
 * pos    目标节点指针
 */
DoublyLinkedListNode *get_previous_node( DoublyLinkedList *list, DoublyLinkedListNode *pos );

/*
 * 搜索双链线性表中目标节点的后继节点地址
 *
 * list   目标线性表指针
 * pos    目标节点指针
 */
DoublyLinkedListNode * get_next_node( DoublyLinkedList *list, DoublyLinkedListNode *pos );

/*
 * 将节点插入双链线性表表头，插入成功后，node为空
 *
 * list      目标线性表指针
 * node      待插节点指针地址
 */
Status insert_list_head( DoublyLinkedList *list, DoublyLinkedListNode **node );

/*
 * 将节点插入双链线性表表尾，插入成功后，node为空
 *
 * list      目标线性表指针
 * node      待插节点指针地址
 */
Status append_list_tail( DoublyLinkedList *list, DoublyLinkedListNode **node );

/*
 * 将节点插入双链线性表中某一位置之前，插入成功后，node为空
 *
 * list    目标线性表指针
 * pos     目标插入位置指针
 * node    目标节点指针地址
 */
Status insert_before_list_node( DoublyLinkedList *list, DoublyLinkedListNode **pos, DoublyLinkedListNode **node );

/*
 * 将节点插入双链线性表中某一位置之后，插入成功后，node为空
 *
 * list    目标线性表指针
 * pos     目标插入位置指针
 * node    目标节点指针地址
 */
Status append_after_list_node( DoublyLinkedList *list, DoublyLinkedListNode **pos, DoublyLinkedListNode **node );

/*
 * 删除双链线性表表头节点，并以node返回
 *
 * list    目标线性表指针
 * node    返回的表头节点
 */
Status delete_list_head( DoublyLinkedList *list, DoublyLinkedListNode **node );

/*
 * 删除双链线性表表尾节点，并以node返回
 *
 * list    目标线性表指针
 * node    返回的表尾节点
 */
Status remove_list_tail( DoublyLinkedList *list, DoublyLinkedListNode **node );

/*
 * 删除一个节点，并以node返回
 *
 * list   目标线性表指针
 * node   待删除节点位置指针
 */
Status delete_list_node( DoublyLinkedList *list, DoublyLinkedListNode **node );

/*
 * 返回双链线性表的表头位置
 *
 * list   目标线性表指针
 */
DoublyLinkedListNode *get_list_head( DoublyLinkedList *list );

/*
 * 返回双链线性表的表尾位置
 *
 * list   目标线性表指针
 */
DoublyLinkedListNode *get_list_tail( DoublyLinkedList *list );

/*
 * 设置节点内容
 *
 * node   目标节点
 * data   数据内容
 */
Status set_list_node_content( DoublyLinkedListNode *node, void *data );

/*
 * 获取节点内容
 *
 * node   目标节点
 */
void *get_list_node_content( DoublyLinkedListNode *node );

/*
 * 双链线性表遍历
 *
 * list    目标线性表指针
 * handle  函数句柄，对线性表中的每一个元素做相应的操作
 */
Status list_traverse( DoublyLinkedList *list, Status ( *handle )( void * ) );

#endif
