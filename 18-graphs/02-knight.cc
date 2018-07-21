// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <queue>
using namespace std;

int knightMove(int board[][8], int xSrc, int ySrc, int xDest, int yDest) {
    queue<int> xcoord;
    queue<int> ycoord;

    bool visited[8][8] = {};

    xcoord.push(xSrc);
    ycoord.push(ySrc);
    visited[xSrc][ySrc] = true; // this cell has been visited
    board[xSrc][xDest] = 0;

    const int rowDir [] = { +1, +2, +2, +1, -1, -2, -2, -1};
    const int colDir [] = { +2, +1, -1, -2, -2, -1, +1, +2};

    while (xcoord.empty() == false) {
        int curX = xcoord.front();  xcoord.pop();
        int curY = ycoord.front();  ycoord.pop();

        if (curX == xDest && curY == yDest) return board[curX][curY];

        for (int i = 0; i < 8 ; ++i) {
            int nextX = curX + rowDir[i];   // edges are generated in real time
            int nextY = curY + colDir[i];
            if (nextX >= 0 && nextX < 8 && nextY >= 0 && nextY < 8 && visited[nextX][nextY] == false) {
                visited[nextX][nextY] = true;
                board[nextX][nextY] = board[curX][curY] + 1;
                xcoord.push(nextX);
                ycoord.push(nextY);
            }
        }
    }
    return -1;
}

int main() {
    int board[8][8] = {};
    int xSrc, ySrc, xDest, yDest;
    cin >> xSrc >> ySrc;
    cin >> xDest >> yDest;

    int minAns = knightMove(board, xSrc, ySrc, xDest, yDest);
    cout << minAns;
}