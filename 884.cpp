#include <bits/stdc++.h>
using namespace std;

#define maxN 1000001

#define ll long long

bitset<maxN>bs;
vector<int>primes;
int ans[maxN+10];
bool isPrime[maxN+10];

void bitSieve()
{
    bs.set();
    bs[0] = bs[1] = 0;
    primes.push_back(2);
    isPrime[2] = 1;

    for(long long i=3;i<=maxN+1;i+=2)
    {
        if(bs[i])
        {
            for(long long j=i*i;j<=maxN+1;j+=i)
            {
                bs[j] = 0;
            }
            primes.push_back((int)i);
            isPrime[int(i)] = 1;
        }

    }
}

void PreCal() {
    bitSieve();
    ans[1] = 0;
    for (int i=2; i<maxN; i++) {
        ans[i] = ans[i-1];
        int n=i, j=0;
        while (!isPrime[n]) {
            if (n%primes[j]==0) {
                ans[i]++;
                n /= primes[j];
            }
            else j++;
        }
        if (isPrime[n]) ans[i]++;
    }
}

main() {
    int n;
    PreCal();
    while (scanf("%d", &n)!=EOF)
        printf("%d\n", ans[n]);
}
