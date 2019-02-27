#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define SIZE 16
#define SIDE 4
#define MAXNODES pow(4,3)
#define MAXDEPTH 20

#include "structs.h"
#include "queue.h"
#include "stack.h"
#include "utils.h"
#include "operators.h"
#include "list.h"



void DFS(Array initial, Array final){
  printf("Starting Depth-First Search...\n");
  PLIST visited = mk_empty_list();
  PSTACK stack = st_make_empty(MAXNODES);
  st_push(stack, initial);
  
  while(!st_is_empty(stack)){
    Array v = st_pop(stack);
    
    if(equals(v, final)){ // solucao
      printf("Solution found!\n");
      // solution path // TODO
      return;
    }
    
    if(!member(v, visited)){
      visited = add_value(v, visited);
      
      // operadores
      st_push(stack, move_up(v));
      st_push(stack, move_down(v));
      st_push(stack, move_left(v));
      st_push(stack, move_right(v));
    }
    
  }
  
  printf("Solution not found\n");
  return;
}
  



void BFS(Array initial, Array final){
  printf("Starting Breadth-First Search...\n");
  PLIST visited = mk_empty_list();
  QUEUE *queue = mk_empty_queue(MAXNODES);
  enqueue(initial, queue);
  
  while(!queue_is_empty(queue)){
    Array v = dequeue(queue);
    print(v);
    
    if(equals(v, final)){ // solucao
      printf("Solution found!\n");
      // solution path // TODO
      return;
    }
    
    if(!member(v, visited)){
      visited = add_value(v, visited);
      
      // operadores
      enqueue(move_up(v), queue);
      enqueue(move_down(v), queue);
      enqueue(move_left(v), queue);
      enqueue(move_right(v), queue);
    }
    
  }

  printf("Solution not found\n");
  return;
}



void IDFS(Array initial, Array final){

  printf("Starting Iterative Depth-First Search...\n");
  PLIST visited = mk_empty_list();
  PSTACK stack = st_make_empty(MAXNODES);

  initial.depth = 0;
    
  for(int depth=0; depth<INT_MAX; depth++){
    if(depth>MAXDEPTH) break;
    
    st_push(stack, initial);
    while(!st_is_empty(stack)){
      Array v = st_pop(stack);
      
      //visited = add_value(v, visited);
	
      if(equals(v, final)){
	printf("Solution found at depth %d!\n", v.depth);
	// solution path // TODO
	return;
      }
   

      if(v.depth<=depth){
	printf("i: %d v.depth: %d\n", depth, v.depth);
	  
	// operadores
	Array up = move_up(v); up.depth=v.depth+1;
	Array down = move_down(v); down.depth=v.depth+1;
	Array left = move_left(v); left.depth=v.depth+1;
	Array right = move_right(v); right.depth=v.depth+1;
	
	st_push(stack, up);
	st_push(stack, down);
	st_push(stack, left);
	st_push(stack, right);
      }
	
    }

  }

  printf("Solution not found\n");
  return;
}





int main(){
  // Config inicial & final
  Array x; Array y;

  int i=0;
  while(i<SIZE) scanf("%d", &x.array[i++]);
  i=0;
  while(i<SIZE) scanf("%d", &y.array[i++]);


  if(!solvability(x, y)){
    printf("There is no solution\n");
    return 0;
  }

  // Selecionar pesquisa
  printf("\n1 - DFS\n2 - BFS\n3 - IDFS\n4 - A*\n5 - Greedy\n");

  int c=3;
  //scanf("%d", &c);
  
  switch(c){
  case 1:
    DFS(x,y);
    break;
  case 2:
    BFS(x,y);
    break;
  case 3:
    IDFS(x, y);
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
	   
