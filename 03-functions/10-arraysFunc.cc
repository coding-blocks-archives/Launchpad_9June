// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void inputArr(int A[], int n){
    for(int i = 0; i < n; ++i){
        cin >> A[i];
    }
}

void outputArr(int A[100], int n){
    for(int i = 0; i < n; ++i){
        cout << A[i] << " " ;
    }
}

void updateArr(int X[100], int n, int num){
    for(int i = 0; i < n; ++i){
        X[i] = X[i] + num;  // X[i] += num;
    }
    // NO NEED TO RETURN SINCE ARRAYS ARE PASSED BY REFERENCE
}

int main(){
    // create an array of 100 elements
    int arr[100];
    // input no of elements to be used from user
    int n; cin >> n;

    // input array elements from user
    inputArr(arr, n);

    // output array elements
    outputArr(arr, n);
    cout << endl;

    // update all elements in the array by 3
    updateArr(arr, n, 3);

    // output array again   
    outputArr(arr, n);
    cout << endl;
}