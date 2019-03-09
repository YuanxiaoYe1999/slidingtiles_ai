
int wrong_positions(Array initial, Array final){
  int n = 0;
  for(int i=0; i<SIZE; i++)
    if(initial.array[i] != final.array[i])
      ++n;
  return n;
}



int manhattan_distance(Array initial, Array final){
  int n = 0;

  int **m = array_to_matrix(initial);
  int **w = array_to_matrix(final);

  for(int x=0; x<SIDE; x++){
    for(int y=0; y<SIDE; y++){
      if(m[x][y] != w[x][y]){
	Pos pos = get_pos(m[x][y], w);
	n += abs(pos.x - x) + abs(pos.y - y);
      }	 
    }
  }
  
  return n; 
}
