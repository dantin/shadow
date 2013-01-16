/*
 * Copyright (c) APUE, all rights reserved.
 *
 * filename    : my.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-16
 * description : Copy STDIN to STDOUT
 */
#include "ourhdr.h"

#define BUFFERSIZE 8192

int main(void)
{
  int n;
  char buf[BUFFERSIZE];

  while((n = read(STDIN_FILENO, buf, BUFFERSIZE)) > 0)
    if(write(STDOUT_FILENO, buf, n) != n)
      err_sys("write error");

  if(n < 0)
    err_sys("read error");

  exit(0);
}
