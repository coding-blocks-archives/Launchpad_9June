// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
}
void outputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}

void mergeSortedArr(int x[], int n1, int y[], int n2, int ans[]){
    int i = 0; 
    int j = 0;
    int k = 0;
    while(i < n1 && j < n2){
        if (x[i] < y[j]){
            ans[k] = x[i];
            ++i;
            ++k;
        }
        else{
            ans[k] = y[j];
            ++j;
            ++k;
        }
    }
    while(i < n1){
        ans[k] = x[i];
        ++i; ++k;
    }
    while(j < n2){
        ans[k] = y[j];
        ++j; ++k;
    }
}

int main(){
    int arr1[100];
    int arr2[100]; 
    int ans[200];

    int n1, n2;
    cin >> n1 >> n2;
    inputArr(arr1, n1);
    inputArr(arr2, n2);
    mergeSortedArr(arr1, n1, arr2, n2, ans);
    outputArr(ans, n1+n2);
}