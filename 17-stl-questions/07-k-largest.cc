// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

void inputArr(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
}

vector<int> bestKElements(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int> > minHeap;   // CompareInt

    for(int i = 0; i < n; ++i){
        if (i < k){
            minHeap.push(arr[i]);
        }
        else {
            minHeap.push(arr[i]);
            minHeap.pop();
        }   
    }

    vector<int> ans;
    while(minHeap.empty() == false){
        ans.push_back(minHeap.top()); minHeap.pop();
    }
    return ans;
}

int main() {
    int arr[100];
    int n; cin >> n;
    inputArr(arr, n);
    int k; cin >> k;
    vector<int> ans = bestKElements(arr, n, k);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}