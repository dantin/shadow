/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : combination.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-03
 * description : 组合算法
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int combination(char a[], int n, int m, int subscript[], const int SIZE);

int main(void)
{
  char *ps = "ABCD";
  const int SIZE = 3;

  int *pi = (int *)malloc(sizeof(int) * SIZE);
  int count = combination(ps, strlen(ps), SIZE, pi, SIZE);
  printf(" Total combination: %d\n", count);

  free(pi);

  return 0;
}

int combination(char a[], int n, int m, int subscript[], const int SIZE)
{
  static int count = 0;
  int i, j;
  for(i = n; i >= m; i--) {
    subscript[m - 1] = i - 1;
    if(m > 1) {
      combination(a, i - 1, m - 1, subscript, SIZE);
    } else {
      for(j = 0; j < SIZE; j++) {
	printf("%c ", a[subscript[j]]);
      }
      printf("\n");
      count++;
    }
  }

  return count;
}
