#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

struct canh
{
    int x, y, w;
};

const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;
int n, m, parent[maxn], sz[maxn];
vector<canh> dscanh;

int findPar(int u)
{
    if(u == parent[u]) return u;
    return parent[u] = findPar(parent[u]);
}

bool Union(int a, int b)
{
    a = findPar(a);
    b = findPar(b);
    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    parent[b] = a;
    return 1;
}

void nhap()
{
    cin >> n >> m;
    FOR(i, 1, n)
    {
        parent[i] = i;
        sz[i] = 1;
    }
    dscanh.clear();
    FOR(i, 1, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dscanh.pb({a, b, c});
    }
}

void Kruskal()
{
    sort(dscanh.begin(), dscanh.end(), [](canh a, canh b)->bool{
        return a.w < b.w;
    });
    ll ans = 0;
    vector<canh> tree;
    FOR(i, 0, m - 1)
    {
        if(tree.size() == n - 1) break;
        if(Union(dscanh[i].x, dscanh[i].y))
        {
            tree.pb(dscanh[i]);
            ans += dscanh[i].w;
        }
    }
    cout << ans << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        nhap(); 
        Kruskal();       
    }
}