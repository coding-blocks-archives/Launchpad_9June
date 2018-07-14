// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <map>
#include <utility>
using namespace std;
int main(){
    map<string, int> m;
    m.insert(make_pair("abc", 123));
    cout << m["abc"];
    
}