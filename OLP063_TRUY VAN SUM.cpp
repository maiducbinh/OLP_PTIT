#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;

ll a[maxn], tree[maxn*4], lazy[maxn*4] = {0};

void built(ll id, ll l, ll r)
{
    if(l == r)
    {
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    built(id*2, l, mid);
    built(id*2+1, mid + 1, r);
    tree[id] = tree[id*2] + tree[id*2+1];
}

void update(ll id, ll l, ll r, ll u, ll v, ll val)
{
    if(lazy[id] != 0)
    {
        tree[id] += (r - l + 1) * lazy[id];
        if(l != r)
        {
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }
        lazy[id] = 0;
    }
    if(l > r || v < l || u > r)
        return;
    if(u <= l && r <= v)
    {
        tree[id] += (r - l + 1) * val;
        if(l != r)
        {
            lazy[id*2] += val;
            lazy[id*2+1] += val;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid + 1, r, u, v, val);
    tree[id] = tree[id*2] + tree[id*2+1];
}

ll query(ll id, ll l, ll r, ll u, ll v)
{
    if(l > r or v < l or u > r)
        return 0;
    if(lazy[id] != 0)
    {
        tree[id] += (r - l + 1) * lazy[id];
        if(l != r)
        {
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }
        lazy[id] = 0;
    }
    if(u <= l && r <= v)
        return tree[id];
    int mid = (l + r) / 2;
    ll q1 = query(id*2, l, mid, u, v);
    ll q2 = query(id*2+1, mid + 1, r, u, v);
    return (q1 + q2);
}

int main()
{
    ll n, q;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    built(1, 1, n);
    while(q--)
    {
        ll type, u, v, x;
        cin >> type >> u >> v;
        if(type & 1)
        {
            cout << query(1, 1, n, u, v) << endl;
        }
        else
        {
            cin >> x;
            update(1, 1, n, u, v, x);
        }
    }
}
