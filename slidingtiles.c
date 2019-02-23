#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


#define SIZE 16

typedef struct {
  int x; int y;
} Pos;




/*
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

*/




// escreve a configuraçao no terminal
void print_matrix(int m[SIZE]){
  int i = 0;
  while(i < SIZE/4){
    printf("%d %d %d %d\n", m[4*i + 0], m[4*i + 1], m[4*i + 2], m[4*i + 3]);
    i++;
  }
}





int main(){

  int initial[SIZE];
  int final[SIZE];

  int i;
  // recebe linhas de config. inicial e final
  for(i=0; i<SIZE; i++)
    scanf("%d", &initial[i]);

  for(i=0; i<SIZE; i++)
    scanf("%d", &final[i]);


  

  // colocar Arrays de inteiros na fila
  Array a1, a2;
  memcpy(a1.array, initial, sizeof(Array));
  memcpy(a2.array, final, sizeof(Array));
     
  QUEUE *q = mk_empty_queue(1024);

  enqueue(a1, q);
  enqueue(a2, q);
  
  Array x = dequeue(q);
  Array y = dequeue(q);

  
  for(i=0; i<SIZE; i++)
    printf("%d ", x.array[i]);

    
  for(i=0; i<SIZE; i++)
    printf("%d ", y.array[i]);


  return 0;
  
}
		   

