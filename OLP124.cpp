#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const ll mod = 1e12 + 39;
const int maxn = 1e6 + 5;
ll p[maxn + 5], Hash[maxn + 5];
ll base = 31, n, m;

// ll getHash(int l, int r)
// {
//     return ((hashA[r]-hashA[l-1]*p[r-l+1]+1ll*mod*mod)%mod);
// }

bool check(string t)
{
    int len = t.size();
    ll h = 0;
    t = " " + t;
    FOR(i, 1, len) h = (h*base+t[i]-'a'+1)%mod;
    FOR(i, 1, len)
    {
        for(int j = 'a'; j <= 'c'; j++)
            if(t[i] != j)
            {
                ll thu = (h+(j-t[i])*p[len-i]%mod+mod)%mod;
                auto j = lower_bound(Hash + 1, Hash + n + 1, thu);
                if(*j == thu) return 1;
            }
    }
    return 0;
}
void init()
{
    p[0] = 1;
    FOR(i, 1, maxn - 1) p[i] = (p[i-1]*base)%mod;
}
int main()
{
    cin >> n >> m;
    init();
    FOR(i, 1, n) 
    {
        string s;
        cin >> s;     
        ll h = 0;
        FOR(i, 0, s.size() - 1) h = (h*base+s[i]-'a'+1)%mod;  
        Hash[i] = h; 
    }
    sort(Hash + 1, Hash + n + 1);
    FOR(i, 1, m) 
    {
        string t;
        cin >> t;
        cout << (check(t) ? "YES\n" : "NO\n");
    }
}// mod qua be