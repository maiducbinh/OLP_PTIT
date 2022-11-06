#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
ll a[maxn*2], stree[8*maxn], ptree[8*maxn];

void built(int id, int l, int r)
{
    if(l == r)
    {
        stree[id] = a[l];
        ptree[id] = l;
        return;
    }
    int mid = (l+r)/2;
    built(id*2, l, mid);
    built(id*2+1, mid + 1, r);
    stree[id] = stree[id*2] + stree[id*2+1];
    if(a[ptree[id*2]] <= a[ptree[id*2+1]]) ptree[id] = ptree[id*2];
    else ptree[id] = ptree[id*2+1];
}

int getPos(int id, int l, int r, int u, int v)
{
    if(l > r or u > r or v < l) return 0;
    if(u <= l && r <= v) return ptree[id];
    int mid = (l+r)/2;
    int p1 = getPos(id*2, l, mid, u, v);
    int p2 = getPos(id*2+1, mid+1, r, u, v);
    if(a[p1] <= a[p2]) return p1;
    else return p2;
}

void updatePos(int id, int l, int r, int u, int val)
{
    if(l > r or u > r or u < l) return;
    if(u == l && r == l)
    { 
        a[ptree[id]] = val;
        return;
    }
    int mid = (l+r)/2;
    if(u <= mid) updatePos(id*2, l, mid, u, val);
    else updatePos(id*2+1, mid+1, r, u, val);
    if(a[ptree[id*2]] <= a[ptree[id*2+1]]) ptree[id] = ptree[id*2];
    else ptree[id] = ptree[id*2+1];
}

void updateSum(int id, int l, int r, int u, int val)
{
    if(l > r or u > r or u < l) return;
    if(u == l && r == l)
    { 
        stree[id] = val;
        a[l] = val;
        return;
    }
    int mid = (l+r)/2;
    if(u <= mid) updateSum(id*2, l, mid, u, val);
    else updateSum(id*2+1, mid+1, r, u, val);
    stree[id] = stree[id*2] + stree[id*2+1];
    // if(a[ptree[id*2]] <= a[ptree[id*2+1]]) ptree[id] = ptree[id*2];
    // else ptree[id] = ptree[id*2+1];
}

ll query(int id, int l, int r, int u, int v)
{
    if(l > r or u > r or v < l) return 0;
    if(u <= l and r <= v)
    {
        return stree[id];
    }
    int mid = (l+r)/2;
    ll q1 = query(id*2, l, mid, u, v);
    ll q2 = query(id*2+1, mid+1, r, u, v);
    return q1 + q2;
}

int main()
{
    int n, q;
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    ll m = 2*n;
    built(1, 1, m);
    a[0] = 1e18;
    // truy van 1: delta += (n - d) % n
    // new pos u = u + delta
    // new pos v = v + delta
    int delta = 0;
    while(q--)
    {
        ll type, s, t, p;
        cin >> type >> s;
        if(type == 1)
        {
            s %= n;
            delta += (n - s);
            delta %= n;
            //delta += n - (s % n);
        }
        else if(type == 2)
        {
            cin >> t >> p;
            s = s + delta;
            t = t + delta;
            int pos = getPos(1, 1, m, s, t);
            // cap nhat mot nuas
            updatePos(1, 1, m, pos, p);
            updateSum(1, 1, m, pos, p);
            // cap nhat nua con lai
            if(pos <= n) pos += n;
            else pos -= n;
            updatePos(1, 1, m, pos, p);
            updateSum(1, 1, m, pos, p);
        }
        else
        {
            cin >> t;
            s += delta;
            t += delta;
            cout << query(1, 1, m, s, t) << endl;
        }
    }
}