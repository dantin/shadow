/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : max-subsequence-sum.c
 * version     : 1.0
 * author      : david
 * date        : 2013-01-04
 * description : 求连续子数组最大和
 *
 */
#include <stdio.h>
#include <limits.h>

int max_subsequence_sum_o_n3(const int *array, const int SIZE);
int max_subsequence_sum_o_n2(const int *array, const int SIZE);
int max_subsequence_sum_o_nlogn(const int *array, int left, int right);
int max_subsequence_sum_o_n1(const int *array, const int SIZE);

int main(void)
{
  int a[10] = {1, -2, 3, 10, -4, 7, 2, -5};

  int n3 = max_subsequence_sum_o_n3(a, 10);
  int n2 = max_subsequence_sum_o_n2(a, 10);
  int nlogn = max_subsequence_sum_o_nlogn(a, 0, 9);
  int n1 = max_subsequence_sum_o_n1(a, 10);
  printf(" Max subsequence sum:\n");
  printf("  n3:    %d\n", n3);
  printf("  n2:    %d\n", n2);
  printf("  nlogn: %d\n", nlogn);
  printf("  n1:    %d\n", n1);

  return 0;
}

/*
 * time efficiency: O(n*n*n)
 */
int max_subsequence_sum_o_n3(const int a[], const int SIZE)
{
  int sum, max, i, j, k;

  max = INT_MIN;
  for(i = 0; i < SIZE; i++) {
    for(j = i; j < SIZE; j++) {
      sum = 0;
      for(k = i; k <= j; k++) {
	sum += a[k];
      }

      if(sum > max) {
	max = sum;
      }
    }
  }

  return max;
}

/*
 * time efficiency: O(n*n)
 */
int max_subsequence_sum_o_n2(const int a[], const int SIZE)
{
  int sum, max, i, j, k;

  max = INT_MIN;
  for(i = 0; i < SIZE; i++) {
    sum = 0;
    for(j = i; j < SIZE; j++) {
      sum += a[j];
      if(sum > max) {
	max = sum;
      }
    }
  }

  return max;
}
/*
 * time efficiency: O(n*log(n))
 */
int max_subsequence_sum_o_nlogn(const int a[], int left, int right)
{
  int maxl, maxr;
  int maxlb, maxrb;
  int suml, sumr;
  int c, i;

  if(left == right) {
    if(a[left] > 0) {
      return a[left];
    } else {
      return 0;
    }
  }

  c = (left + right) / 2;
  maxl = max_subsequence_sum_o_nlogn(a, left, c);
  maxr = max_subsequence_sum_o_nlogn(a, c + 1, right);

  maxlb = INT_MIN;
  suml = 0;
  for(i = c; i >= left; i--) {
    suml += a[i];
    if(suml > maxlb) {
      maxlb = suml;
    }
  }

  maxrb = INT_MIN;
  sumr = 0;
  for(i = c + 1; i <= right; i++) {
    sumr += a[i];
    if(sumr > maxrb) {
      maxrb = sumr;
    }
  }

  int max1 = maxl > maxr ? maxl : maxr;
  int max2 = maxlb + maxrb;
  return max1 > max2 ? max1 : max2;
}

/*
 * time efficiency: O(n)
 */
int max_subsequence_sum_o_n1(const int a[], const int SIZE)
{
  int sum, max, i;

  sum = 0;
  max = INT_MIN;
  for(i = 0; i < SIZE; i++) {
    sum += a[i];
    if(sum > max) {
      max = sum;
    } else if(sum < 0) {
      sum = 0;
    }
  }

  return max;
}
