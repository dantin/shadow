#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "array_list.h"

typedef struct ElementNode {
  int intVal;
} Element;

int equal( const void *value1, const void *value2 )
{
  Element *value = ( Element * ) value1;
  Element *base = ( Element * ) value2;

  if( value->intVal == base->intVal ) {
    return 0;
  } else if( value->intVal < base->intVal ) {
    return -1;
  } else {
    return 1;
  }
}

Status clear( void *elem )
{
  Element *element = ( Element * ) elem;

  if( element ) {
    free( element );
    return true;
  } else {
    return false;
  }
}

Status print_element( void *data ) {
  if( data == NULL ) {
    return false;
  }

  Element *elem = ( Element * ) data;
  printf( "{int: %d} ", elem->intVal);
  return true;
}

void print( ArrayList *list )
{
  printf( "[ " );
  if( !is_empty_list( list ) ) {
    list_traverse( list, print_element );
  } else {
    printf( "empty list " );
  }
  printf( "]\n" );
}

int main( void )
{
  ArrayList *list = NULL;

  printf( "初始化线性表\n" );
  init_list( &list );
  print( list );
  
  printf( "在表头增加新节点\n" );
  for( int i = 0; i < 10; i++ ) {
    Element *element = ( Element * ) malloc( sizeof( Element ) );
    element->intVal = i;
    ArrayListNode *node;
    if( make_list_node( &node, element ) ) {
      insert_list_head( list, &node );
    }
  }
  print( list );

  printf( "清理线性表\n" );
  clear_list( list, clear );
  print( list );
  
  printf( "%s线性表长度 %ld\n", is_empty_list( list ) ? "空" : "非空", list_size( list ) );

  printf( "在表尾增加新节点\n" );
  for( int i = 0; i < 10; i++ ) {
    Element *element = ( Element * ) malloc( sizeof( Element ) );
    element->intVal = i;
    ArrayListNode *node;
    if( make_list_node( &node, element ) ) {
      append_list_tail( list, &node );
    }
  }
  print( list );

  printf( "%s线性表长度 %ld\n", is_empty_list( list ) ? "空" : "非空", list_size( list ) );
  
  ArrayListNode *target;
  if( locate_list_node_by_position( list, 2, &target ) ) {
    printf( "找到下标为%d的节点：", 2 );
    print_element( target->data );
    printf( "\n" );
  }
  
  if( !locate_list_node_by_position( list, 10, &target ) ) {
    printf( "找不到下标为%d的节点\n", 10 );
  }
  
  Element *targetElement = ( Element * )malloc( sizeof( Element ) );
  targetElement->intVal = 3;
  target = locate_list_node_by_locator( list, targetElement, equal );
  if( ( ( Element * ) target->data)->intVal == targetElement->intVal ) {
    printf( "找到目标节点：\n" );
    print_element( target->data );
    printf( "\n" );
  }

  targetElement->intVal = 20;
  target = locate_list_node_by_locator( list, targetElement, equal );
  if( !target ) {
    printf( "找不到值为%d的目标节点：\n", targetElement->intVal );
    print_element( targetElement );
    printf( "\n" );
  }

  printf( "找表头节点\n" );
  target = get_list_head( list );
  print_element( target->data );
  printf( "\n" );

  if( !get_previous_node( list, target ) ) {
    printf( "表头无前驱节点\n" );
  }

  printf( "表头后继节点\n" );
  print_element( get_next_node( list, target )->data );
  printf( "\n" );

  printf( "找表尾节点\n" );
  target = get_list_tail( list );
  print_element( target->data );
  printf( "\n" );

  printf( "表尾前驱节点\n" );
  print_element( get_previous_node( list, target )->data );
  printf( "\n" );

  if( !get_next_node( list, target ) ) {
    printf( "表尾无后继节点\n" );
  }

  printf( "找表中节点，位置%d\n", 3 );
  locate_list_node_by_position( list, 3, &target );
  print_element( target->data );
  printf( "\n" );

  printf( "前驱节点：\n" );
  print_element( get_previous_node( list, target )->data );
  printf( "\n" );

  printf( "后继节点：\n" );
  print_element( get_next_node( list, target )->data );
  printf( "\n" );

  printf( "删除表头\n" );
  delete_list_head( list, &target );
  printf( "表头节点\n" );
  print_element( target->data );
  clear( target->data );
  destroy_list_node( &target );
  assert( !target );
  printf( "\n" );
  print( list );

  printf( "删除表尾\n" );
  remove_list_tail( list, &target );
  printf( "表尾节点\n" );
  print_element( target->data );
  clear( target->data );
  destroy_list_node( &target );
  assert( !target );
  printf( "\n" );
  print( list );

  locate_list_node_by_position( list, 3, &target );
  printf( "删除表中节点\n" );
  print_element( target->data );
  printf( "\n" );
  clear( target->data );
  delete_list_node( list, &target );
  print( list );
  destroy_list_node( &target );
  assert( !target );

  ArrayListNode *node;
  make_list_node( &node, targetElement );
  printf( "新建节点\n" );
  print_element( node->data );
  printf( "\n" );
  printf( "插入%d前\n", 2 );
  locate_list_node_by_position( list, 2, &target );
  insert_before_list_node( list, &target, &node );
  print( list );

  Element *another = ( Element * ) malloc( sizeof( Element ) );
  another->intVal = 30;
  make_list_node( &node, another );
  printf( "新建节点\n" );
  print_element( node->data );
  printf( "\n" );
  printf( "插入%d后\n", 2 );
  locate_list_node_by_position( list, 2, &target );
  append_after_list_node( list, &target, &node );
  print( list );

  printf( "获取位置为%d的节点内容\n", 2 );
  print_element( target->data );
  printf( " --> %d\n", ( ( Element * ) get_list_node_content( target ) )->intVal );

  printf( "清理位置为%d的节点内容\n", 2 );
  clear( get_list_node_content( target ) );
  printf( "设置位置为%d的节点内容为%d\n", 2, 40 );
  Element *third = ( Element * ) malloc( sizeof( Element ) );
  third->intVal = 40;
  set_list_node_content( target, third );
  print( list );

  third = NULL;
  
  clear_list( list, clear );
  destroy_list( &list );
    
  return 0;
}
