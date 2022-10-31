#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

struct Matran
{
    ll f[2][2];
    Matran operator*(Matran b)
    {
        Matran res;
        for(int i = 0 ; i < 2 ; i++)
        {
            for(int j = 0 ; j < 2 ; j++)
            {
                res.f[i][j] = 0;
                for(int k = 0 ; k < 2 ; k++)
                {
                    res.f[i][j] += f[i][k] * b.f[k][j];
                    res.f[i][j] %= Mod;
                }
            }
        }
        return res;
    }
};

Matran powMod(Matran a , ll k)
{
    if(k == 1) return a;
    Matran tmp = powMod(a , k / 2);
    if(k & 1)
        return tmp * tmp * a;
    else return tmp * tmp;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        if(n == 0)
        {
            cout << 1 << endl;
            continue;
        }
        Matran mx;
        mx.f[0][0] = mx.f[0][1] = mx.f[1][0] = 1;
        mx.f[1][1] = 0;
        mx = powMod(mx , n);
        cout << mx.f[0][0] << endl;
    }
}
