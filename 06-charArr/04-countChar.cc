// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
#define print(x) cout << #x << "\t:" << x << endl

bool isSpace(char c) { return c == ' ';}
bool isEnter(char c) { return c == '\n';}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') or (c >= 'A' && c <= 'Z');
}

void countChar(int& nwords, int& nalphabets, int& ndigits,
               int& nothers, int& nspaces, int& nenter) {
    char c;
    bool insideWord = false;
    while (true) {
        c = cin.get();
        if (c == '$') {
            if (insideWord) ++nwords;
            return;
        }
        if (isAlpha(c)) {
            insideWord = true;
            ++nalphabets;
        }
        else if (isDigit(c)) {
            insideWord = true;
            ++ndigits;
        }
        else if (isEnter(c)) {
            if (insideWord) ++nwords;
            insideWord = false;
            ++nenter;
        }
        else if (isSpace(c)) {
            if (insideWord) ++nwords;
            insideWord = false;
            ++nspaces;
        }
        else {
            ++nothers;
        }
    }

}

int main() {
    int nwords = 0;
    int nalphabets = 0;
    int ndigits = 0;
    int nothers = 0;
    int nspaces = 0;
    int nenter = 0;

    countChar(nwords, nalphabets, ndigits, nothers, nspaces, nenter);

    print(nwords);
    print(nalphabets);
    print(ndigits);
    print(nothers);
    print(nspaces);
    print(nenter);
}