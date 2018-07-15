// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
// sort array in decreasing order
#include <iostream>
#include <algorithm>
using namespace std;
void inputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
}

bool compareIntDecreasing(int x, int y){
    // shall x come before y
    // if (x < y) return false;
    // return true;    
    return x > y;
}

void outputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[100];
    int n; 
    cin >> n;
    inputArr(arr, n);   
    sort(arr, arr + n, compareIntDecreasing);     //[0, n-1], [0, n)
    outputArr(arr, n);
}