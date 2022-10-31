#include <bits/stdc++.h>

using namespace std;
int n , s , t , u , v;
char a[105][105];

void nhap()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> a[i][j];
    cin >> s >> t >> u >> v;
}

void BFS()
{
    int d[n + 5][n + 5] , visited[n + 5][n + 5];
    memset(visited , 0 , sizeof(visited));
    queue<pair<int,int>> q;
    q.push({s , t});
    d[s][t] = 0;
    visited[s][t] = 1;

    while(!q.empty())
    {
        pair<int,int> tmp = q.front();
        int x = tmp.first, y = tmp.second;
        q.pop();
        if(x == u && y == v)
        {
            cout << d[u][v];
            return;
        }
        int t1 = x + 1;
        while(t1 < n && a[t1][y] == '.' && !visited[t1][y])
        {
            d[t1][y] = d[x][y] + 1;
            visited[t1][y] = 1;
            q.push({t1 , y});
            t1++;
        }
        t1 = x - 1;
        while(t1 >= 0 && a[t1][y] == '.' && !visited[t1][y])
        {
            d[t1][y] = d[x][y] + 1;
            q.push({t1 , y});
            visited[t1][y] = 1;
            t1--;
        }
        int t2 = y + 1;
        while(t2 < n && a[x][t2] == '.' && !visited[x][t2])
        {
            d[x][t2] = d[x][y] + 1;
            visited[x][t2] = 1;
            q.push({x , t2});
            t2++;
        }
        t2 = y - 1;
        while(t2 >= 0 && a[x][t2] == '.' && !visited[x][t2])
        {
            d[x][t2] = d[x][y] + 1;
            q.push({x , t2});
            visited[x][t2] = 1;
            t2--;
        }
    }
}

int main()
{
    nhap();
    BFS();
}
