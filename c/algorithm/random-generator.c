/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : random-generator.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-06
 * description : 不重复随机数列生成算法
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEED 298

void generate_sequence(int *array, const int size);
void print(const int a[], const int length);
void swap(int *i, int *j);

int main(void)
{
  int size;

  printf("Please input the size: ");
  scanf("%d", &size);

  int *array = (int *) malloc (sizeof(int) * size);
  generate_sequence(array, size);

  print(array, size);
  putchar('\n');

  free(array);

  return 0;
}

void generate_sequence(int *array, const int size)
{
  int i;

  for(i = 0; i < size; i++) {
    array[i] = i;
  }

  srand(SEED);
  int end = size - 1;
  while(end > 0) {
    int num = rand() % end;
    swap(&array[num], &array[end--]);
  }

}

void swap(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

void print(const int *a, const int length)
{
  int i;

  for(i = 0; i < length; i++) {
    printf((i == length - 1) ? "%d" : "%d ", a[i]);
  }
}
