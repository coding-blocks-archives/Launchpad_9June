// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
#define print(x) cout << #x << ":" << x << endl

int main(){
    int arr[] = {};    // initialisation

    print(arr[0]);
    print(arr[1]);
    print(arr[2]);
    print(arr[3]);
    print(arr[4]);  // undefined behaviour...check idx before access

}