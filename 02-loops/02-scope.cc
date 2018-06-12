// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int x = 1;
    // int x = 2; // ERROR

    {
        cout << x << endl;
        int x = 10;
        cout << x << endl;
    }

    cout << x << endl;

}