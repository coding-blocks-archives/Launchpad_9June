// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <iomanip>
using namespace std;

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int maxProfit(int arr[], int beginIdx, int endIdx){
    if (beginIdx > endIdx) {
        return 0;
    }

    if (memo[beginIdx][endIdx] != -1){
        // profit aleardy analysed
        return memo[beginIdx][endIdx];
    }

    int year = endIdx - beginIdx + 1;
    int sellFromFront = arr[beginIdx] * year + maxProfit(arr, beginIdx + 1, endIdx);
    int sellFromEnd = arr[endIdx] * year + maxProfit(arr, beginIdx , endIdx - 1);
    return memo[beginIdx][endIdx] = max(sellFromEnd, sellFromEnd);

}

void outputMat(int mat[][100], int m, int n){
    cout << "\n-----MAT Begins----\n";
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cout << setw(3) << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}

int maxProfit(int arr[], int n) {
    int dp[100][100];

    // for length = 1
    for(int srt = 0; srt < n; ++srt){
        dp[srt][srt] = n * arr[srt];
    }

    for (int len = 2; len <= n; ++len) {
        int year = n - len + 1;
        int startIdx = 0;
        int maxStartIdx = n - len;
        while (startIdx <= maxStartIdx) {
            int endIdx = startIdx + len - 1;
            int sellFromFront = arr[startIdx] * year + dp[startIdx + 1][endIdx];
            int sellFromEnd = arr[endIdx] * year + dp[startIdx][endIdx - 1];
            dp[startIdx][endIdx] = max(sellFromEnd, sellFromFront);
            ++startIdx;
        }
    }
    outputMat(dp, n, n);
    return dp[0][n - 1];
}


int main() {
    int arr[100];
    int n; cin >> n;
    inputArr(arr, n);

    int ans = maxProfit(arr, n);
    cout << ans;
}