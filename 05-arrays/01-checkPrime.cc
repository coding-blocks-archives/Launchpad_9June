// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

bool checkPrime(int n){
    for(int div = 2; div * div <= n; ++div){
        if (n % div == 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    bool ans = checkPrime(n);
    cout << ans;   
}