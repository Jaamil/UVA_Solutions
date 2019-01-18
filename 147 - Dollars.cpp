
#include<bits/stdc++.h>
using namespace std;

long long dp[100][50000];

int main()
{
    //freopen("147o.txt", "w", stdout);
    int a;
    double n, x;
    int coin[] = {0,5,10,20,50,100,200,500,1000,2000,5000,10000};
    while(cin>>n)
    {
        if(n==0) break;
        x = round(n*100);
        a = (int)(x);

        for(int i=1;i<=11;i++) dp[i][0] = 1;
        for(int i=1;i<=11;i++)
        {

            for(int j=1;j<=a;j++)
            {
                if(j>=coin[i])
                {
                    dp[i][j] = dp[i-1][j]+dp[i][j-coin[i]];
                }

                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        printf("%6.2f",n);

       printf("%17lld\n",dp[11][a]);

    }
}

