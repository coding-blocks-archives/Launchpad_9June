// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int n, r;
    cout << "enter n r";
    cin >> n >> r;

    int fact(int n);    // function declaration 

    // int nfact = use fact machine with input n;
    int nfact = fact(n);    // x = 2 +3 // function usage

    // int rfact = use fact machine with input r;
    int rfact = fact(r);

    // int nrfact = use fact machine with input n - r;
    int nrfact = fact(n - r);

    int ans = nfact / rfact / nrfact;
    cout << ans << endl;
}

int fact(int n){    // function definition
    int ans = 1;
    for(int x = 1; x <= n; ++x){
        ans = ans * x;
    }
    return ans;
}