#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// calculates x power y mod m
int power(ll x, ll y, ll m)
{
    ll res = 1;

    x = x%m;

    while(y > 0)
    {
        if(y&1)
            res = (res*x)%m;

        y = y>>1;
        x = (x*x)%m;
    }

    return res;
}
int main()
{
    int x=2;
    int y=100;
    int m=1e9+7;

    cout<<power(x,y,m);
    return 0;
}
