
Pos get_empty_pos(int **pmatrix){
  Pos pos = {-1, -1};
  int i, j;
  for(i=0; i<(SIDE); i++)
    for(j=0; j<(SIDE); j++)
      if(pmatrix[i][j] == 0){
	pos.x = i;
	pos.y = j;
	return pos;
      }
  
  return pos;
}


int **array_to_matrix(Array v){
  int **m = (int**)malloc((SIDE) * sizeof(int*));

  int i,j;
  for(i=0; i<SIDE; i++)
    m[i] = (int*)malloc((SIDE) * sizeof(int));

  for(i=0; i<SIDE; i++)
    for(j=0; j<SIDE; j++)
      m[i][j] = v.array[4*i + j];
  
  return m;
}


Array matrix_to_array(int **pmatrix){ 
  Array v;

  int i,j,k=0;
  for(i=0;i<(SIDE);i++)
    for(j=0;j<(SIDE);j++)
      v.array[k++] = pmatrix[i][j];
 
  return v;
}


bool equals(Array x, Array y){
  int i=0;
  while(i<SIZE){
    if(x.array[i] != y.array[i])
      return false;
    i++;
  }
  
  return true;
}



bool is_visited(Array x, Array **visited, int n){

  for(int i=0; i<n; i++)
    if(equals(x, *visited[i]))
      return true;
        
  return false;
}


void print(Array v){
  int i = 0;
  while(i < SIDE){
    printf("%d %d %d %d\n", v.array[4*i + 0], v.array[4*i + 1],
	   v.array[4*i + 2], v.array[4*i + 3]);
    i++;
  }
  putchar('\n');
}


int count_inversions(Array v){
  int i,j,k=0;

  for(i=0; i<SIZE-1; i++)
    for(j=i+1; j<SIZE; j++){
      int x = v.array[i], y = v.array[j];
      if(x==0 || y==0) continue;
      if(x>y) k++;
    }
  return k;
}



bool solvability(Array a1, Array a2){
  Pos p1 = get_empty_pos(array_to_matrix(a1));
  Pos p2 = get_empty_pos(array_to_matrix(a2));

  bool cond_i = ISEVEN(count_inversions(a1)) == ISODD(p1.x);
  bool cond_f = ISEVEN(count_inversions(a2)) == ISODD(p2.x);

  return cond_i == cond_f;
}



void print_solution(Array *v){

  printf("(Path from final to initial config)\n");
  while(v->parent != NULL){
    Move m = v->move;
    if(m == UP) printf("UP ");
    else if(m == DOWN) printf("DOWN ");
    else if(m == LEFT) printf("LEFT ");
    else if(m == RIGHT) printf("RIGHT ");
    else return;
    //memcpy(v, v->parent, sizeof(Array));
    v = v->parent;
  }
  putchar('\n');
  return;
}
