#include<bits/stdc++.h>
using namespace std;

int dp[105][60001];

int main()
{
    //freopen("562output.txt","w",stdout);
    int test, nCoin;
    int coin[1001];
    cin>>test;
    for(int t=0;t<test;t++)
    {
        int sum = 0;

        cin>>nCoin;
        for(int i=1;i<=nCoin;i++)
        {
            cin>>coin[i];
        }

        for(int i=1;i<=nCoin;i++)
        {
            sum+=coin[i];
        }

        int x;
        if(sum&1) {
            x = sum/2 + 1;
        }

        else x = sum/2;

        for(int i=0;i<=nCoin;i++)
        {
            for(int j=0;j<=x;j++)
            {
                dp[i][j] = 0;
            }

        }
        //for(int i=0;i<=x;i++) dp[0][i] = 0;

        for(int i=1;i<=nCoin;i++)
        {
            for(int j=0;j<=x;j++)
            {
                if(coin[i]<=j)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-coin[i]]+coin[i]);
                else
                    dp[i][j] = dp[i-1][j];
            }

        }

        //cout<<x<<endl;
        //cout<<dp[nCoin][x]<<endl;
        cout<<abs(dp[nCoin][x] - (sum-dp[nCoin][x]))<<endl;
    }
}
