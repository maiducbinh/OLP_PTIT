#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
ll t[maxn * 4], lazy[maxn * 4], a[maxn];
int n, q;

void built(int id, int l, int r)
{
    if(l == r)
    {
        t[id] = a[l];
        lazy[id] = 0;
        return;
    }
    int mid = (l + r)/2;
    built(id * 2, l, mid);
    built(id * 2 + 1 , mid + 1, r);
    t[id] = max(t[id * 2] , t[id * 2 + 1]);
}

void update(int id , int l , int r , int u , int v , ll x)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v)
    {
        t[id] += x;
        lazy[id] += x;
        return;
    }
    int mid = (l + r)/2;
    update(id * 2, l, mid, u, v, x);
    update(id * 2 + 1 , mid + 1, r, u, v, x);
    t[id] = max(t[id * 2] , t[id * 2 + 1]) + lazy[id];
}

ll get(int id, int l, int r, int u, int v)
{
    if(v < l || r < u) return -1e9;
    if(u <= l && r <= v)
    {
        return t[id];
    }
    int mid = (l + r)/2;
    ll t1 = get(id * 2, l, mid, u, v);
    ll t2 = get(id * 2 + 1, mid + 1, r, u , v);
    return max(t1, t2) + lazy[id];
}

int main()
{
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    built(1, 1, n);
    while(q--)
    {
        ll type , u , v , x;
        cin >> type >> u >> v;
        if(type & 1)
        {
            cout << get(1 , 1 , n , u , v) << endl;
        }
        else
        {
            cin >> x;
            update(1 , 1 , n , u , v , x);
        }
    }
}
