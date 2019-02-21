#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

#define matrix m[ROWS][COLS]


typedef struct {
  int x;
  int y;
} Pos;




// converte matriz num array com os elementos em posicoes contiguas
int *matrix_to_array(int m[ROWS][COLS]){

  size_t s = ROWS*COLS;
  int *array = (int*)malloc(sizeof(int)*s); // 4*4 ints = 16 ints

  int k = 0;
  for(int i=0;i<ROWS;i++)
    for(int j=0;j<COLS;j++)
      array[k++] = m[i][j];
  
  return array;
}



// retorna posicao sem peça (peça '0')
Pos get_empty_pos(int m[ROWS][COLS]){
  Pos pos = {-1, -1};
  for(int i=0; i<ROWS; i++)
    for(int j=0; j<COLS; j++)
      if(m[i][j] == 0){
	pos.x = i;
	pos.y = j;
	return pos;}  
  return pos;
}



// escreve a matriz no terminal
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
  printf("Posicao da peça 0 x:%d y:%d\n", pos.x, pos.y);

  int *a = matrix_to_array(solution);

  for(int i=0; i<ROWS*COLS; i++)
    printf("%d ", *(a+i));
  printf("\n");
  
  
  return 0;
}
