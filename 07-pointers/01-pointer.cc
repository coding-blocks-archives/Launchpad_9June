// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
#define print(x) cout << #x << ":\t" << x << endl

void foo(int fooArr[]){
    print(sizeof(fooArr));
}

int main(){
    // int x = 10;
    // print(x);
    // print(&x);

    // pointer
    // int* ptr = &x;

    // int x = 1;
    // double y = 2.1;
    // int* ptr_i   = &x;
    // double* ptr_d= &y;
    // print(x); 
    // print(y);
    // print(ptr_i); 
    // print(ptr_d);
    // print(*ptr_i); 
    // print(*ptr_d);

    // int x = 1;
    // int* ptr_i = &x;
    // print(ptr_i);
    // print((double*)ptr_i);
    // print(*ptr_i);
    // print(*(double*)ptr_i);

    int arr[3] = {1, 2, 3};
    int x = 1;
    // print(arr);
    // print(&arr[0]);
    // int* ptr = arr;
    // print(sizeof(arr));
    // print(sizeof(ptr));

    // void foo(int arr[]);    // declaration void foo(int * arr)
    // foo(x);
    // print(sizeof(arr));
}