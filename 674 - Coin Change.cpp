#include<bits/stdc++.h>
using namespace std;

int dp[100][10000];

int main()
{
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

        cout<<dp[5][amount]<<endl;
    }
}
