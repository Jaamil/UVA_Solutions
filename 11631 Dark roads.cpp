
#include<bits/stdc++.h>
using namespace std;

#define mx 2000005
int parent[mx];
int rankParent[mx];
int totalMember[mx];

struct edge
{
    int u, v;
    long long w;
};

vector<edge>graph;

bool cmp(edge A, edge B)
{
    return A.w<B.w;
}

void initialize(int n)
{
    for(int i=0;i<=n;i++)
    {
        //graph[i].clear();
        parent[i] = i;
        rankParent[i] = 0;
    }
}

int findParent(int x)
{
    int prev;
    while(x!=parent[x])
    {
        prev = x;
        x = parent[x];
        parent[prev] = parent[x];
    }

    return x;
}

long long MST(int n)
{
    sort(graph.begin(),graph.end(),cmp);

    int cnt = 0;
    long long ans = 0;

    for(int i=0;i<graph.size();i++)
    {
        int px = findParent(graph[i].u);
        int py = findParent(graph[i].v);

        if(px!=py)
        {
            parent[px] = py;
            cnt++;
            ans+=graph[i].w;
        }

        if(cnt==n-1) break;
    }

    if(cnt!=n-1) return -1;
    return ans;
}

int main()
{
    //freopen("11631.txt","w",stdout);
    int n, m;
    long long total;

    while(cin>>n>>m and n)
    {
        initialize(n);
        edge get;
        total = 0;

        while(m--)
        {
            int x, y;
            long long z;

            scanf("%d%d%lld",&x,&y,&z);

            get.u = x;
            get.v = y;
            get.w = z;
            total+=z;

            graph.push_back(get);
        }

        cout<<total - MST(n)<<endl;
        graph.clear();
    }

    return 0;
}

