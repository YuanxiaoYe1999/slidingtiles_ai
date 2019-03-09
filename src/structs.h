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


// Node Struct
typedef struct {
  int array[SIZE]; // 4 * 16 Bytes
  int depth, f; // 4 * 2 Bytes
  Move move; // enum (assume sizeof int) 4 bytes
  struct Array *parent; // pointer in 32 bit program, 4 bytes
} Array; // total: 80 Bytes per array instance

