#include <stdio.h>

#define ROWS 4
#define COLS 4


typedef struct {
  int x;
  int y;
} Pos;





Pos get_empty_pos(int m[ROWS][COLS]){
  Pos pos;
  for(int i=0; i<ROWS; i++)
    for(int j=0; j<COLS; j++)
      if(m[i][j] == 0){
	pos.x = i;
	pos.y = j;
	break;}
  return pos;
}


void print_matrix(int m[ROWS][COLS]){
  for(int i=0; i<ROWS; i++)
    printf("%d %d %d %d\n", m[i][0], m[i][1], m[i][2], m[i][3]);
}


		   




int main(){

  int solution[4][4]= {{1,2,3,4},
		       {5,6,7,8},
		       {9,10,11,12},
		       {13,14,15,0}};

  print_matrix(solution);

  Pos pos = get_empty_pos(solution);
  printf("\nPosicao da peça 0 x:%d y:%d\n", pos.x, pos.y);
  
  return 0;
}
