

#include<bits/stdc++.h>
using namespace std;

#define mx 200005
int parent[mx];
int rankParent[mx];
int totalMember[mx];

struct edge
{
    int u, v;
    int w;
};

vector<edge>graph;
vector<int>vans;

bool cmp(edge A, edge B)
{
    return A.w<B.w;
}

void initialize(int n)
{
    graph.clear();
    vans.clear();
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

void MST(int n)
{
    sort(graph.begin(),graph.end(),cmp);

    int cnt = 0;
    int ans = 0;

    for(int i=0;i<graph.size();i++)
    {
        int px = findParent(graph[i].u);
        int py = findParent(graph[i].v);

        if(px==py)
        {
            vans.push_back(graph[i].w);
        }

        if(px!=py)
        {
            parent[px] = py;
            cnt++;
            ans+=graph[i].w;
        }

    }

}

int main()
{
    int n, m;

    while(cin>>n>>m and n)
    {
        initialize(n);
        edge get;

        while(m--)
        {
            int x, y, z;
            cin>>x>>y>>z;
            get.u = x;
            get.v = y;
            get.w = z;

            graph.push_back(get);
        }

        MST(n);
        if(vans.size()==0) cout<<"forest"<<endl;
        else
        {
            cout<<vans[0];
            for(int i=1;i<vans.size();i++)
            {
                cout<<" "<<vans[i];
            }

            cout<<endl;
        }

    }

    return 0;
}

