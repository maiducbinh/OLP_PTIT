#include <bits/stdc++.h>
#define fi first
#define se second
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int l = s.size();
        int f[l + 5];
        f[0] = 0;
        s = ' ' + s;
        FOR(i, 1, l)
        {
            f[i] = i;
            if(s[i] == '0')
            {
                f[i] = min(f[i], f[i - 1]);
                if(i >= 2 && s[i - 1] == '1') f[i] = min(f[i], f[i - 2]);
            }
            else
            {
                f[i] = min(f[i], f[i - 1] + 1);
                if(i >= 2 and s[i - 1] == '0') f[i] = min(f[i], f[i - 2]);
            }
        }
        cout << f[l] << endl;
    }
}
