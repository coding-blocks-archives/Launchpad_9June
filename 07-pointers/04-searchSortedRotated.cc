// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int searchRotated(int arr[], int n, int key) {
    int be = 0;
    int en = n - 1;

    while (be <= en) {
        int mid = (be + en) / 2;
        if (arr[mid] == key) {return mid;}

        if (arr[mid] > arr[en]) {
            // right is unsorted
            if (key <= arr[en] or key > arr[mid]) {
                be = mid + 1;
            }
            else {
                en = mid - 1;
            }
        }
        else {
            if (key >= arr[be] or key < arr[mid]) {
                en = mid - 1 ;
            }
            else {
                be = mid + 1;
            }
        }
    }
    return -1;
}


int lowerBound(int arr[], int n, int key) {
    int be = 0;
    int en = n - 1;
    int ans = -1;
    while (be <= en) {
        int mid = (be + en) / 2;
        if (arr[mid] >= key) {
            ans = mid;
            en = mid - 1 ;
        }
        else {
            be = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[100];
    int n; cin >> n;
    inputArr(arr, n);
    int key; cin >> key;
    // int ans = searchRotated(arr, n, key);
    int ans = lowerBound(arr, n, key);
    cout << ans;
}