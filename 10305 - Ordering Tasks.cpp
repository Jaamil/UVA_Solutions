#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10000];
int node, edge, visit[10000];
stack<int>topo;

void Clear()
{
    for(int i=0;i<=node;i++)
    {
        visit[i] = 0;
        graph[i].clear();
    }
}

void dfs(int x)
{
    visit[x] = 1;
    int sz = graph[x].size();
    for(int i=0;i<sz;i++)
    {
        int nxt = graph[x][i];
        if(visit[nxt]==0) dfs(nxt);
    }

    topo.push(x);
}

int main()
{
   while(1)
   {
       Clear();
        cin>>node>>edge;
        if(node==0 and edge==0) break;
        for(int i=0;i<edge;i++)
        {
            int u, v;
            cin>>u>>v;
            graph[u].push_back(v);
        }

        for(int i=1;i<=node;i++)
            if(visit[i]==0) dfs(i);

        cout<<topo.top();
        topo.pop();
        while(!topo.empty())
        {
            cout<<" "<<topo.top();
            topo.pop();
        }

        cout<<endl;
   }
    return 0;
}
