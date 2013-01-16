/*
 * Copyright (c) APUE, all rights reserved.
 *
 * filename    : shell1.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-16
 * description : Read commands from standard input and execute them
 *
 */
#include <sys/types.h>
#include <sys/wait.h>
#include "../lib.freebsd/ourhdr.h"

int main(void)
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  printf("%% "); /* print prompt */
  while(fgets(buf, MAXLINE, stdin) != NULL) {
    buf[strlen(buf) - 1] = '\0'; /* replace newline with null */

    if((pid = fork()) < 0) {
      err_sys("fork error");
    } else if(pid == 0){ /* child */
      execlp(buf, buf, (char *) 0);
      err_ret("couldn't execute: %s", buf);
      exit(127);
    }
    if((pid = waitpid(pid, &status, 0)) < 0) { /* parent */
      err_sys("waitpid error");
    }

    printf("%% ");
  }

  exit(0);
}
