// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

int factorial(int n) {
    // here we have a function that gives factorial of n

    if (n <= 0) { return 1; }

    int smallFact = factorial(n - 1);
    int ans = smallFact * n;
    return ans;
}

void printInc(int n) {
    if (n == 0) return;

    printInc(n - 1);
    cout << n << " ";
}

void printDec(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    printDec(n - 1);
}

void printDig(int dig) {
    char digToWords[][10] = {
        "zero", "one", "two",
        "three", "four", "five",
        "six", "seven", "eight", "nine"
    };
    cout << digToWords[dig]; // mat[0][0] mat[3]
}

void printNum(int num) {
    if (num == 0) return ;

    int unitDig = num % 10;
    printNum(num  / 10);        // TWO ZERO FOUR
    printDig(unitDig);          // EIGHT
    cout << " ";                // _
}

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int previous = fibonacci(n - 1);
    int superPrevious = fibonacci(n - 2);
    int curFib = previous + superPrevious;
    return curFib;
}

void displayArrRev(int* arr, int n) {
    if (n == 0) return;     // n represents the number of elements

    cout << arr[n  - 1] << " ";
    displayArrRev(arr, n - 1);
}

void bubbleSort(int arr[], int be, int n) {
    if (be >= n) return;        // empty array

    bubbleSort(arr, be + 1, n);
    if (be + 1 < n && arr[be + 1] < arr[be]) {
        swap(arr[be + 1], arr[be]);     // be now has smallest element
        bubbleSort(arr, be + 1, n);
    }
}

bool isArrSorted(int arr[], int be, int en) { // [be, en] // [be, n)
    if (be >= en) {
        // either 0 or 1 elements
        return true;
    }
    // now I have atleast 2 elements
    if (arr[be] > arr[be + 1]) return false;
    return isArrSorted(arr, be + 1, en);
}

int binarySearchRec(int arr[], int be, int en, int key) {
    if (be > en) return -1;

    int mid = (be + en) / 2;
    if (arr[mid] == key) return mid;

    if (arr[mid] < key) {
        // answer lies in the right
        int ans = binarySearchRec(arr, mid + 1, en, key);
        return ans;
    }
    else {
        // agar hua toh left mai hua
        return binarySearchRec(arr, be, mid - 1, key);
    }

}

bool ratInMaze(char board[][10], int r, int c, int dim) {
    if (r == dim - 1 && c == dim - 1) {
        board[r][c] = 'V';
        return true;
    }

    if (r >= dim) return false;
    if (c >= dim) return false;

    if (board[r][c] == 'X') return false;

    board[r][c] = 'V';
    bool moveForward = ratInMaze(board, r, c + 1, dim);
    if (moveForward == true) return true;
    bool moveDownward = ratInMaze(board, r + 1, c, dim);
    if (moveDownward) return true;

    board[r][c] = '.';
    return false;
}

void inputMat(char mat[][10], int m, int n) {
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cin >> mat[r][c];
        }
    }
}
void outputMat(char mat[][10], int m, int n) {
    cout << "\n-----MAT Begins----\n";
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
    cout << "-----MAT Ends------\n";
}
int main() {
    // int n; cin >> n;
    // int ans = factorial(n);
    // cout << ans;

    // int n; cin >> n;
    // printInc(n);

    // int n; cin >> n;
    // printDec(n);

    // int n; cin >> n; printNum(n);

    int n; cin >> n; 
    int ans = fibonacci(n);
    cout << ans;

    // int arr[] = {1, 2, 3, 4}; int n = 4;
    // displayArrRev(arr, n);

    // int arr[] = {3, 1, 4, 2};
    // bubbleSort(arr, 0, 4);
    // displayArrRev(arr, 4);

    // int arr[] = {1, 2, -1, 4,5};
    // bool ans = isArrSorted(arr, 0, 4);
    // cout << ans;

    // int arr[] = {1, 2, 3, 4, 5};
    // int ans = binarySearchRec(arr, 0, 4, 100);
    // cout << ans;

    // char board[10][10] = {}; int n; cin >> n;
    // inputMat(board, n, n);
    // bool ans = ratInMaze(board, 0, 0, n);
    // if (ans) {
    //     outputMat(board, n, n);
    // }
    // else {
    //     cout << "Dear Jerry, you will kill yourself!!!";
    // }

}