// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
1
0 1
1 0 1
*/
int main(){
    int n;
    cin >> n;

    for(int curRow = 1; curRow <= n; ++curRow){
        int val = curRow % 2;
        for(int i = 1; i <= curRow; ++i){
            cout << val << " ";
            val = val == 0 ? 1 : 0;  // can also be written val = 1 - val. Toggle
        }
        cout << endl;   //DONT forget enter
    }
}