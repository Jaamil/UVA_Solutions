
#include<bits/stdc++.h>
using namespace std;

vector<int>primes;
#define Max 32000

struct st
{
    int no, divs;
};

st ans[10005];

void sieve()
{
    bool isPrime[Max];
    memset(isPrime, true, Max);

    primes.push_back(2);
    for(long long i=3;i<Max;i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<Max;j+=i)
            {
                isPrime[j] = false;
            }

            primes.push_back(i);
        }
    }
}

int countDivisor(int n)
{
    int cDivisor = 1;

    for(int i=0;primes[i]<=n and i<primes.size();i++)
    {
        int cnt = 1;
        while(n%primes[i]==0)
        {
            cnt++;
            n/=primes[i];
        }
        cDivisor*=cnt;
    }

    return cDivisor;
}

int main()
{
    sieve();
    int n;
    int test;
    cin>>test;
    while(test--)
    {
        int a, b;
        cin>>a>>b;
        ans[0].divs = 0;
        int k = 1;
        for(int i=a;i<=b;i++)
        {
            int cDivisor =  countDivisor(i);
            if(cDivisor>ans[k].divs)
            {
                k++;
                ans[k].no = i;
                ans[k].divs = cDivisor;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n",a, b, ans[k].no, ans[k].divs);
    }

}
