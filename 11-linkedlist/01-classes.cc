// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void write(char brand[], char color[], char words[]){
    cout << brand << " is writing\" " << words << "\" with color " << color << endl;
}

int main(){
    char pen1Brand[] = "parker";
    char pen1Color[] = "black";
    
    char pen2Brand[] = "montex"; 
    char pen2Color[] = "blue";

    char car1Brand[] = "Audi";

    char words[] = "Thousands have lived without love, not one without water.";

    write(car1Brand, pen2Color, words);

}