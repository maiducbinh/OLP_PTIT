#include <bits/stdc++.h>
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back

using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int a[maxn], n, q;
vector <int> tree[maxn*4];

vector<int> Merge(vector<int> &a, vector<int> &b)
{
    vector<int> res;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            res.pb(a[i]);
            i++;
        }
        else 
        {
            res.pb(b[j]);
            j++;
        }
    }
    while (i < a.size()) res.pb(a[i++]);
    while (j < b.size()) res.pb(b[j++]);
    return res;
}

void built(int id, int l, int r)
{
    if(l==r) return tree[id].pb(a[l]), void();
    int mid = (l+r)/2;
    built(id*2, l, mid);
    built(id*2+1, mid + 1, r);
    tree[id] = Merge(tree[id*2], tree[id*2+1]);
}

int query(int id, int l, int r, int u, int v, int k)
{
    if(u > r or v < l) return 0;
    if(u <= l && r <= v)
    {
        if(*(tree[id].rbegin()) <= k) return 0;
        return tree[id].end() - upper_bound(tree[id].begin(), tree[id]. end(), k);
    }
    int mid = (l + r)/2;
    return query(id*2, l, mid, u, v, k) + query(id*2+1, mid + 1 , r, u, v, k);
}

int main()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    built(1, 1, n);
    cin >> q;
    while(q--)
    {
        int u, v, k;
        cin >> u >> v >> k;
        cout << query(1, 1, n, u, v, k) << endl;
    }
}