// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void mySwap(int x[]){
    int tmp = x[0];
    x[0] = x[1];
    x[1] = tmp;
}


int main(){
    int arr[2] = {1, 2};

    cout << arr[0] << arr[1];
    mySwap(arr);
    cout << arr[0] << arr[1];
}   