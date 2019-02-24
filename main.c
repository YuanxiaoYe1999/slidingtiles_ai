#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

#include "structs.h"
#include "queue.h"
#include "stack.h"
#include "utils.h"
#include "operators.h"



int main(){

  Array x;
  Array y;

  int i,j;
  for(i=0; i<SIZE; i++) scanf("%d", &x.array[i]);
  for(i=0; i<SIZE; i++) scanf("%d", &y.array[i]);

  print(x);

  int **m;

  m = array_to_matrix(x);

  // call by reference >:(
  Array tmp = matrix_to_array(move_up(m));
  print(tmp);
  print(matrix_to_array(m));
  

  return 0;
  
}	
	   
