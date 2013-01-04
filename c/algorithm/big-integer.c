/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : big-integer.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-04
 * description : 大数相加
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
  char data;
  struct Node *next;
} BigInt;

BigInt *read(void);
void print(BigInt *num);
BigInt *reverse(BigInt *p);

int main(void)
{
  BigInt *n1 = read();
  print(n1);

  n1 = reverse(n1);
  print(n1);

  n1 = reverse(n1);
  print(n1);

  return 0;
}

BigInt *read(void)
{
  BigInt *head, *tail;
  int c;

  tail = head = NULL;

  while((c = getchar()) != EOF) {
    if(!isdigit(c)) {
      break;
    }

    BigInt *node = (BigInt *) malloc (sizeof(BigInt));
    node->data = c;
    node->next = NULL;

    if(head == NULL) {
      head = node;
    } else {
      tail->next = node;
    }
    tail = node;
  }

  return head;
}

void print(BigInt *p)
{
  while(p != NULL) {
    putchar(p->data);
    p = p->next;
  }
}

BigInt *reverse(BigInt *head)
{
  if(head == NULL) {
    return head;
  }

  BigInt *previous, *current, *next;
  previous = head;
  current = head->next;

  while(current) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  head->next = NULL;

  return previous;
}
