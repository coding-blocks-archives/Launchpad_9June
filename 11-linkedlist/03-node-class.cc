// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

createLL(){
    Node* head = NULL;
    Node* tail = NULL;
    int x;
    
    while(true){
        cin >> x;
        if (x == -1) break;

        Node* newNode = new Node(x);
        // (*newNode).data = x;    // newNode->data, arrow operator

        if (head == NULL){
            // list is EMPTY but now one node is there.
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;   // tail.next is WRONG!!!
            tail = tail->next;
        }
    }

}

int main(){
    Node* head = createLL();
}