// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int* findBestElementInRight(int arr[], int n) {
    // int ans[100];
    int* ans = new int[n];
    stack<int> stk;

    for (int i = n - 1; i >= 0; --i) {
        int curElement = arr[i];
        while (stk.empty() == false && curElement > stk.top()) {
            stk.pop();
        }
        ans[i] = stk.empty() ? -1 : stk.top();
        stk.push(curElement);
    }
    return ans;
}

void pushIntoDeque(deque<int>& deq, int arr[], int index){
    while(deq.empty() == false && arr[deq.back()] < arr[index]){
        deq.pop_back();
    }
    deq.push_back(index);
}

vector<int> findBestInWindow(int arr[], int n, int k) {
    typedef int index;
    deque<index> deq;
    // int* ans = new int[n];
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        pushIntoDeque(deq, arr, i);
        if (i >= k - 1){
            // ans[i] = arr[deq.front()];
            ans.push_back(arr[deq.front()]);
            if (deq.front() == i - k + 1){
                deq.pop_front();
            }
        }
    }
    return ans;
}

bool isValidBracketSeq(char* sequence){
    stack<char> stk;

    for(int i = 0; sequence[i] != '\0'; ++i){
        if (sequence[i] == '('){
            stk.push('(');
        }
        else {
            if (stk.empty()) return false;
            stk.pop();
        }
    }
    return stk.empty() == true;
}


int main() {
    // int arr[100];
    // int n; cin >> n;
    // for (int i = 0; i < n; ++i) {
    //     cin >> arr[i];
    // }
    // int k; cin >> k;
    // vector<int> ans = findBestInWindow(arr, n, k);
    // for (int i = 0; i < ans.size(); ++i) {
    //     cout << ans[i] << " ";
    // }

    char arr[100];
    cin >> arr;
    bool isValid = isValidBracketSeq(arr);
    cout << isValid;

}