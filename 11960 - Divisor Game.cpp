#include<bits/stdc++.h>
using namespace std;

#define mx 1000005

int divs[mx+10];
int ans[mx+10];

void sieve()
{
    for(int i=1;i<=mx;i++) divs[i] = 2;
    divs[1] = 1;

    for(int i=2;i<=mx;i++)
    {
        for(int j=2*i;j<=mx;j+=i)
        {
            //cout<<i<<" "<<j<<endl;
            divs[j]++;
        }
    }

    ans[1] = 1;
    for(int i=2;i<=mx;i++)
    {
        if(divs[i]>=divs[ans[i-1]])
        {
            ans[i] = i;
        }

        else
        {
            ans[i] = ans[i-1];
        }
    }
}

int main()
{
    sieve();

    int test, n;

    cin>>test;
    while(test--)
    {
        cin>>n;
        cout<<ans[n]<<endl;
    }
}
