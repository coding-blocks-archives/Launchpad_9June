// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main() {
    int initial, final, step;
    cout << "initial final step\n";
    // cin >> initial >> final >> step;

    for (int curFahr = initial; curFahr <= final; curFahr = curFahr + step) {
        double cel = 5.0 / 9.0 * (curFahr - 32.0);
        cout << curFahr << "\t" << cel << endl;
    }
}