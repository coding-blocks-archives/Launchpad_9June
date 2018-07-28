// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <stack>
using namespace std;

void printStk(stack<int>& s) {
    while (s.empty() == false) {
        cout << s.top() << " ";
        s.pop();
    }
}

void insertAtBottom(stack<int>& s, int elementToInsert){
    if (s.empty()){
        s.push(elementToInsert);
        return;
    }

    int curElement = s.top(); s.pop();
    insertAtBottom(s, elementToInsert);
    s.push(curElement);
}

void reverseStack(stack<int>& s){
    if (s.empty()) return;

    int curElement = s.top(); s.pop();
    reverseStack(s);
    insertAtBottom(s, curElement);
}

int main() {
    stack<int> s;
    while (true) {
        int x; cin >> x;
        if (x == -1) break;
        s.push(x);
    }

    reverseStack(s);
    printStk(s);
}