
#include<bits/stdc++.h>
using namespace std;

int n, rows, cols;
int visitedAll;

int dp[1030][15];

struct node{
    int x, y;
};

vector<node>v;

int tsp(int mask, int pos)
{
    int dist;
    if(mask==visitedAll)
    {
        dist = abs(v[pos].x-v[0].x) + abs(v[pos].y - v[0].y);
        return dist;
    }

    if(dp[mask][pos]!=-1) return dp[mask][pos];

    int ans = INT_MAX;

    for(int city=0;city<=n;city++){
        if((mask&(1<<city))==0) {
            dist = abs(v[pos].x-v[city].x) + abs(v[pos].y - v[city].y);
            int newAns = dist + tsp(mask|(1<<city), city);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main()
{
    int T, sx, sy;
    cin>>T;
    while(T--){

        memset(dp, -1, sizeof dp);
        cin>>rows>>cols;

        cin>>sx>>sy;

        v.push_back({sx, sy});

        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>sx>>sy;
            v.push_back({sx, sy});
        }

        visitedAll = pow(2, n+1) - 1;

        cout<<"The shortest path has length ";
        cout<<tsp(1, 0)<<endl;
        v.clear();
    }

    return 0;
}
