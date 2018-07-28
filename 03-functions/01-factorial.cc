// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
int main(){
    int n, r;
    cout << "enter n r";
    cin >> n >> r;

    int nfact = 1;
    for(int x = 1; x <= n; ++x){
        nfact = nfact * x;
    }   

    int rfact = 1;
    for(int x = 1; x <= r; ++x){
        rfact = rfact * x;
    }

    int nrfact = 1;
    for(int x = 1; x <= n-r; ++x){
        nrfact = nrfact * x;
    }

    int ans = nfact / rfact / nrfact;
    cout << ans << endl;
}