// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void update(int arr[], int n, int x){
    int tmp[n];
    for(int i = 0; i < n; ++i){
        tmp[i] = arr[i];   
    }

    for(int i = 0; i < n; ++i){
        arr[i] = tmp[i] + x;
    }
}

void update(int arr[], int n, int x){
    for(int i = 0; i < n; ++i){
        arr[i] = arr[i] + x;
    }
}


int main(){
    int arr[] = {1, 2, 3};
    int n = 3;

    update(arr, n, 3);   
}