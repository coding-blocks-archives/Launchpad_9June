// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
// next lexicolgraphical permutation
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    string s;
    cin >> s; // abcdef
    bool isPossible = next_permutation(s.begin(), s.begin() + 4);
    cout << s;
}