#include<bits/stdc++.h>
using namespace std;

int dp[50][500];
int n, m;
vector<int>v[105];

int solve(int pos, int sum)
{
    if(pos==n)
    {
        if(sum>m)
        {
            return 0;
        }

        return sum;
    }

    if(pos>n or sum>m) return 0;

    if(dp[pos][sum]!=-1) return dp[pos][sum];

    int ans = 0;

    for(int i=0;i<v[pos].size();i++)
    {
        ans = max(solve(pos+1, sum+v[pos][i]), ans);
    }

    return dp[pos][sum] = ans;
}

int main()
{
    //freopen("11450.txt", "w", stdout);
    int T, temp, x;

    cin>>T;
    while(T--)
    {
        memset(dp, -1, sizeof dp);
        cin>>m>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            for(int j=0;j<x;j++)
            {
                cin>>temp;
                v[i].push_back(temp);
            }
        }

        if(solve(0, 0))
            cout<<solve(0,0)<<endl;

        else
            cout<<"no solution"<<endl;

        for(int i=0;i<n;i++) v[i].clear();
    }

    return 0;
}
