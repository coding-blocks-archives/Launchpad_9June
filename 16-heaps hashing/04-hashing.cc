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
        next = NULL;
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
        ++sze;
        if (loadFactor() > 0.7){
            rehash();
        }
    }

    double loadFactor(){
        return (double) sze / capacity;
    }

    void rehash(){
        cout << "Current size " << sze << " Rehashing in progess....\n";
        Node** oldTable = table;
        int oldCapacity = capacity;
        capacity = 2 * capacity;
        table = new Node*[capacity];
        clearTable();
        sze = 0;

        for(int i = 0; i < oldCapacity; ++i){
            Node* head = oldTable[i];
            Node* cur = head;
            while(cur){
                head = cur->next;
                cur->next = NULL;
                insertIntoTable(cur);
                cur = head;
            }
        }
        delete [] oldTable;
        cout << "Rehashing successfully completed\n";
    }

    int getIdx(string str) {
        int ans = 0;
        const int multiplier = 27;
        int power = 1;
        for (int i = 0; i < str.size(); ++i) {
            char curChar = str[i];
            int curCharDig = curChar - 'a';
            ans = ans + ((curCharDig % capacity) * power) % capacity;
            ans = ans % capacity;
            power = (power * (multiplier % capacity)) % capacity;
        }
        return ans;
    }

    void clearTable(){
        for(int i = 0; i < capacity; ++i){
            table[i] = NULL;
        }
    }
public:
    HashTable() {
        capacity = 7;   // research
        sze = 0;
        table = new Node*[capacity];
        clearTable();
    }

    void insert(string nameToInsert, int phoneNumberToInsert) {
        Node* contact = new Node(nameToInsert, phoneNumberToInsert);
        insertIntoTable(contact);
    }

    int find(string name){

    }

    void printTable(){
        for(int i = 0; i < capacity; ++i){
            cout << i << ": "; 
            Node* head = table[i];
            while(head){
                cout << head->name << "(" << head->phoneNumber << ") ";
                head = head->next; 
            }
            cout << endl;
        }
    }

    ~HashTable(){
        // do as homework
        for(int i = 0; i < capacity; ++i){
            Node* head = table[i];
            while(head){
                Node* tmp = head->next;
                delete head;
                head = tmp; 
            }
        }
        delete [] table;
    }
};


int main() {
    HashTable h;
    h.insert("abc", 123);
    h.insert("def", 456);
    h.insert("hij", 789);
    h.insert("lkm", 890);
    h.insert("zara", 123); 
    h.insert("abczy", 123);
    h.insert("defzy", 456);
    h.insert("hijzy", 789);
    h.insert("lkmzy", 890);
    h.insert("zarazy", 123);
    h.printTable();
}