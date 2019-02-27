
#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 100005;

vector <int> graph[ MAX_NODE ];
int edge, node, cost[ MAX_NODE ], visit[ MAX_NODE ], parent[ MAX_NODE ];


void ini()
{
     for( int i = 0 ; i <= 1000 ; i++ )
    {
        visit[i] = 0;
        cost[i] = INT_MAX;
        graph[i].clear();
    }
}


void bfs(int source, int TTL, set<int>s)
{
    for( int i = 0 ; i <= 1000 ; i++ )
    {
        visit[i] = 0;
        cost[i] = INT_MAX;
    }

    int cnt = 0;
    set<int>::iterator it;
    queue < int > q;
    q.push(source);
    cost[source] = 0;
    visit[source] = 1;
    while( !q.empty() )
    {
        int current = q.front();
        q.pop();
        int sz = graph[current].size();
        for( int i = 0 ; i < sz ; i++ )
        {
            int nxt = graph[current][i];
            if( visit[nxt] == 0 )
            {
                visit[nxt] = 1;
                parent[ nxt ] = current;
                cost[nxt] = cost[current] + 1;
                q.push(nxt);
            }
        }
    }

    for( it = s.begin() ; it!=s.end() ; it++ )
    {

        int x = *it;

        if(cost[x]>TTL)
        {

            cnt++;
        }
    }

    printf("%d nodes not reachable from node %d with TTL = %d.\n", cnt, source, TTL);

}


int main()
{
    int source, TTL;
    int Case = 1;

    set<int>s;
    while(cin>>edge and edge)
    {
        ini();
        int x , y;
        for( int i = 0 ; i < edge ; i++ )
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
            s.insert(x);
            s.insert(y);
        }

        while(cin>>source>>TTL and source)
        {
            printf("Case %d: ",Case++);
            bfs(source,TTL,s);
        }

        s.clear();
    }

    return 0;
}



