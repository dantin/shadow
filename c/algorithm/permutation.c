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

int permutation(char per[], int m, int len);

int main(void)
{
  char per[] = "ABCD";

  int count = permutation(per, 0, strlen(per));
  printf("The total: %d\n", count);

  return 0;
}

int permutation(char per[], int m, int len)
{
  static int count = 0;
  int i;
  char tmp;

  if(m < len - 1) {
    permutation(per, m + 1, len);
    for(i = m + 1; i < len; i++) {
      tmp = per[m];
      per[m] = per[i];
      per[i] = tmp;
      permutation(per, m + 1, len);

      tmp = per[m];
      per[m] = per[i];
      per[i] = tmp;
    }
  } else {
    ++count;
    printf("%s\n", per);
  }

  return count;
}


