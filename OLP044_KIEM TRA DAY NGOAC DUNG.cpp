#include <bits/stdc++.h>

using namespace std;

bool check(string s)
{
    stack<char> st;
    for(char i : s)
    {
        if(i == '(' || i == '[' || i == '{') st.push(i);
        else
        {
            if(st.empty())
            {
                return false;
            }
            else
            {
                if(i == ')')
                {
                    if(st.top() == '(') st.pop();
                    else return 0;
                }
                else if(i == ']')
                {
                    if(st.top() == '[') st.pop();
                    else return 0;
                }
                else if(i == '}')
                {
                    if(st.top() == '{') st.pop();
                    else return 0;
                }
            }
        }
    }
    return st.empty();
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        cout << (check(s) ? "YES" : "NO") << endl;
    }
}
