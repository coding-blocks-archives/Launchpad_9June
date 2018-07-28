// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
    map<string, int> m;
#include <iostream>
#include <map>
#include <utility>
using namespace std;
int main(){
    m.insert(make_pair("abc", 123));
    cout << m["abc"];
    
}