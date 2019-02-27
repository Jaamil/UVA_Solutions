
#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 1000;

vector <int> graph[ MAX_NODE ];
int edge, node, cost[ MAX_NODE ], visit[ MAX_NODE ], parent[ MAX_NODE ];
int costBetweenNodes[ MAX_NODE ][ MAX_NODE ];

void ini()
{
     for( int i = 0 ; i <= 100 ; i++ )
    {
        visit[i] = 0;
        cost[i] = INT_MAX;
        graph[i].clear();
    }
}


void bfs(int source, int d)
{
    for( int i = 0 ; i <=100 ; i++ )
    {
        visit[i] = 0;
        cost[i] = INT_MAX;
    }

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
                cost[nxt] = cost[current] + 1;
                q.push(nxt);
            }
        }
    }

    printf("%2d to %2d:%2d\n",source,d,cost[d]);
}


int main()
{
    int n, test, Case = 1;;
    int k = 0;
    while(cin>>n)
    {
        k++;

        for(int i=0;i<n;i++)
        {
            int x , y;
            cin>>y;
            graph[k].push_back(y);
            graph[y].push_back(k);

        }

        if(k==19)
        {
            printf("Test Set #%d\n",Case++);

            cin>>test;
            for(int t=0;t<test;t++)
            {
                int s, d;
                cin>>s>>d;
                bfs(s,d);
            }

            ini();
            k = 0;

            cout<<endl;
        }
    }

    return 0;
}


