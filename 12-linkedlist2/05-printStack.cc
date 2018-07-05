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

void emptyTo(stack<int>& from, stack<int>& to) {
    while (from.empty() == false) {
        to.push(from.top());
        from.pop();
    }
}

void reverseStack(stack<int>& s) {
    stack<int> s1, s2;
    emptyTo(s, s1);
    emptyTo(s1, s2);
    emptyTo(s2, s);
}

void shift(stack<int>& from, stack<int>& to, int numEleToShift){
    for(int i = 0; i < numEleToShift; ++i){
        int curEle = from.top(); from.pop();
        to.push(curEle);
    }
}

void reverseStackUsingOneStack(stack<int>& s) {
    stack<int> tmp;
    int sze  = s.size();
    for (int numOfEleSet = 0; numOfEleSet < sze; ++numOfEleSet){
        int curEle = s.top(); s.pop();
        shift(s, tmp, sze - numOfEleSet - 1);
        s.push(curEle);
        shift(tmp, s, sze - numOfEleSet - 1);
    }
}


int main() {
    stack<int> s;
    while (true) {
        int x; cin >> x;
        if (x == -1) break;
        s.push(x);
    }

    // printStk(s);
    // cout << s.size();

    reverseStackUsingOneStack(s);
    printStk(s);
}