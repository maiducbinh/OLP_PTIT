#include <bits/stdc++.h>
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
ll n, m;
pair<ll,ll> a[1005];

bool check(ll x)
{
    ll res = 0;
    FOR(i, 0, n - 1)
    {
        ll off = x/(a[i].se + 1);
        res += a[i].fi*(x - off);
        if(res >= m) return 1;
    }
    return 0;
    //return res >= m;
}

int main()
{
    n, m;
    cin >> n >> m;
    FOR(i, 0, n - 1) cin >> a[i].fi >> a[i].se;
    ll l = 1, r = m, ans = m;
    while(l <= r)
    {
        ll mid = (l+r)/2;
        if(check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
