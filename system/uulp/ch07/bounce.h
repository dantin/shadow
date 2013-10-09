#define BLANK      ' '
#define DEF_SYMBOL 'o'

#define TOP_ROW    5
#define BOT_ROW    20
#define LEFT_EDGE  10
#define RIGHT_EDGE 70

#define X_INT 10
#define Y_INT 10

#define TICKS_PER_SEC 50

#define X_TTM 5
#define Y_TTM 8

struct ppball {
  int y_pos, x_pos;
  int y_ttm, x_ttm;
  int y_ttg, x_ttg;
  int y_dir, x_dir;
  char symbol;
};
