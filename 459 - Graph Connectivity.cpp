#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1001];
bool visit[10001];
int cnt;

void initialize()
{
     cnt = 0;
     memset(visit, false, sizeof(visit));
     for(int i=0;i<=1000;i++) graph[i].clear();
}

void dfs(int x)
{
    visit[x] = true;
    int sz = graph[x].size();
    for(int i=0;i<sz;i++)
    {
        int nxt = graph[x][i];
        if(!visit[nxt]) dfs(nxt);
    }
}

int main()
{
    //freopen("459output.txt","w",stdout);
    string s, s1, s2;
    int u, v;
    int test;
    cin>>test;
    getline(cin,s);
    getline(cin,s);
    while(test--)
    {
        initialize();
        getline(cin,s1);
        int x = s1[0] - 65;

        while(true)
        {
            getline(cin,s2);
            if(s2.size()==0) break;
            u = s2[0]-'A';
            v = s2[1]-'A';

            graph[u].push_back(v);
            graph[v].push_back(u);
        }


        for(int i=0;i<=x;i++)
        {
            if(visit[i]==false)
            {
        //        cout<<cnt<<endl;
                cnt++;
                dfs(i);
            }
        }

        cout<<cnt<<endl;
        if(test!=0) cout<<endl;
    }
}
