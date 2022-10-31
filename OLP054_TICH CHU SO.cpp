#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        if(n < 10)
        {
            cout << n << endl;
            continue;
        }
        string s = "";
        for(int i = 9 ; i > 1 ; i--)
        {
            while(n % i == 0)
            {
                s = to_string(i) + s;
                n /= i;
            }
        }
        if(n > 10) cout << -1 << endl;
        else cout << s << endl;
    }
}
