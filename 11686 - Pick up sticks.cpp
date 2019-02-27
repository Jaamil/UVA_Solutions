#include <bits/stdc++.h>
using namespace std;

#define mx 100000
vector <int> graph[mx+10] , seq ;
int visit[mx+10],cycle=0;

void Clear(int n)
{
    cycle = 0;
    seq.clear();

    for(int i=0;i<=n;i++)
    {
        graph[i].clear();
        visit[i] = 0;
    }
}

void dfs(int u)
{
    if(visit[u]==2||cycle) return;
    if(visit[u]==1)
    {
        cycle = 1 ;
        return;
    }
    visit[u]=1;
    for(int i=0;i<graph[u].size();i++)
    {
        int v = graph[u][i];
        dfs(v);
    }

    visit[u]=2;
    seq.push_back(u);
}


int main()
{
    int N,M;

    while(cin>>N>>M and N)
    {
        Clear(N);
        while(M--)
        {
            int u , v ;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }
        for(int i=1;i<=N;i++) dfs(i);
        if(cycle) printf("IMPOSSIBLE\n");
        else{
            for(int i=N-1;i>=0;i--) {
                printf("%d\n",seq[i]);
            }
        }
    }

    return 0;
}
