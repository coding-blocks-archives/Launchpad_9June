// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;
    int sze;

    int parent(int idx) { return idx / 2; }
    int left(int idx)   { return 2 * idx; }
    int right(int idx)  { return 2 * idx + 1;}

    void heapify(int curIdx) {
        int maxIdx = curIdx;
        if (left(curIdx) <= sze && v[left(curIdx)] > v[curIdx]) {
            maxIdx = left(curIdx);
        }

        if (right(curIdx) <= sze && v[right(curIdx)] > v[curIdx]) {
            maxIdx = right(curIdx);
        }

        if (curIdx != maxIdx) {
            swap(v[curIdx], v[maxIdx]);
            heapify(maxIdx);
        }
    }

public:
    Heap() {
        v.push_back(-1);    // initialise
        sze = 0;
    }

    void push(int x) {
        v.push_back(x);
        ++sze;

        int curIdx = sze;

        while (parent(curIdx) >= 1 && v[parent(curIdx)] < v[curIdx]) {
            swap(v[curIdx], v[parent(curIdx)]);
            curIdx = parent(curIdx);
        }
    }

    void pop() {
        if (sze < 1) return;
        swap(v[1], v[sze]);
        v.pop_back();
        --sze;
        heapify(1);
    }

    int top() {
        if (sze < 1) return -1;
        return v[1];
    }
};

int main() {
    Heap maxHeap;
    maxHeap.push(52);
    cout << maxHeap.top() << endl;
    maxHeap.push(68);
    maxHeap.pop();
    maxHeap.push(100);
    cout << maxHeap.top() << endl;
    maxHeap.push(-3);
    maxHeap.pop();
    maxHeap.pop();
    maxHeap.push(-10);
    cout << maxHeap.top() << endl;
    maxHeap.push(-20);
    maxHeap.push(1200);
    maxHeap.pop();
    cout << maxHeap.top() << endl;
    maxHeap.push(68);

}