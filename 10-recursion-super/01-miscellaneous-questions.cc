// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;

void printAllSubsequences(char str[], int be, char decision[],  int i) {
    if (str[be] == '\0') {
        decision[i] = '\0';
        cout << decision << endl;
        return;
    }
    printAllSubsequences(str, be + 1, decision, i); // exclude current char
    decision[i] = str[be];
    printAllSubsequences(str, be + 1, decision, i + 1); // include current char
}

int cnt = 0;
void printPermutations(char arr[], int be) {
    if (arr[be] == '\0') {
        ++cnt;
        cout << cnt << " " << arr << endl;
        return;
    }

    for (int i = be; arr[i] != '\0'; ++i) {
        swap(arr[i], arr[be]);
        printPermutations(arr, be + 1);
        swap(arr[i], arr[be]);  // restore the changes
    }
}

void getCode(char ansArr[], char digitOnKeyPad) {
    char allCodes[][10] = {
        " ",
        "$%?*", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    strcpy(ansArr, allCodes[digitOnKeyPad - '0']);
}


void printCodes(char numericString[], int be, char ans[]) {
    if (numericString[be] == '\0') {
        ans[be] = '\0';
        cout << ans << endl;
        return;
    }

    char curDig = numericString[be];    // '2'
    char code[100];
    getCode(code, curDig);      // 2--> abc

    for (int j = 0; code[j] != '\0'; ++j) {
        ans[be] = code[j];   // a [RECURSION]
        printCodes(numericString, be + 1, ans);
    }
}

int stepNo = 0;
void tower(int n, char src, char dest, char helper) {
    if (n == 0) return;
    tower(n - 1, src, helper, dest);
    cout << ++stepNo << ". " << n << ":" << src << "-->" << dest << endl;
    tower(n - 1, helper, dest, src);

}

bool isPalindrome(char arr[], int be, int en) {
    while (be < en) {
        if (arr[be] != arr[en]) return false;
        ++be; --en;
    }
    return true;
}

void printStr(char arr[], int be, int en) {
    while (be <= en) { cout << arr[be]; be++; }
}

void palindromePartioning(char str[], int be) {
    if (str[be] == '\0') {
        cout << "-----" << endl;
        return;
    }

    for (int i = be; str[i] != '\0'; ++i) {
        if (isPalindrome(str, be, i)) {
            printStr(str, be, i); // [be, i]
            cout << endl;
            palindromePartioning(str, i + 1);
        }
    }
}


int main() {
    char arr[100];
    char tmp[100];

    // cin >> arr;
    // printAllSubsequences(arr, 0, tmp, 0);
    // printPermutations(arr, 0);
    // printCodes(arr, 0, tmp);

    // int n; cin >> n;
    // tower(n, 'A', 'B', 'C');

    cin >> arr;
    palindromePartioning(arr, 0);
}