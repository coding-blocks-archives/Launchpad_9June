// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
using namespace std;

class Book {
    string name;
    int ISBN;
public:
    Book(string s = "", int isbn = 0) {
        name = s;
        ISBN = isbn;
    }

    bool operator<(const Book& y) const { // compareBook(B1, B2); B1.compareBook(B2)
        // x is our calling object
        // return x.isbn < y.isbn;
        return ISBN < y.ISBN;
    }

    void printBook() {
        cout << name << " " << ISBN << endl;
    }
};

int main() {
    Book b[10] = {
        {"Harry Potter", 456},
        {"Rich Dad Poor Dad", 123},
        {"How I met her", 678}
    };
    sort(b, b + 3);

    for (int i = 0; i < 3; ++i) {
        b[i].printBook();
    }
}