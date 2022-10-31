#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<pair<char,int>> st;
    int ans = 0, tmp = 0;
    st.push({')', 0});
    for(char i : s)
    {
        if((i == ')' &&  st.top().first == '(') || (i == ']' && st.top().first == '['))
        {
            st.pop();
            ans = max(ans , tmp - st.top().second);
        }
        else
        {
            if(i == '[') tmp++;
            st.push({i, tmp});
        }
    }
    cout << ans;
}
