// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

string convertToNum(int n){
    string ans = "";
    while(n > 0){
        int unitDig = n % 10;
        ans.push_back(unitDig + '0');
        n = n / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool compareLexicographical(int a, int b){
    // 121 1    
    // string num1 = to_string(a);     // num1("a ki value se")
    // string num2 = to_string(b);     // y(a);
    // return num1 < num2;             // num1.operator<(num2)

    // char tmp[100];
    // string num1 = itoa(a, tmp, 10);
    // string num2 = itoa(b, tmp, 10);
    // return num1 < num2;

    string num1, num2;
    num1 = convertToNum(a);
    num2 = convertToNum(b);
    return num1 < num2;
}

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), compareLexicographical);
    reverse(v.begin(), v.end());
    
    for(int i = 0; i < n; ++i){
        cout << v[i] << " ";
    }
    
}