// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;

    for(int curNum = 1; curNum <= N; curNum = curNum + 2){
        cout << curNum << " ";
    }   
}