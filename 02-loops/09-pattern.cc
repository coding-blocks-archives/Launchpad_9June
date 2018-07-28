// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
1*2*3*4*17*18*19*20
--5*6*7*14*15*16
----8*9*12*13
------10*11
*/

int main(){
    int nLines; cin >> nLines;
    int incVal = 1;
    int maxDecVal = nLines * (nLines + 1);

    for(int lineNo = nLines; lineNo >= 1; --lineNo){
        // incPattern
        for(int i = 0; i < lineNo; ++i){
            cout << incVal << "*";
            ++incVal;
        }

        //decPattern
        int startVal = maxDecVal - lineNo + 1;
        for(int val = startVal; val <= maxDecVal; ++val){
            cout << val << (val == maxDecVal ? "" : "*");
        }
        maxDecVal = startVal - 1;

        cout << endl;
    }    
}