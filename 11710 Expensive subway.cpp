
#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v;
    long long w;
};

vector<edge>graph;
int parent[200005], rankParent[200005];

bool cmp(edge A, edge B)
{
    return A.w<B.w;
}

void initialize(int n)
{
    graph.clear();
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
    edge get;
    int n, m;
    map<string, int>mp;
    int test;
    string s1, s2, s;
    while(cin>>n>>m and n)
    {
        initialize(n);
        for(int i=0;i<n;i++)
        {
            cin>>s;
            mp[s] = i;
        }

        for(int i=0;i<m;i++)
        {
            int x, y;
            long long z;

            cin>>s1>>s2>>z;

            get.u = mp[s1];
            get.v = mp[s2];
            get.w = z;

            graph.push_back(get);

        }

        cin>>s;
        long long ans = MST(n);
        if(ans==-1) cout<<"Impossible"<<endl;
        else cout<<ans<<endl;
        mp.clear();
    }
}
