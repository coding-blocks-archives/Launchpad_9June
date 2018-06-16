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

int findElement(int arr[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) return i;
    }
    return -1;
}

void mySwap(int& a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1 ; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                mySwap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[100];
    int n;
    cin >> n;

    inputArr(arr, n);

    // int x; cin >> x;
    // int ans = findElement(arr, n, x);
    // cout << "Element found at index " << ans << endl;

    bubbleSort(arr, n);
    outputArr(arr, n);
}