/*
 * Copyright (c) APUE, all rights reserved.
 *
 * filename    : uidgid.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-16
 * description : Print user ID and group ID
 *
 */
#include "ourhdr.h"

int main(void)
{
  printf("uid = %d, gid = %d\n", getuid(), getgid());

  exit(0);
}
