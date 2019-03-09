
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
      
      QUEUE *successors = gen_successors(v); 
      while(!queue_is_empty(successors)){
	Array x = dequeue(successors);
	if(!member(x, visited))
	  st_push(stack, x);
      }
      free_queue(successors);
      
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

      QUEUE *successors = gen_successors(v);
      while(!queue_is_empty(successors)){
	Array x = dequeue(successors);
	if(!member(x, visited))
	  enqueue(x, queue);
      }
      free_queue(successors);
      
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
	print_solution(v);
	return;
      }
   
      if(v->depth <= depth){

	//if(!member(v, visited))
	//visited = add_value(v, visited);	
	printf("idfs i: %d v.depth: %d\n", depth, v->depth);

	QUEUE *successors = gen_successors(v); 
	while(!queue_is_empty(successors)){
	  Array x = dequeue(successors);
	  // Dont check visited (?)
	  st_push(stack, x);
	}
	free_queue(successors);
	
      }
	
    }

    st_destroy(stack);
    //destroy_list(visited);
  }

  

  printf("Solution not found\n");
  return;
}
