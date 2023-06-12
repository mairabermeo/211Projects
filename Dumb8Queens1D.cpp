/*
Name: Maira Bermeo 
Lab: 21D
Professor: Lizheng Zhou
*/
#include<iostream>
using namespace std;

// make sure the queens are not in danger 
bool ok(int board[]){
    
    // Iterate over each column 
    for (int c = 7; c > 0; --c) {
        int row = board[c];

        // Check each previous column for conflicts
        for (int prevCol = c - 1; prevCol >= 0; --prevCol) {
            int prevRow = board[prevCol];

            // Check for conflict with a queen in the same column
            if (row == prevRow) {
                return false;
            }
            // Check for conflict with a queen diagonally in both left & right side 
            if (abs(row - prevRow) == c - prevCol) {
                return false;
            }
        }
    }
    // All queens are placed without conflicts
    return true;
}

// Print the solution 
void print(int q[]){
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ": ";
    
    // Print the solution number
    for (int i = 0; i < 8; i++)
      cout << q[i];
      cout << endl;

    // Print the binary representation of the board
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            // if codes row and queens column position equal each other print 1
            int visual= (q[j]==i) ? 1:0;
            cout<< visual << " ";
        }
        cout<< endl;
    }
}

int main(){
    // sets array size
     int q[8]={};
        for(int i0=0;i0<8;i0++){
            for(int i1=0;i1<8;i1++){
                for(int i2=0;i2<8;i2++){
                    for(int i3=0;i3<8;i3++){
                        for(int i4=0;i4<8;i4++){
                            for(int i5=0;i5<8;i5++){
                                for(int i6=0;i6<8;i6++){
                                     for(int i7=0;i7<8;i7++){
                                        // gives the array its value based on the nested for loops
                                        q[0]=i0;       
                                        q[1]=i1;
                                        q[2]=i2;
                                        q[3]=i3;
                                        q[4]=i4;
                                        q[5]=i5;
                                        q[6]=i6;
                                        q[7]=i7;
                                        // passes ok to see if queen is not at threat
                                        if(ok(q)){
                                            // print the solution 
                                            print(q);
                                        }   
                                     }
                                }
                            }
                        }
                    }
                }
            }
                                            
        }
    return 0;
}