// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int phoneNumber;
    Node* next;
    Node() {
        // default
        name = "";
        phoneNumber = 0;
        next = NULL;
    };
    Node(string n, int p) {
        name = n;
        phoneNumber = p;
    }
};

class HashTable {
    Node** table;
    int capacity;
    int sze;

    void insertIntoTable(Node* contact) {
        int idx = getIdx(contact->name);
        Node* &head = table[idx];
        contact->next = head;
        head = contact;
    }

    int getIdx(string str) {
        int ans = 0;
        const int multiplier = 27;
        int power = 0;
        for (int i = 0; i < str.size(); ++i) {
            char curChar = str[i];
            int curCharDig = curChar - 'a';
            ans = ans + ((curCharDig % capacity) * power) % capacity;
            ans = ans % capacity;
            power = power * (multiplier % capacity) % capacity;
        }
        return ans;
    }

public:
    HashTable() {
        capacity = 7;   // research
        sze = 0;
        table = new Node*[capacity];
    }

    void insert(string nameToInsert, int phoneNumberToInsert) {
        Node* contact = new Node(nameToInsert, phoneNumberToInsert);
        insertIntoTable(contact);
    }

    int find(string name){

    }

};


int main() {

}