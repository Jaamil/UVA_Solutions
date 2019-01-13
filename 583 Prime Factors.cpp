

#include<bits/stdc++.h>
using namespace std;

#define MAX 46340
#define ll long long
vector<int> primes;

void sieve()
{
    bool isPrime[MAX];
    for(int i=0;i<MAX;i++) isPrime[i] = true;

    primes.push_back(2);

     for (long long i = 3; i < MAX; i += 2)
     {
        if (isPrime[i])
        {
            for (long long j = i * i; j < MAX; j += i)
            {
                isPrime[j] = false;
            }

            primes.push_back(i);
        }
     }

}

void primeFactor(int n)
{
    int k = 0;


    for(int i=0;primes[i]*primes[i]<=n and i<primes.size();i++)
    {
        while(n%primes[i]==0)
        {
           // if(k==0) printf(" %d", primes[i]);
            if(k==0) cout<<" "<<primes[i];
            //else printf(" x %d", primes[i]);
            else cout<<" x "<<primes[i];
            n/=primes[i];
            k++;
        }
    }

    if(n>1 and k==0) printf(" %d", n);
    else if(n>1) printf(" x %d", n);
}

int main()
{
    //freopen("583output.txt","w",stdout);
    sieve();

    int n;
    while(cin>>n and n)
    {
        if(n==1)
        {
            printf("1 = \n");
            continue;
        }
        if(n==-1)
        {
            printf("-1 = -1 x \n");
            continue;
        }

        int x = abs(n);
        printf("%d =",n);
        if(n<0) printf(" -1 x");
        primeFactor(x);

        cout<<endl;
    }
}

///sample 2147483648
