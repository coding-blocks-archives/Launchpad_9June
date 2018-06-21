// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int cntChar(){
    char c;
    int cnt = 0;
    while(true){
        cin >> c;
        if (c == '$') break;
        ++cnt;
    }
    return cnt;
}

int main(){
    int ans = cntChar();
    cout << ans;
}