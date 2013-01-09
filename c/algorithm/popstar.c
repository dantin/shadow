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

#define SIZE 10

#define EMPTY ' '

typedef enum{RED = 'R', YELLOW = 'Y', GREEN = 'G', PINK = 'P', VIOLET = 'V'} color;
typedef enum{FALSE, TRUE} bool;

typedef struct {
unsigned int row;
unsigned int column;
} position;

bool iscolor(char c);
void read(char board[]);
void print(char board[]);
int find(char board[]);
bool compare(char board[], int target, int source);
int row(int i);
int column(int i);

int main(void)
{
  char board[SIZE * SIZE];

  read(board);
  print(board);

  int p;
  if((p = find(board)) != -1) {
    printf("next target is (%d, %c)\n", row(p), column(p) + 'A');
  }
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
       (r >=0 && r < SIZE - 1 && compare(board, (r + 1) * SIZE + c, i))) {
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
