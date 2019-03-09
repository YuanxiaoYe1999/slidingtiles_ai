
Array move_up(Array x){
  int **pmatrix = array_to_matrix(x);
  Pos pos = get_pos(0, pmatrix);
  if(pos.x == 0)
    return matrix_to_array(pmatrix);

  size_t sz = (SIDE) * sizeof(int*);
  int **newmatrix = (int**)malloc(sz);
  memcpy(newmatrix, pmatrix, sz);
   
  newmatrix[pos.x][pos.y] = pmatrix[pos.x-1][pos.y];
  newmatrix[pos.x-1][pos.y] = 0;
  
  return matrix_to_array(newmatrix);
}


Array move_down(Array x){
  int **pmatrix = array_to_matrix(x);
  Pos pos = get_pos(0, pmatrix);
  if(pos.x == 3)
    return matrix_to_array(pmatrix);

  size_t sz = (SIDE) * sizeof(int*);
  int **newmatrix = (int**)malloc(sz);
  memcpy(newmatrix, pmatrix, sz);
   
  newmatrix[pos.x][pos.y] = pmatrix[pos.x+1][pos.y];
  newmatrix[pos.x+1][pos.y] = 0;

  return matrix_to_array(newmatrix);
}


Array move_left(Array x){
  int **pmatrix = array_to_matrix(x);
  Pos pos = get_pos(0, pmatrix);
  if(pos.y == 0)
    return matrix_to_array(pmatrix);

  size_t sz = (SIDE) * sizeof(int*);
  int **newmatrix = (int**)malloc(sz);
  memcpy(newmatrix, pmatrix, sz);
   
  newmatrix[pos.x][pos.y] = pmatrix[pos.x][pos.y-1];
  newmatrix[pos.x][pos.y-1] = 0;
  
  return matrix_to_array(newmatrix);
}



Array move_right(Array x){
  int **pmatrix = array_to_matrix(x);
  Pos pos = get_pos(0, pmatrix);
  if(pos.x == 3)
    return matrix_to_array(pmatrix);

  size_t sz = (SIDE) * sizeof(int*);
  int **newmatrix = (int**)malloc(sz);
  memcpy(newmatrix, pmatrix, sz);
   
  newmatrix[pos.x][pos.y] = pmatrix[pos.x][pos.y+1];
  newmatrix[pos.x][pos.y+1] = 0;
  
  return matrix_to_array(newmatrix);
}




QUEUE *gen_successors(Array *v){
  // Store 4 moves
  QUEUE *q = mk_empty_queue(4);

  Array up = move_up(*v);
  up.depth=v->depth+1;
  up.move = UP;
  up.parent = v; 

  Array down = move_down(*v);
  down.depth=v->depth+1;
  down.move = DOWN;
  down.parent = v;

  Array left = move_left(*v);
  left.depth=v->depth+1;
  left.move = LEFT;
  left.parent = v;
  
  Array right = move_right(*v);
  right.depth=v->depth+1;
  right.move = RIGHT;
  right.parent = v;

  if(!equals(up, *v)) enqueue(up, q);
  if(!equals(down, *v)) enqueue(down, q);
  if(!equals(left, *v)) enqueue(left, q);
  if(!equals(right, *v)) enqueue(right, q);

  return q;
}
