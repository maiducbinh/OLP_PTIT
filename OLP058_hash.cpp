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
ll p[maxn], hashA[maxn], hashB = 0;
ll base = 31;

ll getHash(int l, int r)
{
    return ((hashA[r]-hashA[l-1]*p[r-l+1]+1ll*mod*mod)%mod);
}
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = " " + a, b = " " + b;
    FOR(i, 1, m) hashB = (hashB*base+b[i]-'a'+1)%mod;
    hashA[0] = 0;
    FOR(i, 1, n) hashA[i] =(hashA[i-1]*base+a[i]-'a'+1)%mod;
    p[0] = 1;
    FOR(i, 1, n) p[i] = (p[i-1]*base)%mod;
    for(int i = 1; i+m-1<=n; i++)
        if(hashB == getHash(i, i+m-1)) cout << i << " ";
}