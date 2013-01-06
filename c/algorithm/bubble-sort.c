/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : bubble-sort.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-06
 * description : 冒泡排序算法
 *
 */
#include <stdio.h>

void bsort(int a[], const int length);
void print(const char *message, const int a[], const int length);

void swap(int *i, int *j);

int main(void)
{
  int array[] = {3, 7, 8, 5, 2, 1, 9, 5, 4};
  const int length = sizeof(array) / sizeof(int);

  print(" Original array:   ", array, length);
  bsort(array, length);
  print(" After Bubble sort:", array, length);

  return 0;
}

void bsort(int a[], const int length)
{
  int i, j;

  for(i = 0; i < length; i++) {
    for(j = 0; j < length - i - 1; j++) {
      if(a[j] > a[j + 1]) {
	swap(&a[j], &a[j + 1]);
      }
    }
  }
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

void swap(int *i, int *j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}
