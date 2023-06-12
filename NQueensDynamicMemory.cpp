/*
Name: Maira Bermeo 
Lab: 21D
Professor: Lizheng Zhou
*/
#include <iostream> 
#include <cmath> 
using namespace std; 

// function that checks if the placement of the queens is valid
bool ok(int q[], int c) {
    for (int i = 0; i < c; i++) {
      // if there's a conflict with previous queen placement, return false
      if (q[c] == q[i] || (c - i) == abs(q[c] - q[i])) { 
         return false;
         }
    }
    // if the placement is valid, return true
    return true; 
}

// function that returns the number of solutions for the n-queens problem
int nqueens(int n) {
    int c = 0, solutions = 0;
    // dynamic array for storing the queen placements
    int* q = new int[n]; 
    // place the first queen at position (0,0)
    q[0] = 0; 
   
    while (c >= 0) {
      // if all n queens are placed, increment the solutions count and backtrack to find more solutions
        if (c == n - 1) { 
            solutions++;
            c--;
        }
        else
         // place the next queen at an invalid position
        q[++c] = -1; 
        while (c >= 0) {
         // place the next queen at the next column
         q[c]++; 
         // if all rows have been tried for this column, backtrack
         if (q[c] == n) 
         c--;
         // if the placement is valid, move on to the next column
         else if (ok(q, c)== true) break; 
        }
    }
    // free the dynamically allocated memory
    delete[] q; 
    return solutions;
}

int main() {
    int n = 12; 
    for (int i = 1; i <= n; ++i)
        cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n"; 
    return 0; 
}
