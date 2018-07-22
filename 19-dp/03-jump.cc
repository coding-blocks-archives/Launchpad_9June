// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

int counter = 0;
const int inf = 1e6;
int minMoves(int arr[], int beginIdx, int endIndx) {
    if (beginIdx > endIndx) {
        return inf;
    }

    if (beginIdx == endIndx) {
        return 0;
    }

    ++counter;      // because the below code COMPUTES the value

    int bestAns = inf;

    int potentialStepsToBeTaken = arr[beginIdx];
    for (int curStep = 1; curStep <= potentialStepsToBeTaken; ++curStep) {
        int nextIndex = beginIdx + curStep;
        int minStepsFrmNextIndex = minMoves(arr, nextIndex, endIndx);
        int totalStepsFrmCurIndex = 1 + minStepsFrmNextIndex;
        bestAns = min(bestAns, totalStepsFrmCurIndex);
    }
    return bestAns;
}

int minMoves(int arr[], int beginIdx, int endIndx, int *memoPad) {
    if (beginIdx > endIndx) {
        return inf;
    }

    if (beginIdx == endIndx) {
        return 0;
    }

    if (memoPad[beginIdx] != -1) {
        // already computed
        return memoPad[beginIdx];
    }

    ++counter;  // because the below code COMPUTES the value

    int bestAns = inf;

    int potentialStepsToBeTaken = arr[beginIdx];
    for (int curStep = 1; curStep <= potentialStepsToBeTaken; ++curStep) {
        int nextIndex = beginIdx + curStep;
        int minStepsFrmNextIndex = minMoves(arr, nextIndex, endIndx, memoPad);
        int totalStepsFrmCurIndex = 1 + minStepsFrmNextIndex;
        bestAns = min(bestAns, totalStepsFrmCurIndex);
    }
    memoPad[beginIdx] = bestAns;    // register....DO NOT FORGET Dude!!!
    return bestAns;
}

int minMoves(int arr[], int n) {
    int *dp = new int[n];
    dp[n - 1] = 0;

    for (int idx = n - 2; idx >= 0; --idx) {
        int potentialStepsToBeTakenFrmIthBox = arr[idx];
        int minAns = 1e6;
        for (int curStep = 1; curStep <= potentialStepsToBeTakenFrmIthBox; ++curStep) {

            int nextBox = idx + curStep;
            if (nextBox < n) {
                int noOfMovesReqToReachViaNextBox = 1 + dp[nextBox];
                minAns = min(minAns, noOfMovesReqToReachViaNextBox);
            }
        }
        dp[idx] = minAns;
    }

    return dp[0];
}

int main() {
    int n;
    cin >> n;

    int arr[100];
    inputArr(arr, n);

    // int ans = minMoves(arr, 0, n - 1);
    // cout << ans << counter;

    // int *memoPad = new int[n];
    // for(int i = 0; i < n; ++i) {
    //     memoPad[i] = -1;
    // }
    // int ans = minMoves(arr, 0, n - 1, memoPad);
    // cout << ans << " " << counter;

    int ans = minMoves(arr, n);
    cout << ans;
}