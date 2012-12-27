#include <stdio.h>
#include <math.h>

#define SIZE 9

static int cells[SIZE * SIZE];

static int cols[SIZE];
static int rows[SIZE];
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
 * set a number into the cell
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
