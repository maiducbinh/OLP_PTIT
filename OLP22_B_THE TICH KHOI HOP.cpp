#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b ; i++)

using namespace std;
int x1[105], y_1[105], z1[105], x2[105], y2[105], z2[105];
int n;

void nhap()
{
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> x1[i] >> y_1[i] >> z1[i];
        cin >> x2[i] >> y2[i] >> z2[i];
    }
}

void solve()
{
    map<int,int> mX, mY, mZ;
    multiset<int> sX, sY, sZ;
    FOR(i, 1, n)
    {
        sX.insert(x1[i]), sX.insert(x2[i]);
        sY.insert(y_1[i]), sY.insert(y2[i]);
        sZ.insert(z1[i]), sZ.insert(z2[i]);
    }
    long long valX[100005], valY[100005], valZ[100005];
    int cnt = 0;
    for(int i : sX)
    {
        mX[i] = ++cnt;
        valX[cnt] = i;
    }
    cnt = 0;
    for(int i : sY)
    {
        mY[i] = ++cnt;
        valY[cnt] = i;
    }
    cnt = 0;
    for(int i : sZ)
    {
        mZ[i] = ++cnt;
        valZ[cnt] = i;
    }
    int newX1[105], newY1[105], newZ1[105];
    int newX2[105], newY2[105], newZ2[105];
    FOR(i, 1, n)
    {
        newX1[i] = mX[x1[i]];
        newY1[i] = mY[y_1[i]];
        newZ1[i] = mZ[z1[i]];
        newX2[i] = mX[x2[i]];
        newY2[i] = mY[y2[i]];
        newZ2[i] = mZ[z2[i]];
    }
    int minX = 1e9, minY = 1e9, minZ = 1e9;
    int maxX = -1, maxY = -1, maxZ = -1;
    FOR(i, 1, n)
    {
        minX = min(minX, newX1[i]);
        maxX = max(maxX, newX2[i]);
        minY = min(minY, newY1[i]);
        maxY = max(maxY, newY2[i]);
        minZ = min(minZ, newZ1[i]);
        maxZ = max(maxZ, newZ2[i]);
    }
    int xet[205][205][205];
    FOR(i, 1, n)
        FOR(u, newX1[i], newX2[i] - 1)
            FOR(v, newY1[i], newY2[i] - 1)
                FOR(w, newZ1[i], newZ2[i] - 1)
                    xet[u][v][w] = 1;
    long long V = 0;
    FOR(x, minX, maxX)
        FOR(y, minY, maxY)
            FOR(z, minZ, maxZ)
                if(xet[x][y][z])
                    V += (valX[x + 1] - valX[x]) * (valY[y + 1] - valY[y]) * (valZ[z + 1] - valZ[z]);
    cout << V << endl;
}

int main()
{
    nhap();
    solve();
}
