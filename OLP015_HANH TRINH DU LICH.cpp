#include <bits/stdc++.h>
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define bit(n, i) ((n>>i)&1)
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
ll n, c[15][15], f[1<<16][16];
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        memset(f, 0 , sizeof(f));
        cin >> n;
        FOR(i, 0, n - 1)
            FOR(j , 0, n - 1)
                cin >> c[i][j];
        FOR(mask, 1, (1<<n) - 1)
        {
            if(__builtin_popcount(mask) == 1) continue;// trang thai chi co 1 so 1 hay dang la diem bat dau
            FOR(i, 0, n - 1)
            {
                if(bit(mask, i))
                {
                    f[mask][i] = 1e9;
                    int pre_mask = mask - (1<<i);// tat bit 1 tai vi tri i
                    FOR(j, 0, n - 1)
                    {
                        if(bit(pre_mask, j))
                        {
                            f[mask][i] = min(f[mask][i], f[pre_mask][j] + c[j][i]);
                        }
                    }
                }
            }
        }
        ll ans = 1e9;
        FOR(i, 0, n - 1)
            ans = min(ans, f[(1<<n)-1][i]);
        cout << ans << endl;
    }
}