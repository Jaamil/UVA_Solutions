#include<bits/stdc++.h>
using namespace std;

long long dp[100][50000];

int main()
{
    //freopen("357o.txt", "w", stdout);
    int amount;
    int coin[] = {0,1,5,10,25,50};
    while(cin>>amount)
    {
        for(int i=1;i<=5;i++) dp[i][0] = 1;
        for(int i=1;i<=5;i++)
        {

            for(int j=1;j<=amount;j++)
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

        if(dp[5][amount]!=1) printf("There are %lld ways to produce %d cents change.\n",dp[5][amount],amount);

        else printf("There is only 1 way to produce %d cents change.\n",amount);
    }
}

