// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void inputMat(int mat[][10], int m, int n) {
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> mat[r][c];
        }
    }
}

void printDiag(int mat[][10], int m, int n){
    int minm = m > n ? n : m;
    for(int x = 0; x < minm; ++x){
        cout << mat[x][x] << " ";
    }
}

void outputMat(int mat[][10], int m, int n){
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat[10][10];
    int m, n;
    cin >> m >> n;
    inputMat(mat, m, n);
    // outputMat(mat, m, n);
    printDiag(mat, m, n);
}