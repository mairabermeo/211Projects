/*
Name: Maira Bermeo 
CUNY ID: 24175075
Lab: 21D
Professor: Lizheng Zhou
*/

#include<iostream>
using namespace std;

// function to make sure the marriages are stable
bool ok(int q[], int c) { 

    // mens prefrences     w0 w1 w2
	static int mp[3][3] = { { 0,2,1 },//m0	 
							      { 0,2,1 },//m1
							      { 1,2,0 } //m2
   }; 
						
   // womens prefrences    m0 m1 m2
	static int wp[3][3] = { { 2,1,0 },//w0
							      { 0,1,2 },//w1
							      { 2,0,1 } //w2
   }; 

   for(int i = 0; i < c; i++){ 
      int wi = q[i];  // wife of the man i
      int wc = q[c];   // wife of the man c
      if(q[i] == q[c]){ // if two men are paired with the same woman, the pairing is unstable
        return false;
      }
      // check if there is an instability in the current pairing
      if(mp[i][wc] < mp[i][wi] && wp[wc][i] < wp[wc][c] || // Man#i and (wife of the man#c) both like each other more than their own spouse
       mp[c][wi] < mp[c][wc] && wp[wi][c] < wp[wi][i]){ // Man#c and (wife of the man#i) both like each other more than their own spouse
        return false;
       }
   }

   return true;
}


// A function that prints the current valid arrangement of wives.
// q[]: array representing the current arrangement of wives (index represents the husband)
void print(int q[]) {
static int solution = 0;
cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
for (int i = 0; i < 3; ++i)
cout << i << "\t" << q[i] << endl;
cout << endl;
}


int main() {
  int marr[3] = {}; 
  int c = 0; 
  marr[c]=0; 
  while (c >= 0) {
   c++; // Move to the next husband
   if (c == 3) { // If we have assigned all wives, print the solution
      print(marr);
      c--; // Backtrack to find other solutions
   }
   else marr[c] = -1; // Assign the next wife to the current husband
       
   while (c >= 0) {
      marr[c]++; // Move to the next wife
      if (marr[c] == 3){ // If we have tried all wives for the current husband, backtrack
            c--; 
      }
      else if (ok(marr, c)){ // if pair is stable then move onto the next man
         break; 
      }
   }
  }
   return 0;
}
