
Array move_up(Array x){
  int **pmatrix = array_to_matrix(x);
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


Array move_down(Array x){
  int **pmatrix = array_to_matrix(x);
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


Array move_left(Array x){
  int **pmatrix = array_to_matrix(x);
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



Array move_right(Array x){
  int **pmatrix = array_to_matrix(x);
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

