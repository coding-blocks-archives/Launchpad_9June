// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

class Pen{
public:
    char color[10];
    char brand[10];

    Pen(const char b[], const char c[]){
        strcpy(brand, b);
        strcpy(color, c);
    }

    void write(char words[]) {
        cout << brand << " is writing\" " << words << "\" with color " 
             << color << endl;
    }

};



int main() {
    // Pen p1, p2;
    // p1.setInitialValues("parker", "black");
    // cout << p1.color << endl;

    Pen p1("parker", "black");


    //----------------------------------

    char words[] = "Thousands have lived without love, not one without water.";

    p1.write(words);

}