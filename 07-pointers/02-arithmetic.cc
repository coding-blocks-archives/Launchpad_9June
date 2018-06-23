// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
#define print(x) cout << #x << ":\t" << x << endl

int main(){
    // int arr[] = {1, 2, 3};
    // int* ptr1 = arr;
    // int* ptr2 = &arr[2];

    // print(ptr2 - ptr1);
    // print((char*)ptr2 - (char*)ptr1);
    // print((int*)ptr2 - (char*)ptr1);    // WRONG

    // double y = 1.0;
    // double* ptr_d = &y;


    // int* ptr;
    // print(ptr);
    // print(*ptr);

    // 1D array
    int arr[3] = {};
    // print((&arr) + 1);  // ARRAY
    // print(&arr);
    // print(arr + 1);
    // print(arr);
    // int(*ptr)[3] = &arr;

    // 2D array
    int mat[2][3] = {};
    // print(&mat);
    // print(mat);
    // print(mat[0]);
    // print(&mat[0][0]);
    int(*ptr)[3] = mat;


}