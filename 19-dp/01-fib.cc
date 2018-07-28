// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int fib(int n/*, int memoPad[]*/){
    if (n == 0) return 0;
    if (n == 1) return 1;

    /*if (memoPad[n] != 0){
        // this applies this nth fib no has ALREADY been computed
        return memoPad[n];
    }*/

    // compute nth fib no because n is NOT 1 nor 0
    int prev = fib(n-1/*, memoPad*/);
    int superPrev = fib(n - 2/*, memoPad*/);
    int ans = prev + superPrev;
    // memoPad[n] = ans; // register what you have computed because
    // THOSE WHO DO NOT REMEMBER THE PAST ARE CONDEMN TO REPEAT IT!!! :)
    return ans;
}



int main(){
    int n;
    cin >> n;

    // int memoPad[100] = {};  // all set to 0 first
    
    // make dynamic array instead of static
    int *memoPad = new int[n];
    
    int ans = fib(n/*, memoPad*/); 
    cout << ans;   

    delete [] memoPad;

    return 0;
}