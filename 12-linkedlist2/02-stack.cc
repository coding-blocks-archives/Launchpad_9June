// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int sze;
public:
    Stack() {
        sze = 0;
    }

    void push(int x) {
        arr[sze] = x;
        ++sze;
    }

    void pop() {
        if (sze == 0) return;
        --sze;
    }
    
    int size() {
        return sze;
    }
    
    bool empty() {
        return sze == 0;
    }

    int top() {
        if (empty()) return -1;
        return arr[sze - 1];
    }
};


int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.top();
    s.pop();
    s.top();
    s.pop();
    s.pop();
    s.pop();
    s.top();
    s.top();
    s.push(-100);
    s.top();
}