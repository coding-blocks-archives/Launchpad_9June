// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

template<typename T>
class Stack {
    T arr[100];
    int sze;
public:
    Stack() {
        sze = 0;
    }

    void push(T x) {
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

    T top() {
        if (empty()) return T();
        return arr[sze - 1];
    }
};

int main(){

    Stack<double> sInt;
    cout << sInt.top();
    Stack<char> sChar;
    cout << "X" << sChar.top() << "X";

    
}