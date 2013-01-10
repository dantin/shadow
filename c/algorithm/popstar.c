/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : popstar.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-09
 * description : PopStar! 游戏的解题算法
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

#define EMPTY ' '

typedef enum{RED = 'R', YELLOW = 'Y', GREEN = 'G', PINK = 'P', VIOLET = 'V'} color;
typedef enum{FALSE, TRUE} bool;

typedef struct lnode {
  int location;
  char data;
  struct lnode *next;
} list;

bool iscolor(char c);
void read(char board[]);
void print(char board[]);
int find(char board[]);
bool compare(char board[], int target, int source);
int row(int i);
int column(int i);
void set(char board[], int location, list **visited);
list *make_node(int location, char data);
void push(list **stack, list *node);
list *pop(list **stack);
void travel(const list *head);
bool exist(const list *head, const int location);
void clear(char board[], char result[]);
void swap(char *i, char *j);

int main(void)
{
  char board[SIZE * SIZE];

  read(board);
  print(board);

  int p = 3 * SIZE + 3;
  //if((p = find(board)) != -1) {
    if(p != -1) {
    printf("next target is (%d, %c)\n", row(p), column(p) + 'A');
  }

  printf("\n---\n");
  list *visited = NULL;
  set(board, p, &visited);
  //travel(visited);

  printf("\n---\n");
  print(board);

  printf("\n---\n");
  char to[SIZE * SIZE];
  clear(board, to);
  print(to);

  return 0;
}

bool iscolor(char c)
{
  switch(c) {
  case RED:
  case YELLOW:
  case GREEN:
  case PINK:
  case VIOLET:
    return TRUE;
  default:
    return FALSE;
  }
}

void read(char board[])
{
  unsigned int loc;
  const unsigned int length = SIZE * SIZE;

  for(loc = 0; loc < length; loc++) {
    board[loc] = EMPTY;
  }
  for(loc = 0; loc < length;) {
    int ch = getchar();

    if(ch == EOF) {
      break;
    }

    if(ch == '#') {
      while((ch = getchar()) && ch != '\n' && ch != '\r')
	;
    } else if(iscolor(ch)) {
      board[loc++] = ch;
    }
  }
}

void print(char board[])
{
  int r, c;

  for(c = 0; c <= SIZE; c ++) {
    printf((c == 0) ? "   " : "  %c ", 'A' - 1 + c);
  }
  printf("\n");

  for(c = 0; c <= SIZE; c++) {
    printf((c == 0) ? "   +" : "---+");
  }
  printf("\n");

  for(r = 0; r < SIZE; r++) {
    printf(" %d ", r);
    for(c = 0; c < SIZE; c++) {
      char chess = board[r * SIZE + c];
      printf((c == SIZE - 1) ? "| %c |" : "| %c ", chess);
    }
    printf("\n");

    for(c = 0; c <= SIZE; c++) {
      printf((c == 0) ? "   +" : "---+");
    }
    printf("\n");
  }
}

int find(char board[])
{
  int i;

  for(i = 0; i < SIZE * SIZE; i++) {
    int c = column(i);
    int r = row(i);

    if((c > 0 && c < SIZE && compare(board, r * SIZE + c - 1, i)) ||
       (r > 0 && r < SIZE && compare(board, (r - 1) * SIZE + c, i)) ||
       (c >= 0 && c < SIZE - 1 && compare(board, r * SIZE + c + 1, i)) ||
       (r >= 0 && r < SIZE - 1 && compare(board, (r + 1) * SIZE + c, i))) {
	return i;
    }
  }

  return -1;
}

/*
 * compare board[target] with board[source]
 */
bool compare(char board[], int target, int source)
{
  return board[target] != EMPTY && board[target] == board[source];
}

int row(int i)
{
  return i / SIZE;
}

int column(int i)
{
  return i % SIZE;
}

void set(char board[], int location, list **visited)
{
  list *stack = NULL;
  *visited = NULL;

  push(&stack, make_node(location, board[location]));
  while(stack != NULL) {
    list *node = pop(&stack);
    int c = column(node->location);
    int r = row(node->location);
    int found;

    if(c > 0 && c < SIZE && compare(board, r * SIZE + c - 1, node->location) && !exist(*visited, node->location)) {
      found = r * SIZE + c - 1;
      push(&stack, make_node(found, board[found]));
    }
    if(r > 0 && r < SIZE && compare(board, (r - 1) * SIZE + c, node->location) && !exist(*visited, node->location)) {
      found = (r - 1) * SIZE + c;
      push(&stack, make_node(found, board[found]));
    }
    if(c >= 0 && c < SIZE - 1 && compare(board, r * SIZE + c + 1, node->location) && !exist(*visited, node->location)) {
      found = r * SIZE + c + 1;
      push(&stack, make_node(found, board[found]));
    }
    if(r >= 0 && r < SIZE - 1 && compare(board, (r + 1) * SIZE + c, node->location) && !exist(*visited, node->location)) {
      found = (r + 1) * SIZE + c;
      push(&stack, make_node(found, board[found]));
    }

    if(!exist(*visited, node->location)) {
      node->next = NULL;
      push(visited, node);
      board[node->location] = EMPTY;
    }
  }

}

list *make_node(int location, char data)
{
  list *node = (list *) malloc(sizeof(list));
  node->location = location;
  node->data = data;
  node->next = NULL;

  return node;
}

void push(list **stack, list *node)
{
  node->next = *stack;
  *stack = node;
}

list *pop(list **stack)
{
  list *element = *stack;
  *stack = (*stack)->next;

  element->next = NULL;
  return element;
}

void travel(const list *head)
{
  while(head) {
    printf("<%d, %c> : %c\n", row(head->location), 'A' + column(head->location), head->data);
    head = head->next;
  }
}

bool exist(const list *head, const int location)
{
  while(head) {
    if(head->location == location) {
      return TRUE;
    }
    head = head->next;
  }

  return FALSE;
}

void clear(char from[], char to[])
{
  int r, c, i;
  // copy
  for(i = 0; i < SIZE * SIZE; i++) {
    to[i] = from [i];
  }

  for(c = 0; c < SIZE; c++) {
    for(i = 0; i < SIZE - 1 ; i++) {
      for(r = SIZE - 1; r > 0; r --) {
	if(to[r * SIZE + c] == EMPTY) {
	  swap(&to[r * SIZE + c], &to[(r - 1) * SIZE + c]);
	}
      }
    }
  }

  for(c = 0; c < SIZE; c++) {
    bool is_clear = TRUE;
    for(r = 0; r < SIZE; r ++) {
      is_clear = is_clear && (to[r * SIZE + c] == EMPTY);
    }
    if(!is_clear) {
      continue;
    }
    for(i = 0; i < SIZE; i++) {
      int j;
      for(j = c; j < SIZE - 1; j++) {
	swap(&to[i * SIZE + j], &to[i * SIZE + j + 1]);
      }
    }
  }
}

void swap(char *i, char *j)
{
  char temp = *i;
  *i = *j;
  *j = temp;
}
