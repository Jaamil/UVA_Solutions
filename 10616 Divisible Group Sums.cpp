#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n, m, d;
int dp[205][105][11];
int arr[10005];

ll solve(int pos, int sum, int cnt)
{
    if(sum%d==0 and cnt==m) return 1;

    if(pos>=n or cnt>m) return 0;

    if(dp[pos][sum][cnt]!=-1) return dp[pos][sum][cnt];

    ll ans = solve(pos+1, (sum+arr[pos])%d, cnt+1) + solve(pos+1, sum, cnt);

    dp[pos][sum][cnt] = ans;

    return ans;
}

int main()
{
    int q;
    int cs = 1;

    while(cin>>n>>q)
    {
        if(n==0 and q==0) break;
        cout<<"SET "<<cs++<<":"<<endl;

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        for(int i=0;i<q;i++)
        {
            memset(dp, -1, sizeof dp);
            cin>>d>>m;
            cout<<"QUERY "<<i+1<<": ";
            cout<<solve(0,0,0)<<endl;
        }

    }

    return 0;
}
