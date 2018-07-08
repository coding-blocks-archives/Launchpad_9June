// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int sum(double x, int y){
    cout << "SUM with int return\n";
    return x + y;

}

double sum(int x, double y){
    cout << "SUM with double return\n";
    return x + y;
}

int main(){
    int ans1 = sum(2, 3);
    double ans2 = sum(2.0, 3.0);
    int ans3 = sum('a', 'b');
}