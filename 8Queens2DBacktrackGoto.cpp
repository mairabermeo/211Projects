/**
*Name: Maira Bermeo
*/
#include <iostream>
using namespace std;

int main() {
  //create the board, counter,  
  int q[8][8]={}, solNum=1,r=0,c=0; 
  // place a queen in the corner
  q[r][c]=1;
  
  //move onto next col
  nc:
  c++;
  if(c==8)
    goto print;
  r= -1; // question: why -1 here? a: without this it would not be able start at the top
  
  // move to next row 
  nr:
  r++; 
  if(r==8) goto backtrack;
  for (int i=0; i<c; i++) // check row
    if(q[r][i]==1)
      goto nr;
  for(int i=1; r-i>=0 && c-i >=0 ;i++) // up diag test
    if (q[r-i][c-i]==1)
      goto nr;
  for(int i=1; r+i < 8 && c-i >=0 ;i++) // down diag test
    if (q[r+i][c-i]==1) 
        goto nr;
  q[r][c]=1;// place queen if it passed all tests 
  goto nc; // do the same for next row
  
  //backtrack when all the conitions fail 
  backtrack:
  c--;
  if (c < 0) return 0;
  r=0;
  while (q[r][c] != 1)
    r++;
  q[r][c]=0; //remove the queen and reset 
  goto nr; // start to find a new spot for the queen to be safe 

//when everything passed the solution can be outputed 
  print:
  cout<< "Solution #" << solNum++ << endl;
  for (int i= 0; i<8; i++){
    for(int j=0;j<8;++j)
      cout<< q[i][j] << " "; // print all 0s and 1s
    cout<< endl;
    
  }
  goto backtrack; //look for other solutions 
}