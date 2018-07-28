// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

// int* foo(){
//     int a = 10;
//     return &a;
// }

int* foo(){
    int* a  = new int;
    *a = 1000;
    return a;
}

int main(){
    // int* x = foo();
    // cout << x << endl;
    // cout << *x << endl;
    // delete x;   // delete <address>

    // int n;
    // cin >> n;
    // int* arr = new int[n];
    // delete [] arr;
}