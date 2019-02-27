#include<bits/stdc++.h>
using namespace std;

#define mx 1005
int n, m;
int capacity[mx][mx];

int residualCapacity[mx][mx];
int parent[mx];


void Clear()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            capacity[i][j] = 0;
            residualCapacity[i][j] = 0;
        }
    }
}

bool bfs(int parent[], int source, int sink)
{
    bool visit[mx];
    memset(visit,false,n);

    queue<int>q;
    q.push(source);
    visit[source]  = 1;
    parent[source] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0;i<n;i++)
        {
            if(!visit[i] and residualCapacity[u][i]>0)
            {
                visit[i] = 1;
                q.push(i);
                parent[i] = u;

            }
        }

    }

    return (visit[sink] == true);
}

int maxFlow(int source, int sink)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            residualCapacity[i][j] = capacity[i][j];
        }
    }

    int maxf = 0;

    while(bfs(parent, source, sink))
    {
        int flow = INT_MAX;
        int v = sink;

        while(v!=source)
        {
            int u = parent[v];

            if(flow>residualCapacity[u][v])
            {
                flow = residualCapacity[u][v];
            }

            v = u;
        }

        maxf += flow;
        v = sink;

        while(v!=source)
        {
            int u = parent[v];

            residualCapacity[u][v]-=flow;
            residualCapacity[v][u]+=flow;
            v = u;
        }
    }

    return maxf;
}

int main()
{
    //freopen("A.txt","w",stdout);
    int s, t,  net = 1;
    while(cin>>n and n)
    {
        Clear();
        cin>>s>>t>>m;
        for(int i=0;i<m;i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            capacity[u-1][v-1] = capacity[u-1][v-1] + w;
            capacity[v-1][u-1] = capacity[v-1][u-1] + w;
        }

        cout<<"Network "<<net++<<endl;
        cout<<"The bandwidth is "<<maxFlow(s-1,t-1)<<".\n";
        cout<<endl;
    }
}

