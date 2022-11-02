#include <bits/stdc++.h>
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define bit(n, i) ((n>>i)&1)

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
int d[16];
ll a[4][100005];
ll f[100005][16];

int main()
{
    FOR(i, 0, 15)
    {
        bool bl = 1;
        FOR(j, 0, 2)
            if(bit(i, j) && bit(i, j + 1)) bl = 0;
        d[i] = bl;
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll ans = -1e9, res = -1e9;
        int n;
        cin >> n;
        FOR(i, 0, 3)
            FOR(j, 1, n) cin >> a[i][j], res = max(res, a[i][j]);
        FOR(i, 1, n)
        {
            FOR(mask, 0, 15)
            {
                f[i][mask] = -1e9;
                if(d[mask])
                {
                    ll sum = 0;
                    FOR(j, 0, 3)
                        if(bit(mask, j)) sum += a[j][i];
                    //cout << sum << " ";
                    FOR(pre_mask, 0, 15)
                    {
                        if(d[pre_mask] && ((pre_mask & mask) == 0))
                            f[i][mask] = max(f[i][mask], f[i - 1][pre_mask] + sum);
                    }
                }
                ans = max(ans, f[i][mask]);
            }
        }
        if(ans) cout << ans << endl;
        else cout << res << endl;
    }
}
