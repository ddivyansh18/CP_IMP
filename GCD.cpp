#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd(ll a, ll b)
{
    while(b)
    {
        a = a % b;
        swap(a,b);
    }

    return a;
}
int main()
{
    cout<<gcd(256,1024);
    //Prints 256
}
