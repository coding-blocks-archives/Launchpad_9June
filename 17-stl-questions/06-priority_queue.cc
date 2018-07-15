// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;

bool compareInt(int x, int y) {
    // shall x come before y
    return x > y;
}

bool compareInt2(int x, int y) {
    // shall x come before y
    return x > y;
}

class CompareInt {
public:
    bool operator()(int x, int y) { // overload bracket operator
        // shall x come before y
        return x > y;
    }
};


int main() {
    // bool (*compareIntType)(int, int) = compareInt;
    // priority_queue<int, vector<int>, bool(*)(int, int)> pq;
    priority_queue<int, vector<int>, CompareInt> pq;
    pq.push(1);
    pq.push(2);
    cout << pq.top();
}