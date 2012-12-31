/*
 * Copyright (c) david
 * All rights reserved.
 *
 * filename    : bulbs.c
 * version     : 1.0
 * author      : david
 * date        : 2012-12-28
 * description : 100 bulbs, which one is light?
 *
 */
#include <stdio.h>

#define SIZE 101

typedef enum {FALSE, TRUE} bool;

int main(void)
{
  int i, j;
  bool lights[SIZE] = {FALSE};

  for(i = 1; i < SIZE; i++) {
    for(j = 1; j < SIZE; j++) {
      if(j % i == 0) {
	lights[j] = !lights[j];
      }
    }
  }

  for(i = 1; i < SIZE; i++) {
    if(lights[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}

