
void AStar(Array initial, Array final, int heuristic){
  printf("Starting A* Guided Search...\n");

  PLIST visited = mk_empty_list();
  Heap *heap = mk_empty_heap();
  
  push(heap, INT_MIN, &initial);
  add_value(initial, visited);
  
  while(!empty_heap(heap)){
    Array *v = pop(heap);

    if(equals(*v, final)){
      printf("Solution found!\n");
      print_solution(v);
      return;
    }

    QUEUE *successors = gen_successors(v);

    while(!queue_is_empty(successors)){
      Array w = dequeue(successors);

      int g = w.depth;
      int h;
      if(heuristic == 1) h = wrong_positions(w,final);
      else if(heuristic == 2) h = 0;
      else h = wrong_positions(w, final) + manhattan_distance(w, final);

      int f = g + h;

      if(!member(w, visited)
	 || (member(w, visited) && w.f > f)
	 || (member_heap(w, heap) && w.f > f)){

	Array *x = (Array*)malloc(sizeof(Array));
	w.f = f;
	
	memcpy(x, &w, sizeof(Array));	
	push(heap, f, x);
	
      }
	
    }   
  }

  printf("Solution not found\n");
  return;
}





void Greedy(Array initial, Array final, int heuristic){
  printf("Starting Greedy Guided Search...\n");

  PLIST visited = mk_empty_list();
  Heap *heap = mk_empty_heap();
  
  push(heap, INT_MIN, &initial);
  add_value(initial, visited);
  
  while(!empty_heap(heap)){
    Array *v = pop(heap);

    if(equals(*v, final)){
      printf("Solution found!\n");
      print_solution(v);
      return;
    }

    QUEUE *successors = gen_successors(v);

    while(!queue_is_empty(successors)){
      Array w = dequeue(successors);

      int g = w.depth;
      int h;
      if(heuristic == 1) h = wrong_positions(w,final);
      else if(heuristic == 2) h = 0;
      else h = wrong_positions(w, final) + manhattan_distance(w, final);

      //int f = g + h;
      int f = h;
      
      if(!member(w, visited)
	 || (member(w, visited) && w.f > f)
	 || (member_heap(w, heap) && w.f > f)){

	Array *x = (Array*)malloc(sizeof(Array));
	w.f = f;
	
	memcpy(x, &w, sizeof(Array));	
	push(heap, f, x);
	
      }
      
    }
    
  }

  printf("Solution not found\n");
  return;
}
