
Array move_up(int **pmatrix){
  Pos pos = get_empty_pos(pmatrix);
  if(pos.x == 0)
    return matrix_to_array(pmatrix);

  size_t sz = (SIDE) * sizeof(int*);
  int **newmatrix = (int**)malloc(sz);
  memcpy(newmatrix, pmatrix, sz);
   
  newmatrix[pos.x][pos.y] = pmatrix[pos.x-1][pos.y];
  newmatrix[pos.x-1][pos.y] = 0;
  
  return matrix_to_array(newmatrix);
}


Array move_down(int **pmatrix){
  Pos pos = get_empty_pos(pmatrix);
  if(pos.x == 3)
    return matrix_to_array(pmatrix);

  size_t sz = (SIDE) * sizeof(int*);
  int **newmatrix = (int**)malloc(sz);
  memcpy(newmatrix, pmatrix, sz);
   
  newmatrix[pos.x][pos.y] = pmatrix[pos.x+1][pos.y];
  newmatrix[pos.x+1][pos.y] = 0;
  
  return matrix_to_array(newmatrix);
}


Array move_left(int **pmatrix){
  Pos pos = get_empty_pos(pmatrix);
  if(pos.y == 0)
    return matrix_to_array(pmatrix);

  size_t sz = (SIDE) * sizeof(int*);
  int **newmatrix = (int**)malloc(sz);
  memcpy(newmatrix, pmatrix, sz);
   
  newmatrix[pos.x][pos.y] = pmatrix[pos.x][pos.y-1];
  newmatrix[pos.x][pos.y-1] = 0;
  
  return matrix_to_array(newmatrix);
}



Array move_right(int **pmatrix){
  Pos pos = get_empty_pos(pmatrix);
  if(pos.x == 3)
    return matrix_to_array(pmatrix);

  size_t sz = (SIDE) * sizeof(int*);
  int **newmatrix = (int**)malloc(sz);
  memcpy(newmatrix, pmatrix, sz);
   
  newmatrix[pos.x][pos.y] = pmatrix[pos.x][pos.y+1];
  newmatrix[pos.x][pos.y+1] = 0;
  
  return matrix_to_array(newmatrix);
}

