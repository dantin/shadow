/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : hanoi.c
 * version     : 1.0
 * author      : david
 * date        : 2012-12-24
 * description : 汉诺塔
 *
 */
#include <stdio.h>

int main(void)
{
  void hanoi(int n, char one, char two, char three);

  int m;
  printf("Input the number of diskes: ");
  scanf("%d", &m);
  printf("The step to move %d diskes:\n", m);
  hanoi(m, 'A', 'B', 'C');

  return 0;
}

void hanoi(int n, char one, char two, char three)
{
  void move(char x, char y);

  if(n == 1) {
    move(one, three);
  } else {
    hanoi(n - 1, one, three, two);
    move(one, three);
    hanoi(n - 1, two, one, three);
  }
}

void move(char x, char y)
{
  printf("%c --> %c\n", x, y);
} 
