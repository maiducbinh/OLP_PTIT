#include <iostream>
#include <iomanip>

using namespace std;

struct point
{
    double x,y;
};

void area(point a[],int n)
{
    double area = 0;
    for(int i = 1 ; i < n ; i++)
        area += a[i].x * a[i+1].y;
    area += a[n].x * a[1].y;
    for(int i = 2 ; i <= n ; i++)
        area -= a[i].x * a[i-1].y;
    area -= a[1].x * a[n].y;
    cout<<setprecision(3)<<fixed<<abs(area/2)<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        point a[n+1];
        for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
        area(a,n);
    }
}
