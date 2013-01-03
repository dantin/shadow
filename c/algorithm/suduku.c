/*
 * Copyright (c) david, all rights reserved.
 *
 * filename    : suduku.c
 * version     : 1.0
 * author      : david
 * date        : 2012-12-26
 * description : 计算数独的C语言代码
 *
 */
#include <stdio.h>
#include <math.h>

#define SIZE 9

// Array that contains values of all 81 cells in the grid.
static int cells[SIZE * SIZE];

// A set of bit-vectors that represent the known values for each column.
// Specifically, if column c contains the digits d1 and d2,
//   colsSet[c] = 2^(d1-1)|2^(d2-1)
// For example, if column 0 contains the values 1 and 4, colsSet[0] = 9.
// The information in this variable is redundant with the information
// in the cells variable.
// The purpose of this variable is to reduce the cost of determining 
// whether a particular digit can be set in a particular cell.
static int cols[SIZE];
// This purpose and behavior of this variable is similar to cols.
static int rows[SIZE];
// This purpose and behavior of this variable is similar to cols.
static int subgrids[SIZE];

typedef enum {FALSE, TRUE} bool;

void suduku(void);

int find(void);
void read(void);
bool set(const int loc, const int num);
void unset(const int loc);
void print(void);

int main(void)
{
  read();
  
  suduku();

  return 0;
}

/*
 * Recursive routine that implements the bifurcation algorithm
 */
void suduku(void)
{
  static int found = 0;

  if(found >= 1) {
    return;
  }

  int loc = find();
  if(loc < 0) {
    found++;
    print();
    return;
  }

  int n;
  for(n = 1; n < 10; n++) {
    if(set(loc, n)) {
      suduku();
      unset(loc);
    }
  }
}

/*
 * Finds an empty cell
 */
int find(void)
{
  int i;

  for(i = 0; i < SIZE * SIZE; i++) {
    if(cells[i] == 0) {
      return i;
    }
  }

  return -1;
}

/*
 * This method returns a grid of givens and empty cells ready to be solved.
 * The cells containing givens have values between 1 and 9.
 * Empty cells have the value 0.
 * 
 * Characters are read one at a time from the input stream and placed into
 * the grid in left-to-right and top-down order.
 *  - The characters 0 or . indicates an empty cell.
 *  - The characters 1 to 9 indicates a given.
 *  - The character # is used for comments; subsequent characters are ignored
 *    until a newline is encountered. 
 *  - All other characters are simply ignored.
 */
void read(void)
{
  int loc, ch;

  for(loc = 0; loc < SIZE * SIZE;) {
    int ch = getchar();

    if(ch == EOF) {
      break;
    }

    if(ch == '#') {
      while((ch = getchar()) && ch >= 0 && ch != '\n' && ch != '\r')
	;
    } else if(ch >= '1' && ch <= '9') {
      set(loc, ch - '0');
      loc++;
    } else if(ch == '.' || ch == '0') {
      loc++;
    }
  }
}

/*
 * Sets a number in a cell. This method checks to see if
 *  1. the cell is empty
 *  2. the cell is allowed to contain the specified number.
 *     E.g. if the number is 5 but the row already has a 5, the cell will not
 *     be set and false is returned.
 */
bool set(const int loc, const int num)
{
  int r = loc / SIZE;
  int c = loc % SIZE;
  int b = (r / 3) * 3 + c / 3;

  bool valid = cells[loc] == 0
    && (cols[c] & (1 << num)) == 0
    && (rows[r] & (1 << num)) == 0
    && (subgrids[b] & (1 << num)) == 0;

  if(!valid) {
    return FALSE;
  }

  cells[loc] = num;
  cols[c] |= (1 << num);
  rows[r] |= (1 << num);
  subgrids[b] |= (1 << num);

  return TRUE;
}

/*
 * remove a number from cell
 */
void unset(const int loc)
{
  int r = loc / SIZE;
  int c = loc % SIZE;
  int b = (r / 3) * 3 + c / 3;

  int num = cells[loc];
  cells[loc] = 0;
  cols[c] ^= (1 << num);
  rows[r] ^= (1 << num);
  subgrids[b] ^= (1 << num);
}

/*
 * print the string representing the current contents of the grid
 */
void print(void)
{
  int r, c;

  for(r = 0; r < SIZE; r++) {
    if(r % 3 == 0) {
      printf("-------------------------\n");
    }
    for(c = 0; c < SIZE; c++) {
      if(c % 3 == 0) {
	printf("| ");
      }
      int num = cells[r * 9 + c];
      if(num == 0) {
	printf(". ");
      } else {
	printf("%d ", num);
      }
    }
    printf("|\n");
  }
  printf("-------------------------\n");
}

