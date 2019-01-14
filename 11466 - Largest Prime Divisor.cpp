

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 1000007
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
    ll lpd = 0;
    int cnt = 0;
    for(int i=0;primes[i]*primes[i]<=n and i<primes.size();i++)
    {
          if(n%primes[i]==0)  cnt++;
        while(n%primes[i]==0)
        {

          //  cout<<primes[i]<<" ";
            lpd = primes[i];
            n/=primes[i];
        }
    }

    if(n>1 and lpd==0)
    {
        //cout<<-1<<endl;
        printf("-1\n");
    }

    else if(cnt==1 and n==lpd)
    {
        //cout<<-1<<endl;
        printf("-1\n");
    }
    else if(cnt==1 and n<=1)
    {
        //cout<<-1<<endl;
        printf("-1\n");

    }

    else{
        //cout<<max(n,lpd)<<endl;
        printf("%lld\n",max(n,lpd));
    }
}

int main()
{
    //freopen("10392.txt","w",stdout);
    bitSieve();

    ll n;

    while(scanf("%lld",&n) and n)
    {
        if(n<0) n*=-1;
        if(n==1)
        {
            //cout<<-1<<endl;
            printf("-1\n");
            continue;
        }

      primeFactor(n);

        //cout<<endl;
    }
}


