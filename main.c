#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 16
#define SIDE 4
#define MAXNODES 1024

#include "structs.h"
#include "queue.h"
#include "stack.h"
#include "utils.h"
#include "operators.h"



bool DFS(Array initial, Array final){

  Array **visited = (Array**)malloc(MAXNODES * sizeof(Array*));

  PSTACK stack = st_make_empty(MAXNODES);
  st_push(stack, initial);

  int n_visited = 0;
  
  while(!st_is_empty(stack)){
    
    Array v = st_pop(stack);

    printf("pop:\n");
    print(v);
    
    if(equals(v, final)) // solucao
      return true;
       
    if(!is_visited(v, visited, n_visited)){

      printf("crash\n");
      // guardar Array em matriz **visited
      memcpy(visited[n_visited++], &v, sizeof(Array));
      

      // operadores
     
  
      st_push(stack, move_left(array_to_matrix(v)));
      
    }   
  }
  

  return false;
}
  





int main(){

  Array x; Array y;


  int i=0;
  while(i<SIZE) scanf("%d", &x.array[i++]);
  i=0;
  while(i<SIZE) scanf("%d", &y.array[i++]);


  if(!solvability(x, y)){
    printf("There is no solution\n");
    return 0;
  }


  printf("\n1 - DFS\n2 - BFS\n3 - IDFS\n4 - A*\n5 - Greedy\n");

  int c=1;
  //scanf("%d", &c);
  
  switch(c){
  case 1:
    DFS(x,y);
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  default:
    break;
  }
  
 
  return 0;
}	
	   
