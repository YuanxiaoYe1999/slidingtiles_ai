#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define SIZE 16
#define SIDE 4
#define MAXNODES pow(2,20)
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
    Array *v = (Array*)malloc(sizeof(Array));
    *v = st_pop(stack);
    
    if(equals(*v, final)){ // solucao
      printf("Solution found at depth %d!\n", v->depth);
      print_solution(v);
      return;
    }
    
    
    if(!member(*v, visited)){
      visited = add_value(*v, visited);
      
      // operadores
      Array up = move_up(*v); up.depth=v->depth+1; up.move = UP; up.parent = v;
      Array down = move_down(*v); down.depth=v->depth+1; down.move = DOWN; down.parent = v;
      Array left = move_left(*v); left.depth=v->depth+1; left.move = LEFT; left.parent = v;
      Array right = move_right(*v); right.depth=v->depth+1; right.move = RIGHT; right.parent = v;
      
      if(!member(up, visited)) st_push(stack, up);
      if(!member(down, visited)) st_push(stack, down);
      if(!member(left, visited)) st_push(stack, left);
      if(!member(right, visited)) st_push(stack, right);
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
    Array *v = (Array*)malloc(sizeof(Array));
    *v = dequeue(queue);
    
    if(equals(*v, final)){ // solucao
      printf("Solution found!\n");
      print_solution(v);
      return;
    }
    
    if(!member(*v, visited)){
      visited = add_value(*v, visited);
      
      // operadores
      Array up = move_up(*v); up.depth=v->depth+1; up.move = UP; up.parent = v;
      Array down = move_down(*v); down.depth=v->depth+1; down.move = DOWN; down.parent = v;
      Array left = move_left(*v); left.depth=v->depth+1; left.move = LEFT; left.parent = v;
      Array right = move_right(*v); right.depth=v->depth+1; right.move = RIGHT; right.parent = v;
      if(!member(up, visited)) enqueue(up, queue);
      if(!member(down, visited)) enqueue(down, queue);
      if(!member(left, visited)) enqueue(left, queue);
      if(!member(right, visited)) enqueue(right, queue);
    }
    
  }

  printf("Solution not found\n");
  return;
}



void IDFS(Array initial, Array final){
  printf("Starting Iterative Depth-First Search...\n");
  //PLIST visited = mk_empty_list();
  PSTACK stack;
    
  for(int depth=0; depth<INT_MAX; depth++){
    if(depth>MAXDEPTH) break;

    stack = st_make_empty(MAXNODES);
    st_push(stack, initial);
    
    while(!st_is_empty(stack)){
      Array *v = (Array*)malloc(sizeof(Array));
      *v = st_pop(stack);
           
	
      if(equals(*v, final)){
	printf("Solution found at depth %d!\n", v->depth);
	
	return;
      }
   

      if(v->depth <= depth){

	//if(!member(v, visited))
	//visited = add_value(v, visited);	
	//printf("idfs i: %d v.depth: %d\n", depth, v.depth);
	  
	// operadores
	Array up = move_up(*v); up.depth=v->depth+1; up.move = UP; up.parent = v;
	Array down = move_down(*v); down.depth=v->depth+1; down.move = DOWN; down.parent = v;
	Array left = move_left(*v); left.depth=v->depth+1; left.move = LEFT; left.parent = v;
	Array right = move_right(*v); right.depth=v->depth+1; right.move = RIGHT; right.parent = v;
	
	if(!equals(*v, up)) st_push(stack, up);
	if(!equals(*v, down)) st_push(stack, down);
	if(!equals(*v, left)) st_push(stack, left);	
	if(!equals(*v, right)) st_push(stack, right);
      }
	
    }

    st_destroy(stack);
    //destroy_list(visited);
  }

  

  printf("Solution not found\n");
  return;
}





int main(){
  // Config inicial & final
  Array x; Array y;

  int i=0;
  printf("\nInitial config: ");
  while(i<SIZE) scanf("%d", &x.array[i++]);
  i=0;
  printf("\nGoal config: ");
  while(i<SIZE) scanf("%d", &y.array[i++]);


  x.depth = 0;
  x.move = NONE;
  x.parent = NULL;

  if(!solvability(x, y)){
    printf("\nThere is no solution");
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
    // Greedy
    break;
  case 5:
    // A*
    break;
  default:
    break;
  }
  
 
  return 0;
}	
	   
