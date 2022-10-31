#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;

int n , m;
int parent[maxn] , sz[maxn];

int findPar(int u)
{
    if(u == parent[u]) return u;
    return parent[u] = findPar(parent[u]);
}

void Union(int a , int b)
{
    a = findPar(a);
    b = findPar(b);
    if(a != b)//chi Union khi thuoc 2 tap khac nhau
    {
        if(sz[a] < sz[b]) swap(a , b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1 ; i <= n ; i++)
            parent[i] = i, sz[i] = 1;
        while(m--)
        {
            int x , y;
            cin >> x >> y;
            Union(x , y);
        }
        int Max = 0;
        for(int i = 1 ; i <= n ; i++)
            Max = max(Max , sz[parent[i]]);
        cout << Max << endl;
    }
}
