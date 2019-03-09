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

// Game Mechanics
#include "operators.h"

// Search Algorithms
#include "uninformed.h" // DFS, BFS, IDFS
#include "heuristics.h" 
#include "informed.h" // A*, Greedy



int main(){
  // Receive initial & final input
  Array initial; Array final;

  int i=0;
  printf("\nInitial config: ");
  while(i<SIZE) scanf("%d", &initial.array[i++]);
  i=0;
  printf("\nGoal config: ");
  while(i<SIZE) scanf("%d", &final.array[i++]);


  // Root node property
  initial.depth = 0;
  initial.move = NONE;
  initial.parent = NULL;


  // Count inversions
  if(!solvability(initial, final)){
    printf("\nThere is no solution\n.");
    return 0;
  }

  
  // Search Algorithm to be used
  printf("\n1 - DFS\n2 - BFS\n3 - IDFS\n4 - Greedy\n5 - A*\n");
  int b;
  scanf("%d", &b);


  
  // Desired Heuristic
  int h;
  if(b==4 || b==5){ 
    printf("\n1 - Wrong Positions\n2 - Manhattan Distance\n3 - Wrong Pos. + Manhattan Dist.\n");
    scanf("%d", &h);
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
    Greedy(initial, final, h);
    break;
  case 5:
    AStar(initial, final, h);
    break;
  default:
    break;
  }
  
 
  return 0;
}	
	   
