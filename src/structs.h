#define ISEVEN(n)  ((n%2 == 0) ? 1 : 0)
#define ISODD(n)   ((n%2 != 0) ? 1 : 0)

typedef struct {
  int x;
  int y;
} Pos;

typedef enum {
  UP, DOWN, LEFT, RIGHT,
  NONE
} Move;

typedef struct {
  int array[SIZE];
  int depth, f;
  Move move;
  struct Array *parent;
} Array;
