
#include<bits/stdc++.h>
using namespace std;

int graph[1001][1001], color[1001],dist[1001],parent[1001];

#define white 1
#define blue 2
#define green 3

void Clear(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j] = 0;
        }
    }
}

int main()

{
    //freopen("10004o.txt","w",stdout);
    int n,m;
    int s,d;

    while(cin>>n and n)
    {
        Clear(n);
        cin>>m;

        bool bipartite = true;
        for(int i=0;i<=n;i++)
        {
            color[i] = white;
        }

        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            graph[u][v]=1;

        }


        queue<int>Q;
        Q.push(0);

        color[0] = blue;
        parent[0] = 500;
        color[500] = 500;

        while(Q.size()!=0)
        {
            int u=Q.front();

            Q.pop();
            for(int i=0;i<n;i++)
            {
                if(graph[u][i]==1 && color[i]==color[u])
                {

                    bipartite = false;
                    break;
                }

                if(graph[u][i]==1 && color[i]==white)
                {

                    if(color[u]==blue)
                    {

                        color[i] = green;
                    }

                    else color[i] = blue;

                    Q.push(i);
                    parent[i] = u;

                }
            }

            if(bipartite==false) break;
        }

        if(bipartite==true) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;

    }

    return 0;
}
