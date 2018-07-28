// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
/*
  *
 ***
*****
 ***
  *
*/
int main(){
    int nLines; cin >> nLines;

    int incLines = nLines / 2 + 1;
    int decLines = nLines - incLines;

    // print Inc Pattern
    for(int curRow = 1; curRow <= incLines; ++curRow){
        int nSpace = incLines - curRow;
        int nStars = 2 * curRow - 1;

        for(int i = 0; i < nSpace; ++i){
            cout << " ";
        }

        for(int i = 0; i < nStars; ++i){
            cout << "*";
        }
        cout << endl;
    }  

    // print Dec Pattern
    int nSpace = 1;
    for(int curRow = decLines; curRow >= 1; --curRow){
        int nStars = 2 * curRow - 1;
        for(int i = 0; i < nSpace; ++i){
            cout << " ";
        }
        ++nSpace;   // for the next iteration, we have set the value of nspace

        for(int i = 0; i < nStars; ++i){
            cout << "*";
        }
        cout << endl;
    }  
}