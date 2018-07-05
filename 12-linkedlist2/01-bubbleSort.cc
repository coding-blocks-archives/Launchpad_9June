// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next; // self referential classes
    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* createLL() {
    int x;
    Node* head = NULL;
    Node* tail = NULL;
    while (true) {
        cin >> x;
        if (x == -1) break;
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            (*tail).next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

void printLL(const Node* head) {
    const Node* cur = head;
    while (cur) {
        cout << cur->data << "-->"; cur = cur->next;
    }
    cout << endl;
}

Node* mergeSortedLL(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    if (head1->data < head2->data) {
        head1->next = mergeSortedLL(head1->next, head2);
        return head1;
    }
    else {
        head2->next = mergeSortedLL(head1, head2->next);
        return head2;
    }
}
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL)  return head;

    // Node* mid = midPoint(head);
    // Node* head2 = mid->next;
    // mid->next = NULL;
    // Node* head1 = mergeSort(head);
    // Node* secondHead = mergeSort(head2);

    // return mergeSortedLL(head1, secondHead);
}


Node* reverseRec(Node* head) {
    if (head == NULL || head->next == NULL)  return head;

    Node* newHead = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

Node* reverseIterative(Node* head) {
    if (head == NULL || head->next == NULL)  return head;
    Node *prev = NULL, *cur = head;
    while (cur != NULL) {
        Node* ahead = cur->next;
        cur->next = prev;
        prev = cur;
        cur = ahead;
    }
    return prev;
}

int lengthLL(Node* head) {
    if (head == NULL)  return 0;
    return 1 + lengthLL(head->next);
}

Node* bubbleSort(Node* head) {
    if (!head or !head->next)    return head;

    int len = lengthLL(head);
    for (int i = 0; i < len; i++) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr && curr->next) {
            Node* ahead = curr->next;
            if (curr->data > ahead->data) {
                if (prev != NULL) {
                    curr->next = ahead->next;
                    ahead->next = curr;
                    prev->next = ahead;
                    prev = ahead;
                }
                else {
                    // need to change the head of the LL
                    curr->next = ahead->next;
                    ahead->next = curr;
                    head = ahead;
                    prev = head;
                }
            }
            else {
                prev = curr;
                curr = ahead;
            }

        }
    }
    return head;
}

Node* kReverse(Node* head, int k){
    if (head == NULL) return head;

    int counter = 0;
    Node* cur = head;
    Node* previous = NULL;
    while(counter < k and cur){
        Node* ahead = cur->next;
        cur->next = previous;
        previous = cur;
        cur = ahead;
        ++counter;
    }
    head->next = kReverse(cur, k);
    return previous;
}


int main() {
    Node* head = createLL();
    printLL(head);
    // head = bubbleSort(head);
    int k; cin >> k;
    head = kReverse(head, k);
    printLL(head);
}