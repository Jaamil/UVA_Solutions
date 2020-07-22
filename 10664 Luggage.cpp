#include<bits/stdc++.h>
using namespace std;

vector<int>v;
int dp[1008][1008], totalSum;

int solve(int pos, int sum)
{
    if(sum==totalSum-sum) return 1;
    if(pos>=v.size() or sum>totalSum-sum) return 0;

    if(dp[pos][sum]!=-1) return dp[pos][sum];

    int ans = solve(pos+1, sum+v[pos]) + solve(pos+1, sum);

    return dp[pos][sum] = ans;
}

int main()
{
    int T, n;
    string s;

    cin>>T;
    getline(cin, s);
    while(T--)
    {
        memset(dp, -1, sizeof dp), totalSum = 0;
        getline(cin, s);
        stringstream ss(s);

        while(ss>>n)
        {
            v.push_back(n);
            totalSum+=n;
        }

        if(solve(0,0))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

        v.clear();
    }

    return 0;
}
