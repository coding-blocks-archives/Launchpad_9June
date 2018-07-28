// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void myswap(int& A, int& B){    // pass by reference
    int tmp = B;
    B = A;
    A = tmp;
}
int main(){
    int x, y;
    cin >> x >> y;
    myswap(1, 2);
    // myswap(1,2);     // wont work
    cout << x << y;   
}