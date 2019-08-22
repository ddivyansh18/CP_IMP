#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000001
#define ll long long int
vector<ll> isprime(MAX_SIZE, true);
vector<ll> prime;
vector<ll> SPF(MAX_SIZE);

int primeSeive(int n)
{
isprime[0] = isprime[1] = false;

for(ll i=2; i<n; i++)
{
    if(isprime[i])
    {
        prime.push_back(i);
        SPF[i] = i;
    }


for(ll j=0;j<prime.size() && i*prime[j] < n && prime[j] <= SPF[i]  ; j++)
{
    isprime[i*prime[j]] = false;
    SPF[i*prime[j]] = prime[j];
}

}
}
int main()
{
    int n = 100;

    primeSeive(n);

    for(ll i=0;i<prime.size() && prime[i]<=n; i++)
        cout<<prime[i]<<" ";

    return 0;
}
