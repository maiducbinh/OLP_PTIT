#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 5;
int parent[maxn] , sz[maxn];

int findPar(int u)
{
    if(u == parent[u]) return u;
    else return parent[u] = findPar(parent[u]);
}

bool checkUnion(int a, int b)
{
    a = findPar(a);
    b = findPar(b);
    if(a == b) return 1;
    return 0;
}

void Union(int a , int b)
{
    a = findPar(a);
    b = findPar(b);
    if(sz[a] < sz[b]) swap(a , b);
    parent[b] = a;
    sz[a] += sz[b];
}

void init()
{
    for(int i = 0 ; i < maxn ; i++)
        parent[i] = i, sz[i] = 1;
}

int main()
{
    init();
    int q;
    cin >> q;
    while(q--)
    {
        int x , y , z;
        cin >> x >> y >> z;
        if(z == 2)
        {
            if(checkUnion(x , y)) cout << 1;
            else cout << 0;
            cout << endl;
        }
        else
        {
            Union(x , y);
        }
    }
}
