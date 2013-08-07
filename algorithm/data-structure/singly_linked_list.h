#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/*
 * 通用链式线性表
 */

#include <stdbool.h>

/*
 * 节点结构
 */
typedef struct LinkedListNodeTag {
  void *data;
  struct LinkedListNodeTag *next;
} LinkedListNode;

/*
 * 链表结构
 */
typedef struct {
  LinkedListNode *head;
  LinkedListNode *tail;
  long size;
} LinkedList;

typedef bool Status;

/*
 * 新建线性表节点，并由node返回
 *
 * node     返回的新建节点
 * data     实际数据
 */
Status make_list_node( LinkedListNode **node, void *data );

/*
 * 释放线性表节点
 *
 * node     待释放的节点地址
 */
Status destroy_list_node( LinkedListNode **node );

/*
 * 构造一个空的线性表
 *
 * list   目标线性表指针
 */
Status init_list( LinkedList *list );

/*
 * 将线性表重置为空表，并释放原链表节点空间
 *
 * list   目标线性表指针
 * clear  清理函数，用户提供
 */
Status clear_list( LinkedList *list, void (*clear)(void *) );

/*
 * 判断线性表是否为空表
 *
 *  空表返回TRUE
 *  否则返回FALSE
 *
 * list   目标线性表指针
 */
bool is_empty_list( LinkedList *list );

/*
 * 线性表大小
 *
 *  返回线性表中元素个数
 *
 * list   目标线性表指针
 */
long list_size( LinkedList *list );

/*
 * 获取线性表中某位置的节点
 *
 *  返回该位置的元素，若找不到，返回空
 *
 * list   目标线性表指针
 * index  元素下标
 * node   目标节点地址
 */
Status locate_list_element_position( LinkedList *list, long index, LinkedListNode **node );

/*
 * 搜索线性表中与key满足compare关系的的第一个数据节点
 *
 *  返回与key满足compare关系的第一个元素的位置
 *  找不到返回-1
 *
 * list      目标线性表指针
 * key       目标元素
 * compare   函数指针，定义目标元素和数据元素之间关系
 */
LinkedListNode *locate_list_element( LinkedList *list, void *key, int (*compare)(const void *, const void *) );

/*
 * 搜索线性表中目标节点的前驱节点
 *
 * list    目标线性表指针
 * pos     目标节点
 */
LinkedListNode * get_previous_position( LinkedList *list, LinkedListNode *pos );

/*
 * 搜索线性表中目标节点的后继节点
 *
 * list    目标线性表指针
 * pos     目标节点
 */
LinkedListNode *get_next_position( LinkedList *list, LinkedListNode *pos );

/*
 * 将节点插入线性表表头
 *
 * list      目标线性表指针
 * node      待插节点指针
 */
Status list_insert_head( LinkedList *list, LinkedListNode *node );

/*
 * 将节点插入线性表表尾
 *
 * list      目标线性表指针
 * node      待插节点指针
 */
Status list_append_tail( LinkedList *list, LinkedListNode *node );

/*
 * 将节点插入线性表中某一位置之前
 *
 * list    目标线性表指针
 * data    目标插入位置
 * index   目标节点
 */
Status list_insert( LinkedList *list, LinkedListNode **pos, LinkedListNode *node );

/*
 * 将节点插入线性表中某一位置之后
 *
 * list    目标线性表指针
 * pos     目标插入位置
 * node    目标节点
 */
Status list_append( LinkedList *list, LinkedListNode **pos, LinkedListNode *node );

/*
 * 删除线性表表头节点，并以node返回
 *
 * list    目标线性表指针
 * node    返回的表头节点
 */
Status list_delete_head( LinkedList *list, LinkedListNode **node );

/*
 * 删除线性表表尾节点，并以node返回
 *
 * list    目标线性表指针
 * node    返回的表尾节点
 */
Status list_remove_tail( LinkedList *list, LinkedListNode **node );

/*
 * 删除一个节点
 *
 * list   目标线性表指针
 * pos    待删除节点位置
 * node   返回的节点
 */
Status list_delete( LinkedList *list, LinkedListNode *pos, LinkedListNode **node );

/*
 * 返回线性链表的表头位置
 *
 * list   目标线性表指针
 */
LinkedListNode *get_list_head( LinkedList *list );

/*
 * 返回线性链表的表尾位置
 *
 * list   目标线性表指针
 */
LinkedListNode *get_list_tail( LinkedList *list );

/*
 * 设置节点内容
 *
 * node   目标节点
 * data   数据内容
 */
Status set_list_element( LinkedListNode **pos, void *data );

/*
 * 获取节点内容
 *
 * node   目标节点
 */
void *get_list_element( LinkedListNode *pos );

/*
 * 链表遍历
 *
 * list    目标线性表指针
 * handle  函数句柄，对线性表中的每一个元素做相应的操作
 */
Status list_traverse( LinkedList *list, Status (*handle)(void *) );

#endif
