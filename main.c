#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 16
#define SIDE 4

#include "structs.h"
#include "queue.h"
#include "stack.h"
#include "utils.h"
#include "operators.h"



int main(){

  Array x; Array y;

  
  int i=0;
  while(i<SIZE) scanf("%d", &x.array[i++]);
  i=0;
  while(i<SIZE) scanf("%d", &y.array[i++]);

  printf("has solution? %s\n", solvability(x,y) ? "true" : "false");
  
  return 0;
  
}	
	   
