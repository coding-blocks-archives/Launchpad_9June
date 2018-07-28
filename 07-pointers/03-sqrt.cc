// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int mySqrt(int num){
    int root = 0;
    while(root * root <= num){
        root++;
    }
    return root - 1;
}

int mySqrt2(int num){
    int be = 0;
    int en = num;
    while(be <= en){
        int mid = (be + en) / 2;
        if (mid * mid <= num){
            be = mid + 1;
        }
        else {
            en = mid - 1;
        }
    }
    return en;
}

int main(){
    int num;
    cin >> num;
    int ans = mySqrt2(num);
    cout << ans;   
}