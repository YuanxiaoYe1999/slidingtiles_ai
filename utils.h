
Pos get_empty_pos(int **pmatrix){
  Pos pos = {-1, -1};
  int i, j;
  for(i=0; i<(SIZE/4); i++)
    for(j=0; j<(SIZE/4); j++)
      if(pmatrix[i][j] == 0){
	pos.x = i;
	pos.y = j;
	return pos;
      }
  
  return pos;
}


int **array_to_matrix(Array v){
  int **m = (int**)malloc((SIZE/4) * sizeof(int*));

  int i,j;
  for(i=0; i<SIZE/4; i++)
    m[i] = (int*)malloc((SIZE/4) * sizeof(int));

  for(i=0; i<SIZE/4; i++)
    for(j=0; j<SIZE/4; j++)
      m[i][j] = v.array[4*i + j];
  
  return m;
}



Array matrix_to_array(int **pmatrix){ 
  Array v;

  int i,j,k=0;
  for(i=0;i<(SIZE/4);i++)
    for(j=0;j<(SIZE/4);j++)
      v.array[k++] = pmatrix[i][j];
 
  return v;
}



void print(Array v){
  int i = 0;
  while(i < SIZE/4){
    printf("%d %d %d %d\n", v.array[4*i + 0], v.array[4*i + 1],
	   v.array[4*i + 2], v.array[4*i + 3]);
    i++;
  }
  putchar('\n');
}

