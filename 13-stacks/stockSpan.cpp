#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    stack<int> st;
    st.push(-1);
    int answers[100];
    for (int i = 0; i < n; ++i)
    {
        int curNum = arr[i];
        while (st.top() != -1)
        {

            if (arr[st.top()] <= curNum) st.pop();
            else break;
        }
        answers[i] = i - st.top();
        st.push(i);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << answers[i] << " ";
    }
    return 0;
}