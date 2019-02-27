#include<bits/stdc++.h>
using namespace std;

int dist[1005][1005];
bool visit[1005][1005];

int di[] = {0,-1,0,1};
int dj[] = {-1,0,1,0};
int n, m;

int cnt = 1;

struct Node{
    int u,v;
};

void Clear(int n, int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            visit[i][j] = 0;
            dist[i][j] = 0;
        }
    }
}

int bfs(int x1, int y1, int x2, int y2)
{
    int I,J;
    visit[x1][y1] = 1;
    dist[x1][y1] = 0;
    queue<Node>q;
    q.push({x1,y1});


    while(!q.empty())
    {
        int u = q.front().u;
        int v = q.front().v;
        q.pop();

        for(int i=0;i<4;i++)
        {
            I = u+di[i];
            J = v+dj[i];

            if(I>=0 and I<n and J>=0 and J<m and visit[I][J]==0)
            {
                if(I==x2 and J==y2)
                {
                    int x =  dist[u][v]+1;
                    return x;
                }

               q.push({I,J});
                visit[I][J] = 1;
                dist[I][J] = dist[u][v]+1;


            }
        }
    }
}

int main()
{
    int dista, distb, distc;

    int test, newm;
    int u, v, n2;

    while(cin>>n>>m and n)
    {
        Clear(n,m);
        cin>>newm;

        for(int i=0;i<newm;i++)
        {
            cin>>u>>n2;
            {
                for(int j=0;j<n2;j++)
                {
                    cin>>v;
                    visit[u][v] = 1;
                }
            }
        }

        int x1, y1, x2, y2;

        cin>>x1>>y1>>x2>>y2;
        int dista = bfs(x1, y1, x2, y2);

        printf("%d\n", dista);

    }

}
