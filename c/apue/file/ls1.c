/*
 * Copyright (c) APUE, all rights reserved.
 *
 * filename    : ls1.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-14
 * description : List all the files in a directory
 *
 */
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "ourhdr.h"

int main(int argc, char *argv[])
{
  DIR * dp;
  struct dirent *dirp;

  if(argc != 2)
    err_quit("a single argument (the directory name) is required");

  if((dp = opendir(argv[1])) == NULL)
    err_sys("can't open %s", argv[1]);

  while((dirp = readdir(dp)) != NULL)
    printf("%s\n", dirp->d_name);

  closedir(dp);
  exit(0);
}
