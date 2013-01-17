/*
 * Copyright (c) APUE, all rights reserved.
 *
 * filename    : shell2.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-16
 * description : Read commands from standard input and execute them with signal
 *
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "ourhdr.h"

static void sig_init(int); /* our signal-catching function */

int main(void)
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  if(signal(SIGINT, sig_init) == SIG_ERR) {
    err_sys("signal error");
  }

  printf("%% ");
  while(fgets(buf, MAXLINE, stdin) != NULL) {
    buf[strlen(buf) - 1] = '\0';

    if((pid = fork() < 0)) {
      err_sys("fork error");
    } else if(pid == 0) {
      execlp(buf, buf, (char *) 0);
      err_ret("couldn't execute: %s", buf);
      exit(127);
    }

    if((pid = waitpid(pid, &status, 0)) < 0) {
      err_sys("waiting error");
    }

    printf("%% ");
  }

  exit(0);
}

void sig_init(int signo)
{
  printf("interrupt\n%%");
}
