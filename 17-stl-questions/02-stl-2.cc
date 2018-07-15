// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
// merge sorted arrays
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v1, v2;
    int n1, n2; cin >> n1 >> n2;

    for (int i = 0; i < n1; ++i) {
        int x; cin >> x;
        v1.push_back(x);
    }

    v2.resize(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> v2[i];
    }

    vector<int> ans;
    // ans.resize(n1 + n2);
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(ans));

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }

}