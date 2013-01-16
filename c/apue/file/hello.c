/*
 * Copyright (c) APUE, all rights reserved.
 *
 * filename    : hello.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-16
 * description : Print the process ID
 *
 */
#include "../lib.freebsd/ourhdr.h"

int main(void)
{
  printf("Hello world from process ID %d\n", getpid());

  exit(0);
}
