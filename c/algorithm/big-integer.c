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

BigInt *add(BigInt *num1, BigInt *num2);

int main(void)
{
  BigInt *n1 = read();
  BigInt *n2 = read();

  BigInt *sum = add(n1, n2);
  print(sum);

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

BigInt *add(BigInt *num1, BigInt *num2)
{
  num1 = reverse(num1);
  num2 = reverse(num2);

  int carry = 0;
  BigInt *head, *tail;

  head = NULL;
  while(num1 != NULL || num2 != NULL || carry != 0) {
    int n1, n2;
    n1 = (num1 != NULL) ? num1->data - '0' : 0;
    n2 = (num2 != NULL) ? num2->data - '0' : 0;

    int result = (n1 + n2 + carry) % 10;
    carry = (n1 + n2 + carry) / 10;

    BigInt *node = (BigInt *) malloc (sizeof(BigInt));
    node->data = result + '0';
    node->next = NULL;

    if(head == NULL) {
      head = node;
    } else {
      tail->next = node;
    }
    tail = node;

    if(num1 != NULL) {
      num1 = num1->next;
    }
    if(num2 != NULL) {
      num2 = num2->next;
    }
  }

  head = reverse(head);
  return head;
}
