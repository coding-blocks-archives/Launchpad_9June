// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputMat(char mat[][100], int m, int n) {
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> mat[r][c];
        }
    }
}
void outputMat(char mat[][100], int m, int n) {
    cout << "\n-----MAT Begins----\n";
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}

void rotateMat(char mat[][100], int n){
    int tmp[100][100];
    for(int r = 0; r < n; ++r){
        for(int c = 0; c < n; ++c){
            tmp[n-c-1][r] = mat[r][c];
        }
    }

    // copy back
    for(int r = 0; r < n; ++r){
        for(int c = 0; c < n; ++c){
            mat[r][c] = tmp[r][c];
        }
    }

}


int main() {
    int n;
    cin >> n;
    char mat[100][100];
    inputMat(mat, n, n);
    outputMat(mat, n, n);
    rotateMat(mat, n);
    outputMat(mat, n, n);
}