#include <bits/stdc++.h>

using namespace std;
#define Max 50000
struct node
{
    int u , w ;
};


class cmp
{
    public :
    bool operator () (node &a,node &b)
    {
        if(a.w>b.w) return true; else return false;
    }
};

vector <int> graph[Max+10];
vector <int> cost[Max+10];
int parent[Max+10];
int dist[Max+10];
bool visit[Max+10] ;

void ini(int n)
{
    for(int i=0;i<=n;i++)
    {
        graph[i].clear();
        cost[i].clear();
        visit[i]=false;
        dist[i]=INT_MAX;
    }
}

int Dijkstra(int N,int source)
{
    priority_queue <node,vector<node>,cmp> Q;

    node n;
    n.u=source;
    n.w=0;

    Q.push(n);
    while(Q.size()!=0)
    {
        n = Q.top();
        Q.pop();

        int u = n.u , w = n.w;
        if(visit[u]) continue;
        visit[u]=true;
        if(u==N) return w;

        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i];
            if(visit[v]==false and dist[u]+cost[u][i]<dist[v])
            {
                n.u=v ;
                n.w=w+cost[u][i];
                Q.push(n);
                dist[v] = dist[u] + cost[u][i];
                parent[v] = u;
            }
        }
    }

    return -1;
}

int main()
{
    int n, m, s, t;
    int N, M;
    int test;
    cin>>test;
    for(int Case=1;Case<=test;Case++)
    {
        scanf("%d%d%d%d",&N,&M,&s,&t);
        ini(N);
        while(M--)
        {
            int u , v , w;
            scanf("%d%d%d",&u,&v,&w);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        if(M==0)
        {
            printf("Case #%d: unreachable\n",Case);
            continue;
        }

        int d = Dijkstra(t,s);
        if(d!=-1) printf("Case #%d: %d\n",Case, d);
        else
        {
            printf("Case #%d: unreachable\n",Case);
        }

    }

    return 0;
}
