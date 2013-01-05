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

void print(const char *message, const int a[], const int length);
void qsort(int a[], int left, int right);
void swap(int a[], int i, int j);

int main(void)
{
  int array[] = {3, 7, 8, 5, 2, 1, 9, 5, 4};
  const int length = sizeof(array) / sizeof(int);

  print(" Original array:  ", array, length);
  qsort(array, 0, length - 1);
  print(" After Quick sort:", array, length);

  return 0;
}

void print(const char *message, const int a[], const int length)
{
  int i;

  printf("%s [", message);
  for(i = 0; i < length; i++) {
    printf((i == length - 1) ? "%2d" : "%2d,", a[i]);
  }
  printf("]\n");
}

void qsort(int a[], int left, int right)
{
  int i, last;

  if(left >= right) {
    return;
  }

  swap(a, left, (left + right) / 2);

  last = left;
  for(i = left + 1; i <= right; i++) {
    if(a[i] < a[left]) {
      swap(a, ++last, i);
    }
  }

  swap(a, left, last);

  qsort(a, left, last - 1);
  qsort(a, last + 1, right);
}

void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}
