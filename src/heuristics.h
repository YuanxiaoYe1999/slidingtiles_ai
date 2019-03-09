int wrong_positions(Array initial, Array final){
  int n = 0;
  for(int i=0; i<SIZE; i++)
    if(initial.array[i] != final.array[i])
      ++n;
  return n;
}


int manhattan_distance(Array initial, Array final){

  // TO DO
  return 0;

}
