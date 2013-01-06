/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : quick-sort.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-05
 * description : 快速排序算法
 *
 */
#include <stdio.h>
#include <stdlib.h>

void print(const char *message, const int a[], const int length);
void quick_sort(int a[], int left, int right);
void swap(int *i, int *j);

void read(int *array, const int length);

int main(void)
{
  int length;
  scanf("%d", &length);

  int *array = (int *) malloc (sizeof(int) * length);

  read(array, length);

  print(" Original array:  ", array, length);

  quick_sort(array, 0, length);

  print(" After Quick sort:", array, length);

  free(array);

  return 0;
}

void print(const char *message, const int a[], const int length)
{
  int i;

  printf("%s [", message);
  for(i = 0; i < length; i++) {
    printf((i == length - 1) ? "%2d" : "%2d, ", a[i]);
  }
  printf("]\n");
}

void quick_sort(int a[], int left, int right)
{
  int i, last;

  if(left >= right) {
    return;
  }

  last = left;
  for(i = left + 1; i < right; i++) {
    if(a[i] < a[left]) {
      swap(&a[++last], &a[i]);
    }
  }

  swap(&a[left], &a[last]);

  quick_sort(a, left, last);
  quick_sort(a, last + 1, right);
}

void swap(int *i, int *j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

void read(int *array, const int length)
{
  int num, i = 0;

  while(scanf("%d", &num) && i < length) {
    array[i++] = num;
  }
}
