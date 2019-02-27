#include<bits/stdc++.h>
using namespace std;

#define mx 1005
int parent[mx], visit[mx];
vector<int>graph[1005];
map<string, int> m;
bool check;

void Clear()
{
    check = false;
    m.clear();
    for(int i=0;i<=1000;i++)
    {
        graph[i].clear();
        visit[i] = 0;
        parent[i] = 0;
    }
}

void bfs(int source, int d)
{
    visit[source] = 1;
    parent[source] = 0;
    queue<int>q;
    q.push(source);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0;i<graph[u].size();i++)
        {
            int nxt = graph[u][i];

            if(!visit[nxt])
            {
                parent[nxt] = u;
                visit[nxt] = 1;
                q.push(nxt);
                if(nxt==d)
                {
                    check = true;
                    return;
                }
            }
        }
    }
}


int main()
{
    //freopen("C.txt","w",stdout);
    string s1, s2;
    int n, Case = 1;
    string arr[1005];
    while(cin>>n)
    {
        if(Case!=1) cout<<endl;
        Case++;
        check = false;
        int index = 1;
        for(int i=0;i<n;i++)
        {
            cin>>s1>>s2;
            if(m[s1]==0)
            {
                arr[index] = s1;
                m[s1] = index++;
            }

            if(m[s2]==0) {
                arr[index] = s2;
                m[s2] = index++;
            }

            graph[m[s1]].push_back(m[s2]);
            graph[m[s2]].push_back(m[s1]);
        }

        cin>>s1>>s2;

        bfs(m[s1], m[s2]);

        if(!check)
        {
            cout<<"No route"<<endl;
            Clear();
            continue;
        }
        int d = m[s2], s = m[s1];
        stack<int> Stack;
        Stack.push(d);
        while(1)
        {
            Stack.push(parent[d]);
            d = parent[d];
            if(d==s) break;
        }

        int x = Stack.top();
        cout<<arr[x]<<" ";
        Stack.pop();

        while(!Stack.empty())
        {
            x = Stack.top();
            cout<<arr[x]<<endl;;
            Stack.pop();

            if(!Stack.empty())
                cout<<arr[x]<<" ";

        }

        Clear();
    }
}
