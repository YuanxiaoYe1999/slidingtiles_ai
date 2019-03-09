#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <unistd.h>

#define SIZE 16
#define SIDE 4
#define MAXNODES pow(2,20)
#define MAXDEPTH 20


// Data Structures
#include "structs.h"
#include "queue.h"
#include "stack.h"
#include "utils.h"
#include "list.h"
#include "heap.h"

// Game Mechanic
#include "operators.h"

// Search Algorithms
#include "uninformed.h" // DFS, BFS, IDFS
#include "heuristics.h" 
#include "informed.h" // A*, Greedy





int main(){
  // Config inicial & final
  Array initial; Array final;

  int i=0;
  printf("\nInitial config: ");
  while(i<SIZE) scanf("%d", &initial.array[i++]);
  i=0;
  printf("\nGoal config: ");
  while(i<SIZE) scanf("%d", &final.array[i++]);

  // Propriedades nó raiz
  initial.depth = 0;
  initial.move = NONE;
  initial.parent = NULL;

  if(!solvability(initial, final)){
    printf("\nThere is no solution\n.");
    return 0;
  }

  // Selecionar pesquisa
  printf("\n1 - DFS\n2 - BFS\n3 - IDFS\n4 - A*\n5 - Greedy\n");
  int b=5;
  //scanf("%d", &b);

  int h;
  if(b==4 || b==5){ 
    // Selecionar heuristica
    printf("\n1 - Wrong Positions\n2 - Manhattan Distance\n3 - Wrong Pos. + Manhattan Dist.\n");
    int h=1;
    //scanf("%d", &h);
  }
  
  
  switch(b){
  case 1:
    DFS(initial,final);
    break;
  case 2:
    BFS(initial,final);
    break;
  case 3:
    IDFS(initial, final);
    break;
  case 4:
    // Greedy
    break;
  case 5:
    AStar(initial, final, h);
    break;
  default:
    break;
  }
  
 
  return 0;
}	
	   
