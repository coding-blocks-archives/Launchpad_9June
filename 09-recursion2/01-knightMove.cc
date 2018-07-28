// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <iomanip>
using namespace std;
void outputMat(int mat[][100], int m, int n) {
    cout << "\n-----MAT Begins----\n";
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << setw(4) << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}

bool canVisit(int board[][100], int r, int c, int n) {
    return
        r >= 0 && r < n &&
        c >= 0 && c < n &&
        board[r][c] == 0;
}


bool knightSolve(int board[][100], int n, int r, int c, int moveNo) {
    if (moveNo == n * n) return true;

    int rowDir[] = { +2, +2, +1, -1, -2, -2, -1, +1};
    int colDir[] = { +1, -1, -2, -2, -1, +1, +2, +2};
    // int rowDir[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    // int colDir[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    for (int i = 0; i < 8; ++i) {
        int nextRow = r + rowDir[i];
        int nextCol = c + colDir[i];
        if (canVisit(board, nextRow, nextCol, n) == true) {
            board[nextRow][nextCol] = moveNo;
            bool success = knightSolve(board, n, nextRow, nextCol, moveNo + 1);
            if (success) return true;
            board[nextRow][nextCol] = 0;    // 0 represents unvisited
        }
    }
    return false;
}



int main() {
    int board[100][100] = {};   // initialisation

    int N; cin >> N;
    board[0][0] = -1;
    bool ans = knightSolve(board, N, 0, 0, 1);

    if (ans == true) {
        // knight was able to solve the board
        outputMat(board, N, N);
    }
    else {
        cout << "Sorry man.. Board cannot be visited\n";
    }

}