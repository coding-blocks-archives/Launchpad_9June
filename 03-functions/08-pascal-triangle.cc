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

int ncr(int n, int r){
    int nfact = factorial(n);
    int rfact = factorial(r);
    int nrfact = factorial(n - r);
    return nfact / rfact / nrfact; 
}

void printLine(int lineNo){
    for(int r = 0; r <= lineNo; ++r){
        int val = ncr(lineNo, r);
        cout << val << " ";
    }
}


int main(){
    int n;
    cin >> n;
    for(int curLine = 0; curLine <= n; ++curLine){
        printLine(curLine); 
        cout << endl;
    }   
}