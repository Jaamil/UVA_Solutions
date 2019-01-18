#include<bits/stdc++.h>
using namespace std;

int dp[1001][10001];
int value[1001], weight[1001];

long long ans;

int main()
{
    int n,m,ppl, test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        ans = 0;
        for(int i=0;i<=n;i++) dp[i][0] = 0;

        for(int i=1;i<=n;i++)
        {
            cin>>value[i];
            cin>>weight[i];
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=30;j++)
            {
                if(weight[i]<=j)
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
                }

                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        cin>>ppl;
        for(int i=0;i<ppl;i++)
        {
            int x;
            cin>>x;
            ans+=dp[n][x];
        }

        cout<<ans<<endl;
    }

}
