#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int tree[2*N];

void build(int arr[])
{
    for(int i=0; i<n; i++)
        tree[n+i] = arr[i];

    for(int i=n-1; i>0; i--)
        tree[i] = tree[i<<1] + tree[i<<1|1];
}

void update(int in, int value)
{
    tree[in+n] = value;
    in = in + n;

    for(int i=in; i>1; i>>=1)
        tree[i>>1] = tree[i] + tree[i^1];
}

int query(int l, int r)
{
    int res = 0;

    for(l+=n, r+=n; l<r; l>>=1,r>>=1)
    {
        if(l&1)
            res += tree[l++];
        if(r&1)
            res += tree[--r];
    }

    return res;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    n = sizeof(a)/sizeof(a[0]);
    build(a);
    cout<<query(0,n)<<"\n";
    //Prints 55
    update(0,10);
    //Update arr[0] = 10;
    cout<<query(0,n)<<"\n";
    //Prints 64
    return 0;
}
