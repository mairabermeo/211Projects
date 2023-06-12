/*
Name: Maira Bermeo 
Lab: 21D
Professor: Lizheng Zhou
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    // Create 3 empty vectors to represent the 3 towers
    vector<int> t[3];
    int n;
    cout<<"Please enter a number of rings to move: ";
    cin>>n;
    cout<<endl;
    int from = 0, to, candidate = 1, move = 0;
    // Determine which tower to start with based on whether the number of rings is odd or even
    to = (n % 2 == 1) ? 1 : 2;

    // Initialize the first tower with the rings in decreasing order, and the other 2 towers with a large number to represent an empty tower
    for(int i=n+1; i>=1; --i)
        t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);

    // Move the rings until they are all on the second tower
    while( t[1].size()<n+1){ 
        cout<<"Move # "<< ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";

        // Copy the top ring from the "from tower" to the "to tower", then delete it from the "from tower"
        t[to].push_back(t[from].back());
        t[from].pop_back();
        
        if(n%2==1){//if there are an odd number of rings
            // Choose the next "from tower" based on the sizes of the rings on the other towers
            if(t[(to+1)%3].back() < t[(to+2)%3].back())
                from=(to+1)%3;
            else
                from=(to+2)%3;
            // Choose the next "to tower" based on the sizes of the rings on the other towers
            if(t[from].back() < t[(from+1)%3].back())
                to=(from+1)%3;
            else
                to=(from+2)%3;
            // Choose the next candidate ring to move (i.e., the top ring of the current "from tower")
            candidate=(t[from].back());
        } else { // if there are an even number of rings
            // Choose the next "from tower" based on the sizes of the rings on the other towers
            if(t[(to+1)%3].back() < t[(to+2)%3].back())
                from=(to+1)%3;
            else
                from=(to+2)%3;
            // Choose the next "to tower" based on the sizes of the rings on the other towers
            if(t[from].back() < t[(from+2)%3].back())
                to=(from+2)%3;
            else
                to=(from+1)%3;
            // Choose the next candidate ring to move (i.e., the top ring of the current "from tower")
            candidate=(t[from].back());
        }
    }
    return 0;
}
