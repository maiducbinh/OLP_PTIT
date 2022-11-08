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
int t[1000005];

int main()
{
    string a, b;
    cin >> a >> b;
    string s = b + '*' + a;
    int len = s.size();
    s = " " + s;
    // t[i] do dai xau dai nhat ket thuc tai i khop voi xau dau
    // dat t[i - 1] = k
    // neu s[i] = s[i - 1] thi t[i] = t[i - 1] + 1
    // else tim k' co the thoa man lon nhat < k (k' tot nhat = t[k])
    // neu s[i] = s[k' + 1] => t[i] = k' + 1
    t[1] = 0;
    int k = 0;
    FOR(i, 2, len)
    {
        while(k > 0 && s[k + 1] != s[i]) k = t[k];
        if(s[k + 1] == s[i]) k++;
        t[i] = k;
    }
    FOR(i, b.size() + 1, len) 
        if(t[i] == b.size()) cout << i - 2*t[i] << " ";
}