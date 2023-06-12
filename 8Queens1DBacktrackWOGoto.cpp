/*
Name: Maira Bermeo 
Lab: 21D
Professor: Lizheng Zhou
*/

#include <iostream>
using namespace std;

// Function to check if the queen placement is valid
bool ok(int q[], int c) {
   // Check for each previous column
   for (int i = 0; i < c; i++)
      // Check if there's already a queen in the same row or diagonal 
      if(q[i] == q[c] || (c - i) == abs(q[c] - q[i]))
         return false; 
   return true; 
}

// Function to print the chessboard with the queen placements
void print(int q[]) {
   static int numSolutions = 0;
   // printing the solution number
   cout << "Solution #" << ++numSolutions << ": "; 

   for (int i = 0; i < 8; i++){
   // printing the queen positions in each row
      cout << q[i]; 
   }
   cout << endl;

   // printing the chessboard
   for (int i = 0; i < 8; i++){
      for (int j = 0; j < 8; j++){
         // if there is a queen print 1 else print 0
         if (q[j] == i) 
            cout<< "1 "; 
         else 
            cout<<"0 "; 
      }
      cout<<endl;
   }
}

int main() {
   //initialize board, and place forst queen in first row
  int q[8] = {}; 
  int c = 0; 
  q[c]=0; 
  
  // haven't found all solutions 
   while (c >= 0) {
     c++; // goto next column
     // if we have found a solution: print and backtrack
      if (c == 8) { 
         print(q);
         c--; 
      } else q[c] = -1; // initialize the next column to -1, move to one before the first row
           
      while (c >= 0) {
         q[c]++;     // move to the next row
         if (q[c] == 8)   // went through all rows in w/ no queen
            c--; // backtrack 
         else if (ok(q, c)) // check conditions
            break; // go back to the beginning of the outer loop
      }
   }
   return 0;
}
