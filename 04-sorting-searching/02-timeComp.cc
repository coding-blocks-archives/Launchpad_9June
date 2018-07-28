// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void print1(int n){
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        ++cnt;
        cout << i << " " << "Coding Blocks" << endl;
    }
    cout << "Total Number of times program ran " << cnt << endl;
}

void print2(int n){
    int cnt = 0;
    for(int i = 0; i < n*n; ++i){
        ++cnt;
        if (i < n) cout << i << " " << "Coding Blocks" << endl;
    }
    cout << "Total Number of times program ran " << cnt << endl;
}

int main(){
    int n;
    cin >> n;
    print1(n);
    print2(n);

}