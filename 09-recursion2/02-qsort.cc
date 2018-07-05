// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}
void outputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}

int partitonQsort(int arr[], int be, int en) {
    int pivot = arr[en];

    // copy all smaller elements into leftArr
    // copy all greater elements into rightArr
    int leftArr[100], rightArr[100];
    int j = 0, k = 0;

    for (int i = be; i <= en; ++i) {
        if (arr[i] <= pivot) {
            leftArr[j] = arr[i]; ++j;
        }
        else {
            rightArr[k] = arr[i]; ++k;
        }
    }
    // j no of elements and k no of elements are lesser and greater than pivot
    for (int i = 0; i < j; ++i) {
        arr[i + be] = leftArr[i];
    }
    for (int i = 0; i < k; ++i) {
        arr[i + be + j] = rightArr[i];
    }
    return be + j - 1;
}

int partitonQsort2(int arr[], int be, int en){
    int pivotIndex = en;
    int right = en;

    for(int i = en - 1; i >= be; --i){
        if (arr[i] > arr[pivotIndex]){
            swap(arr[right], arr[i]);
            if (right == pivotIndex) pivotIndex = i;
            --right;
        }
    }
    swap(arr[right], arr[pivotIndex]);
    return right;
}


void quickSort(int arr[], int be, int en) {
    if (be > en) return;

    int idx = partitonQsort2(arr, be, en);
    quickSort(arr, be, idx - 1 );
    quickSort(arr, idx + 1, en);
}


int main() {
    int arr[100];
    int n; cin >> n;
    inputArr(arr, n);
    quickSort(arr, 0, n - 1);
    outputArr(arr, n);
}