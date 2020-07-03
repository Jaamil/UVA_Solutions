#include<bits/stdc++.h>
using namespace std;

int n, amount, newAmount;
int dp[105][20005];
vector<int>coins;

int minAmount(int pos, int sum)
{
    if(sum>=amount) return sum;

    if(pos>=coins.size()) return 10000000;

    if(dp[pos][sum]!=-1) return dp[pos][sum];

    int ans;

    ans = min(minAmount(pos+1, sum+coins[pos]), minAmount(pos+1, sum));

    dp[pos][sum] = ans;

    return ans;
}

int minCoins(int pos, int sum)
{
    if(sum==newAmount)
    {
        return 0;
    }

    if(pos>=coins.size() or sum>newAmount)
    {
        return 10000000;
    }

    if(dp[pos][sum]!=-1) return dp[pos][sum];

    int ans;

    ans = min(1+minCoins(pos+1, sum+coins[pos]), minCoins(pos+1, sum));

    dp[pos][sum] = ans;

    return ans;
}

int main()
{
    //freopen("11517.txt", "w", stdout);
    int T, x;

    cin>>T;
    while(T--){

        memset(dp, -1, sizeof dp);
        cin>>amount;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;

            coins.push_back(x);
        }

        newAmount = minAmount(0, 0);

        memset(dp, -1, sizeof dp);

        cout<<newAmount<<" "<<minCoins(0, 0)<<endl;

        coins.clear();
    }

    return 0;
}
