/*
 * Copyright (c) david
 * All rights reserved.
 *
 * filename    : permutation.c
 * version     : 1.0
 * author      : david
 * date        : 2012-12-29
 * description : 全排列算法
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b);
int permutation(char per[], int m, int len);

int main(void)
{
  char per[] = "ABCD";

  int count = permutation(per, 0, strlen(per) - 1);
  printf("The total: %d\n", count);

  return 0;
}

void swap(char *a, char *b)
{
  char tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

int permutation(char per[], int m, int len)
{
  static int count = 0;
  int i;

  if(m > len) {
    printf("%s\n", per);
    ++count;
  } else {

    for(i = m; i <= len; i++) {
      swap(&per[m], &per[i]);
      permutation(per, m + 1, len);
      swap(&per[m], &per[i]);
    }
  }

  return count;
}


