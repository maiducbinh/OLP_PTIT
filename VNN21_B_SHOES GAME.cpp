#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll sum = 0;
    int n , l;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        sum += x;
    }
    cout << -sum;
}
