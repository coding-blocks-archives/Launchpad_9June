// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* createLL() {
    Node* head = NULL;
    Node* tail = NULL;
    int x;

    while (true) {
        cin >> x;
        if (x == -1) break;

        Node* newNode = new Node(x);
        // (*newNode).data = x;    // newNode->data, arrow operator

        if (head == NULL) {
            // list is EMPTY but now one node is there.
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;   // tail.next is WRONG!!!
            tail = tail->next;
        }
    }
    return head;
}

void printLL(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        // I have a cur node for printing
        cout << cur->data << "-->";
        cur = cur->next;
    }
    cout << endl;
}

Node* midPoint(Node* head){
    Node* slow = head;
    Node* fast = head;
    // GO
    while(slow && fast && fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSortedLists(Node* head1, Node* head2){
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    // BOTH list have atleast one-one node
    Node* ans = NULL;

    if (head1->data < head2->data){
        ans = head1;
        head1->next = mergeSortedLists(head1->next, head2);
        return ans;
    }
    else {
        ans = head2;
        head2->next = mergeSortedLists(head1, head2->next);
        return ans;
    }
}

int main() {
    // Node* head = createLL();
    // printLL(head);
    // Node* middle = midPoint(head);
    // cout << middle << " " << (middle ? middle->data : -1);

    Node* head1 = NULL;
    Node* head2 = NULL;
    head1 = createLL();
    head2 = createLL();
    Node* mergeListAns = mergeSortedLists(head1, head2);
    printLL(mergeListAns);
}