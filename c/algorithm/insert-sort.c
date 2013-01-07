/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : insert-sort.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-07
 * description : 插入排序算法
 *
 */
#include <stdio.h>
#include <stdlib.h>

void insert_sort(int a[], const int length);
void print(const char *message, const int a[], const int length);
void swap(int *i, int *j);
void read(int *array, const int length);

int main(void)
{
  int length;
  scanf("%d", &length);

  int *array = (int *) malloc (sizeof(int) * length);

  read(array, length);

  print(" Original array:    ", array, length);

  insert_sort(array, length);

  print(" After Insert sort: ", array, length);

  free(array);

  return 0;
}

void insert_sort(int a[], const int length)
{
  int i, j;
  int temp;

  for(i = 1; i < length; i++) {
    temp = a[i];
    for(j = i; j > 0 && a[j - 1] > temp; j--) {
      swap(&a[j], &a[j - 1]);
    }
    a[j] = temp;
  }
}

void print(const char *message, const int a[], const int length)
{
  int i;

  printf("%s [", message);
  for(i = 0; i < length; i++) {
    printf((i == length - 1) ? "%d" : "%d, ", a[i]);
  }
  printf("]\n");
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
