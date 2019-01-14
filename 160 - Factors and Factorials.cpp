#include<bits/stdc++.h>
using namespace std;

int p[1001];
bool prime[1001];

void sieve()
{
    memset(prime , true, sizeof(prime));

    for(int i=2;i*i<=100;i++)
    {
        if(prime[i]==true)
        {

            for(int j=i*2;j<=100;j=j+i)
            {
                prime[j] = false;
            }
        }
    }

    int j = 0;
    for(int i=2;i<=100;i++)
    {
        if(prime[i]) p[j++] = i;

    }
}


int main()
{
   // freopen("160o.txt","w", stdout);

    int n, arr[1000], ans[1001];
    sieve();
    while(cin>>n)
    {
        if(n==0) break;
        int j = 0;
        for(int i=0;i<=n;i++)
        {
            ans[i] = 0;
        }

        for(int i=2;i<=n;i++)
        {
            arr[j++] = i;
        }


        for(int j=0;j<n-1;j++)
        {

            while(arr[j]%2==0 and arr[j]!=0)
            {
                ans[2]++;
                arr[j]/=2;
            }

            for(int k=3;k<=sqrt(arr[j]);k=k+2)
            {
                while(arr[j]%k==0 and arr[j]!=0)
                {
                    ans[k]++;
                    arr[j]/=k;
                }
            }

            if(arr[j]>2)
            {
                ans[arr[j]]++;

            }


        }
        cout.width(3);
        cout << right << n ;
        printf("! =");

        int k = 0;
        for(int i=2;i<=n;i++)
        {
            if(prime[i] )
            {
                ++k;
                if(k==16)
                {
                    cout<<endl;
                  cout.width(9);
                  cout << right << ans[i];
                  continue;
                }
                cout.width(3);
                cout << right << ans[i];
            }
        }

        cout<<endl;

    }
}

