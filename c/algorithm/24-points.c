/*
 * Copyright (c) david
 * All rights reserved.
 *
 * filename    : 24-points.c
 * version     : 1.0
 * author      : david
 * date        : 2012-12-25
 * description : 计算24点的C语言代码
 * 
 *               树的深度优先算法 (DFS)
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {FALSE, TRUE} bool;

#define PRECISION 1E-6
#define SIZE 4
#define TARGET 24

typedef struct
{
  double  value;
  char    expression[20];
} Element;

bool game(Element *, int);

int main(void)
{
  int i;
  Element array[SIZE];

  for(i = 0; i < 4; i++) {
    int number;
    scanf("%d", &number);

    array[i].value = (double)number;
    sprintf(array[i].expression, "%d", number);
  }
  
  if(game(array, SIZE)) {
    printf("Done.\n");
  } else {
    printf("No Answer.\n");
  }

  return 0;
}

bool game(Element *array, int number)
{
  int i, j, k;
  Element temp[number - 1];

  if(number == 1) {
    if(fabs(array[0].value - TARGET) < PRECISION) {
      printf("%d = %s\n", TARGET, array[0].expression);
      return TRUE;
    } else {
      return FALSE;
    }
  }
  
  for(i = 0; i < number - 1; i++) {
    for(j = i + 1; j < number; j++) {
      int kk = 0;
      for(k = 0; k < number; k++) {
	if(k != i && k != j) {
	  temp[kk].value = array[k].value;
	  sprintf(temp[kk].expression, "%s", array[k].expression);
	  kk++;
	}
      }

      temp[number-2].value = array[i].value + array[j].value;
      sprintf(temp[number - 2].expression, "(%s + %s)", array[i].expression, array[j].expression);
      if(game(temp, number - 1))
	return TRUE;

      if(array[i].value > array[j].value) {
	temp[number - 2].value = array[i].value - array[j].value;
	sprintf(temp[number - 2].expression, "(%s - %s)", array[i].expression, array[j].expression);
      } else {
	temp[number - 2].value = array[j].value - array[i].value;
	sprintf(temp[number - 2].expression, "(%s - %s)", array[j].expression, array[i].expression);
      }
      if(game(temp, number - 1))
	return TRUE;

      temp[number - 2].value = array[i].value * array[j].value;
      sprintf(temp[number - 2].expression, "%s * %s", array[i].expression, array[j].expression);
      if(game(temp, number - 1))
	return TRUE;

      if(array[i].value != 0.0) {
	temp[number - 2].value = array[j].value / array[i].value;
	sprintf(temp[number - 2].expression, "%s / %s", array[j].expression, array[i].expression);
	if(game(temp, number - 1))
	  return TRUE;
      }
      if(array[j].value != 0.0) {
	temp[number - 2].value = array[i].value / array[j].value;
	sprintf(temp[number - 2].expression, "%s / %s", array[i].expression, array[j].expression);
	if(game(temp, number - 1))
	  return TRUE;
      }
    }
  }

  return FALSE;
}

