// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void printEven(int n, int r, int x){
    if (n % 2 == 0) cout << n;
    // return 1;    // ERROR. EMPTINESS TO BE RETURNED
}

int main(){
    int n;
    cin >> n;
    printEven(n);
}