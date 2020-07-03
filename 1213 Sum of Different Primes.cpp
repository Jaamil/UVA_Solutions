
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX 10007
bitset<MAX>bs;
vector<int>primes;
ll n, k, allmask;
int dp[2000][15][200];

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

ll primeSum(ll sum, int cnt, int pos)
{
    if(sum==n and cnt==k) return 1;

    if(cnt==k or sum>n or primes[pos]>n) return 0;

    if(dp[sum][cnt][pos]!=-1) return dp[sum][cnt][pos];

    ll ans = 0;

    ans+= primeSum(sum, cnt, pos+1);

    ans+= primeSum(sum+primes[pos], cnt+1, pos+1);


    dp[sum][cnt][pos] = ans;

    return ans;
}

int main()
{
    //freopen("1213.txt","w",stdout);
    bitSieve();


    while(cin>>n>>k and n)
    {
        memset(dp, -1, sizeof dp);

        cout<<primeSum(0, 0, 0)<<endl;
    }
}


