

#include<bits/stdc++.h>
using namespace std;

#define mx 2000005
int parent[mx];
int rankParent[mx];
int totalMember[mx];
int cnt = 0;
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
    cnt = 0;
    for(int i=0;i<=n;i++)
    {
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

long long MST(int n, int a)
{
    sort(graph.begin(),graph.end(),cmp);

    long long ans = 0;

    for(int i=0;i<graph.size();i++)
    {
        int px = findParent(graph[i].u);
        int py = findParent(graph[i].v);

        if(px!=py and graph[i].w<a)
        {
            parent[px] = py;
            cnt++;
            ans+=graph[i].w;
        }

        if(cnt==n-1) break;
    }

    return ans;
}

int main()
{
    //freopen("11733.txt","w",stdout);
    int n, m;
    long long total;

    int test, a;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        cin>>n>>m>>a;
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

        long long cost = MST(n, a);

        printf("Case #%d: ",t);
        cout<<a*(n-cnt)+cost<<" "<<n-cnt<<endl;

        graph.clear();
    }

    return 0;
}

