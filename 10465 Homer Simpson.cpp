#include<bits/stdc++.h>
using namespace std;

int n, m, t;
int dp[20005];

int solve(int sum)
{
    if(sum==t)
    {
        return 0;
    }

    if(sum>t) return -10000;

    if(dp[sum]!=-1) return dp[sum];

    int ans = 1 + max(solve(n+sum), solve(m+sum));

    return dp[sum] = ans;
}

int solve1(int sum, int ex)
{
    if(sum>t)
    {
        return sum - ex;
    }

    if(dp[sum]!=-1) return dp[sum];

    int ans = max(solve1(n+sum, n), solve1(m+sum, m));

    return dp[sum] = ans;
}

int main()
{
    while(cin>>n>>m>>t)
    {
        for(int i=0;i<20000;i++) dp[i] = -1;

        if(solve(0)<=0)
        {
            int prevT = t;

            for(int i=0;i<20000;i++) dp[i] = -1;

            t = solve1(0, 0);

            for(int i=0;i<20000;i++) dp[i] = -1;

            cout<<solve(0)<<" "<<prevT - t<<endl;
        }

        else
            cout<<solve(0)<<endl;
    }

    return 0;
}
