#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<int>coins;
int n;
ll dp[30][10005];

ll go(int pos, int sum)
{
    if(sum==n)
        return 1;

    if(sum>n or pos>=coins.size()) return 0;

    if(dp[pos][sum]!=-1) return dp[pos][sum];

    ll ans;

    ans = go(pos, sum+coins[pos]) + go(pos+1, sum);

    dp[pos][sum] = ans;

    return ans;
}

int main()
{
    for(int i=1;i<22;i++)
    {
        coins.push_back(pow(i, 3));
    }


    while(cin>>n){
        memset(dp, -1, sizeof dp);
        cout<<go(0, 0)<<endl;
    }

    return 0;
}
