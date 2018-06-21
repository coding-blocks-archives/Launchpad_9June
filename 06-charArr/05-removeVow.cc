// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

bool isVowel(char c) {
    if (c >= 'A' && c <= 'Z') {
        c = 'a' + (c - 'A');        // convert to lowercase
    }
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': return true;
    }
    return false;
}


void removeVow(char arr[]) {
    // S(N) T(N)
    char tmp[200];
    int k = 0;

    for (int i = 0; arr[i] != '\0'; ++i) {
        char cur = arr[i];
        if (isVowel(cur) == false) {
            tmp[k] = cur;
            ++k;
        }
    }
    tmp[k] = '\0';

    // copy back to array
    for (int i = 0; tmp[i] != '\0'; ++i) {
        arr[i] = tmp[i];
    }
    arr[k] = '\0';
}
void removeVow3(char arr[]) {
    int vow = 0;
    int cur = 0;
    while(arr[cur] != '\0'){
        if (isVowel(arr[cur]) == false){
            swap(arr[cur], arr[vow]);
            ++vow;
            ++cur;
        }
        else {
            ++cur;
        }
    }
    arr[vow] = '\0';
    
}
void removeVow2(char arr[]) {
    // T(N) S(1)
    int i = 0;
    while(arr[i] != '\0'){
        if (isVowel(arr[i])){
            // shift
            int j = i + 1;
            while(arr[j] != '\0'){
                arr[j - 1] = arr[j];
                ++j;
            }
            arr[j-1] = '\0';
        }
        else {
            ++i;
        }
    }
}

int main() {
    char arr[200]; 
    // int n; cin >> n; cin.get(); // consume enter
    cin.getline(arr, 150);
    removeVow3(arr);
    cout << arr;
}