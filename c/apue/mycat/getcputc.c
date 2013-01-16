/*
 * Copyright (c) APUE, all rights reserved.
 *
 * filename    : getcputc.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-16
 * description : Copy STDIN to STDOUT
 */
#include "../lib.freebsd/ourhdr.h"

int main(void)
{
  int c;

  while((c = getc(stdin)) != EOF)
    if(putc(c, stdout) == EOF)
      err_sys("output error");

  if(ferror(stdin))
    err_sys("input error");

  exit(0);
}
