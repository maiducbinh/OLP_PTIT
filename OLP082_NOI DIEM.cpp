#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
using ld = long double;
int parent[105], sz[105], n;

struct canh
{
    int x , y;
    ld w;
};
vector<canh> adj;

int findPar(int u)
{
    if(parent[u] == u) return u;
    return parent[u] = findPar(parent[u]);
}

bool Union(int a , int b)
{
    a = findPar(a);
    b = findPar(b);
    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a , b);
    parent[b] = a;
    sz[a] += sz[b];
    return 1;
}

void Kruskal()
{
    sort(adj.begin() , adj.end() , [](canh a, canh b)->bool{
         return a.w < b.w;
    });
    ld ans = 0;
    vector<canh> tree;
    for(int i = 0 ; i < adj.size() ; i++)
    {
        if(tree.size() == n - 1) break;
        if(Union(adj[i].x , adj[i].y))
        {
            tree.push_back(adj[i]);
            ans += adj[i].w;
        }
    }
    cout << setprecision(6) << fixed << ans << endl;
}

ld distance(pair<ld,ld> x , pair<ld,ld> y)
{
    return sqrt((x.fi - y.fi) * (x.fi - y.fi) + (x.se - y.se) * (x.se - y.se));
}

void nhap()
{
    cin >> n;
    pair<ld,ld> a[n + 5];
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i].first >> a[i].second;
        parent[i] = i;
        sz[i] = 1;
    }
    adj.clear();
    for(int i = 1 ; i <= n ; i++)
        for(int j = i + 1 ; j <= n ; j++)
        {
            ld w = distance(a[i] , a[j]);
            adj.push_back({i , j , w});
        }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        nhap();
        Kruskal();
    }
}
