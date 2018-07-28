// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    cout << (10 / 3) << endl;
    cout << (10.0 / 3) << endl;

    double x = 10 / 3;      // 3. RHS is int
    double y = 10.0 / 3;    // 3.33
    int z = 10.0 / 3.0;     // truncation. LHS is int
}