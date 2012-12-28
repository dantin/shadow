/*
 * Copyright (c) david
 * All rights reserved.
 *
 * filename    : nQueens.c
 * version     : 1.0
 * author      : david
 * date        : 2012-12-27
 * description : 在n*n (n=1 or n>=4 )的棋盘上放置n个皇后，如果在同一行，同一列，同一对角线上都不存在两个皇后，那么这个棋盘格局就是n皇后的一个解。
 *
 */
#include <stdio.h>
#include <math.h>

// 皇后数=棋盘行列数
#define N 8

// a[i]为第i行皇后所在列
int a[N];

/*
 * 图形化输出
 */
void show(void)
{
  int i;
  int p, q;
  int b[N][N] = {0};

  static int t = 1;
  printf("%d th's solution: ", t++);

  for(i = 0; i < N; i++) {
    b[i][a[i]] = 1;
    printf("(%d, %d) ", i, a[i]);
  }
  printf("\n");

  for(p = 0; p < N; p++) {
    for(q = 0; q < N; q++) {
      if(b[p][q] == 1) {
	printf("x");
      } else {
	printf("o");
      }
    }
    printf("\n");
  }
}

/*
 * 满足条件返回1，否则返回0
 */
int check(int n)
{
  int i;

  for(i = 0; i < n; i++) {
    // at the same column or diagonal
    if(a[i] == a[n] || fabs(n - i) == fabs(a[i] - a[n])) {
      return 0;
    }
  }

  return 1;
}

/*
 * 在第n行放置第n个皇后
 */
void put(int n)
{
  int i;

  if(n == N)
    return;

  for(i = 0; i < N; i++) {
    a[n] = i;
    if(check(n)) { // 位置合法
      if(n == N - 1) { // 皇后全部放置完毕
	show();
      } else {
	put(n + 1);
      }
    }
  }
}

int main()
{
  put(0);

  return 0;
}
