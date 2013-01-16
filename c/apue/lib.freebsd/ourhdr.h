/*
 * Copyright (c) APUE, all rights reserved.
 *
 * filename    : ourhdr.h
 * version     : 1.0
 * author      : david
 * date        : 2013-01-14
 * description : Error header
 *
 */
#ifndef __ourhdr_h
#define __ourhdr_h

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 4096

void err_ret(const char *, ...);
void err_sys(const char *, ...);
void err_quit(const char *, ...);

#endif
