// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <string>
using namespace std;

class Elephant {
public:
    int wt;
    string name;
    Elephant(int w = 0, string n = "") {
        wt = w;
        name = n;
    }
};


template<typename T, typename Function>
int linearSearch(T arr[], int n, T key, Function comp) {
    // comp is a function that takes two elements in the arr
    // and return true if element 1 is equal to element 2

    for (int i = 0; i < n; ++i) {
        if (comp(arr[i], key) == true) {
            // if (compareElephat(arr[i], key) == true)
            return i;
        }
    }
    return -1;
}

// compareInt = bool (*)(int, int)
// compareElephat = bool(*)(Elephant, Elephant)



bool compareInt(int x, int y) {
    return x == y;
}

bool compareChar(char x, char y){
    return x == y;
}

bool compareElephat(Elephant e1, Elephant e2){
    return e1.name == e2.name;
}


int main() {
    char arrChar[] = "apple";
    int arrInt[] = {1, 2, 3};
    Elephant arrElephant[] = {{200, "Jumbo"}, {3000, "Hachi"}};

    int findInt = linearSearch(arrInt, 3, 2, compareInt);
    int findChar = linearSearch(arrChar, 3, 'a', compareChar);

    Elephant key(200, "Jumbo");
    int findElephant = linearSearch(arrElephant, 2, key, compareElephat);

}