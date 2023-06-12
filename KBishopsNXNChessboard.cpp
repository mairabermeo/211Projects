#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int n) {
    for (int i = 0; i < c; i++)
        if ((q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n))
            // Bishops can't attack each other diagonally 
            return false; 
    // Bishops are placed in a valid way
    return true; 
}

int kBishops(int n, int k) {
    int solutions = 0; 
    int* q= new int[k];
    int c = 0;
    // Place the first bishop in the top-left corner (0, 0)
    q[c] = 0; 
    while (c >= 0) {
        c++; 
        if (c == k) {
            // Found a valid configuration of k bishops
            solutions++; 
            // Backtrack to find more solutions
            c--; 
        }
        else
        // Copy the previous column's position to the current column
        q[c]=q[c-1]; 
        while (c >= 0) {
            // Move to the next row in the current column
            q[c]++; 
            if (q[c] == n*n) 
            // Backtrack to the previous column if all rows have been explored
            c--; 
            // Check if the new bishop placement is valid
            else if (ok(q, c, n)) break; 
        }
    }
    // Free the dynamically allocated memory
    delete [] q; 
    // Return the number of valid configurations
    return solutions; 
}

int main() {
    int n, k;
    while(true){
        cout << "Enter value of n (input -1 to end program): ";
        cin >> n;
        if (n == -1)
            // Exit the program if -1 is entered for n
            return 0; 
        cout << "Enter value of k: ";
        cin >> k;
        // Display the number of valid configurations
        cout << "number of solutions: " << kBishops(n, k) << "\n"; 
    }
    return 0;
}
