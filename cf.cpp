// Created by Mai Duc Binh

#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
 
// Defines
#define tc()               \
    int T;                 \
    cin>>T;                \
    while(T--)
#define yes     cout<<"YES\n";
#define no      cout<<"NO\n";
#define endl "\n"
#define Sz size()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define __int128 lll
#define ll long long
#define ld long double
#define vt(C) vector<C>
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define reset(C) memset(C,0,sizeof(C))
#define rev(C) reverse(begin(C), end(C))
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int dx[]={1, 0, -1, 0, 1, 1, -1, -1};
int dy[]={0, 1, 0, -1, 1, -1, -1, 1};
 
// Some useful std functions
template<typename T> T pmax(T &a) {return max_element(a.begin(), a.end()) - a.begin();}
template<typename T> T pmin(T &a) {return min_element(a.begin(), a.end()) - a.begin();}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};// cin >> whole vector
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;}; // cout << whole vector
template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.ff << ' ' << x.ss;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.ff >> x.ss;}
template<typename T> void lower(T &a) {for(int i=0; i<(sizeof(a)/sizeof(a[0])); i++) a[i] = tolower(a[i]);}
template<typename T> void upper(T &a) {for(int i=0; i<(sizeof(a)/sizeof(a[0])); i++) a[i] = toupper(a[i]);}
template<typename T> using matrix = vector<vector<T>>;
template<typename T> using rubik = vector<vector<vector<T>>>;// rubik<int> a: instead of vector<vector<vector<int> > > a;
 
// Main Functions

struct dia
{
    ll a, b, h;
};

bool cmp(dia x, dia y)
{
    if(x.b != y.b) return x.b > y.b;
    else return x.a >= y.a;
}

int main()
{
    faster();
    int n; cin >> n;
    vector<dia> v;
    FOR(i, 1, n)
    {
        ll x, y, z; cin >> x >> y >> z;
        v.pb({x, y, z});
    }
    sort(all(v), cmp);
    // for(dia i: v) cout << i.a << " " << i.b << " " << i.h << endl;
    stack<pair<dia, ll>> st;
    ll ans = 0;
    F(i, 0, n)
    {
        while(!st.empty() && v[i].b <= st.top().ff.a)
        {
            st.pop();
        }
        if(!st.empty())
        {
            ll h = st.top().ss + v[i].h;
            st.push({v[i], h});
        }
        else st.push({v[i], v[i].h});
        ans = max(ans, st.top().ss);
    }
    cout << ans;
}