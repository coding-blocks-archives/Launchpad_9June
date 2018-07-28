// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
1
12
123
1234
*/

int main() {
    int nLines;
    cin >> nLines;

    for (int lineNo = 1; lineNo <= nLines; ++lineNo) {
        for (int val = 1; val <= lineNo; ++val) {
            cout << val << " ";
        }
        cout << endl;
    }

}