// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;
void inputMat(char mat[][100], int m, int n){
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cin >> mat[r][c];
        }
    }
}
void outputMat(char mat[][100], int m, int n){
    cout << "\n-----MAT Begins----\n";
    for(int r = 0; r < m; ++r){
        for(int c = 0; c < n; ++c){
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}


void spiralPrint(char mat[][100], int m, int n){
    int startRow = 0, endRow = m - 1;
    int startCol = 0, endCol = n - 1;

    while(startRow <= endRow && startCol <= endCol){
        // print startRow
        for(int c = startCol; c <= endCol; ++c){
            cout << mat[startRow][c];
        }
        ++startRow;     // loop invariant

        // print endCol
        for(int r = startRow; r <= endRow; ++r){
            cout << mat[r][endCol];
        }
        --endCol;

        // print endRow
        for(int c = endCol; endRow >= startRow && c >= startCol; --c){
            cout << mat[endRow][c];
        }
        --endRow;

        // print startCol
        for(int r = endRow; startCol <= endCol && r >= startRow; --r){
            cout << mat[r][startCol];
        }
        ++startCol;
    }
}



int main(){
    char mat[100][100];
    int m, n;
    cin >> m >> n;
    inputMat(mat, m, n);
    outputMat(mat, m, n);
    spiralPrint(mat, m, n);       
}