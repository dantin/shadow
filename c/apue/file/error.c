/*
 * Copyright (c) APUE, all rights reserved.
 *
 * filename    : error.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-14
 * description : Error functions
 *
 */
#include <errno.h>
#include <stdarg.h>
#include "ourhdr.h"

static void err_doit(int, const char *, va_list);

/*
 * Fatal error related to a system call
 * Print a message and terminate.
 */
void err_sys(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  err_doit(1, fmt, ap);
  va_end(ap);
  exit(1);
}

/*
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */
void err_quit(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  err_doit(0, fmt, ap);
  va_end(ap);
  exit(1);
}

/*
 * Print a message and return to caller.
 * Caller specifies "errnoflag".
 */
static void err_doit(int errnoflag, const char *fmt, va_list ap)
{
  int errno_save;
  char buf[MAXLINE];

  errno_save = errno; /* value caller might want printed */
  vsprintf(buf, fmt, ap);
  if(errnoflag)
    sprintf(buf+strlen(buf), ": %s", strerror(errno_save));
  strcat(buf, "\n");
  fflush(stdout); /* in case stdout and stderr are the same */
  fputs(buf, stderr);
  fflush(NULL);   /* flushes all stdio output streams */
  return;
}
