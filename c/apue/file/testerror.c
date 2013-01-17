/*
 * Copyright (c) APUE, all rights reserved.
 *
 * filename    : testerror.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-16
 * description : Demonstrate strerror and perror
 *
 */
#include <errno.h>
#include "ourhdr.h"

int main(int argc, char *argv[])
{
  fprintf(stderr, "EACCES: %s\n", strerror(EACCES));

  errno = ENOENT;
  perror(argv[0]);

  exit(0);
}
