/*
Name: Maira Bermeo 
CUNY ID: 24175075
Lab: 21D
Professor: Lizheng Zhou
*/

#include <iostream>
#include <cmath>
using namespace std;


bool ok(int cross[], int c) {
   
   // Helper array to store the indexes of the conflicting numbers
   static int helper[8][5] = { 
      {-1},
      {-1},
      {0, 1, -1},
      {0, -1},
      {0, 2, 3, -1},
      {0, 2, 3, -1},
      {0, 1, 2, 4, -1},
      {0, 1, 2, 5, -1},
   }; 
   
// Check if the current value at index c is already present in the cross array
for (int i = 0; i < c; ++i) {
  if (cross[i] == cross[c]) {
    return false;
  }
}

// Check if the current value at index c is adjacent that has a difference of 1
for (int i = 0; helper[c][i] != -1; ++i) {
  if (abs(cross[c] - cross[helper[c][i]]) == 1) {
    return false;
  }
}

return true;
}

// Function to print the current configuration
void print(int q[]) {
   static int solution = 0;
   cout << "Solution #" << ++solution << "\n";
   cout << " " << q[1] << q[4] << endl;
   cout << q[0] << q[2] << q[5] << q[7] << endl;
   cout << " " << q[3] << q[6] << endl;
   cout << endl;
}

int main() {
   int cross[8]={};
   int c = 0;
   cross[c] = 0;
   while( c >= 0 ){
   // If it passed all the tests then print
	if( c > 7 ){
	print( cross ) ;
   // return for other solutions
	   c-- ;
	   }
	   else{
	   cross[c] = 0 ;
      }
		

      while( c >= 0 && c < 8 ){
         cross[c]++ ;
         // If there are no more positions to try to backtrack
         if( cross[c] > 8 )
            c-- ;
         // If the current configuration is valid, move on to the next queen
         else
            if( ok( cross, c ) ==  true ){
            c++ ;
            break ;
            }
      }
   }
return 0 ;  
}

