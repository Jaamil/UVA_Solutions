
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 10000007
bitset<MAX>bs;
vector<int>primes;

void bitSieve()
{
    bs.set();
    bs[0] = bs[1] = 0;
    primes.push_back(2);

    for(long long i=3;i<=MAX+1;i+=2)
    {
        if(bs[i])
        {
            for(long long j=i*i;j<=MAX+1;j+=i)
            {
                bs[j] = 0;
            }
            primes.push_back((int)i);
        }

    }
}

void primeFactor(ll n)
{

    for(int i=0;primes[i]*primes[i]<=n and i<primes.size();i++)
    {
        while(n%primes[i]==0)
        {

            cout<<"    "<<primes[i]<<endl;
            n/=primes[i];

        }
    }

    if(n>1) cout<<"    "<<n<<endl;
}

int main()
{
    //freopen("10392.txt","w",stdout);
    bitSieve();

    ll n;

    while(cin>>n)
    {
        if(n==-1) break;

      primeFactor(n);

        cout<<endl;
    }
}

