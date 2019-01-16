#include<bits/stdc++.h>
using namespace std;

int node, edge;
vector<int >graph[1000];
int parent[1001], dist[101][101], visit[101][101];

int di[] = {-1,-2,-2,-1,1,2,2,1};
int dj[] = {-2,-1,1,2,2,1,-1,-2};

struct Node{
    int u,v;
};

void Clear()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            visit[i][j] = 0;
            dist[i][j] = 0;
        }
    }
}

void bfs(int x, int y)
{
    int I,J;
    visit[x][y] = 1;
    dist[x][y] = 0;
    queue<Node>q;
    q.push({x,y});

    while(!q.empty())
    {
        int u = q.front().u;
        int v = q.front().v;
        q.pop();

        for(int i=0;i<8;i++)
        {
            I = u+di[i];
            J = v+dj[i];

            if(I>0 and I<9 and J>0 and J<9 and visit[I][J]==0)
            {
                dist[I][J] = dist[u][v]+1;
                //parent[nxt] = u;
                q.push({I,J});
                visit[u][v] = 1;
            }
        }
    }
}

int main()
{
    int x, y, d1, d2;
    char s1[100], s2[100];

    map<char, int>m;

    int j = 1;
    for(char i='a';i<'i';i++)
    {
        m[i] = j;
        j++;
    }

    while(cin>>s1>>s2)
    {
        Clear();
        x = m[s1[0]];
        y = s1[1]-48;
        d1 = m[s2[0]];
        d2 = s2[1] - 48;
        bfs(x,y);

        printf("To get from %s to %s takes %d knight moves.\n",s1,s2,dist[d1][d2]);
    }


}
