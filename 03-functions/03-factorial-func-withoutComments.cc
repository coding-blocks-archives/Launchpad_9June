// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int factorial(int n){
    int ans = 1;
    for(int x = 1; x <= n; ++x){
        ans = ans * x;
    }
    return ans;
}

int main(){
    int n, r;
    cout << "enter n r";
    cin >> n >> r;

    // int factorial(int ){};   // WRONG!!! CANT DEFINE ONE FUCN IN ANOTHER FUNC
    int factorial(int );
    int factorial(int n);

    int nfact = factorial(n);
    int rfact = factorial(r);
    int nrfact = factorial(n - r);
    int ans = nfact / rfact / nrfact;
    cout << ans << endl;
}
