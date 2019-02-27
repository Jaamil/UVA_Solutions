#include<bits/stdc++.h>
using namespace std;

vector<int>graph[100005];
int visit[100005];
bool check;

void Clear(int n)
{
    check = false;
    for(int i=0;i<=n;i++)
    {
        visit[i] = 0;

    }
}

void dfs(int u, int v)
{
    int sz = graph[u].size();
    for(int i=0;i<sz;i++)
    {
        int nxt = graph[u][i];
        if(!visit[nxt])
        {

            if(nxt==v)
            {
                check = true;
                return;
            }
            visit[nxt] = 1;
            dfs(nxt, v);
        }
    }
}

int main()
{
    //freopen("B.txt","w",stdout);
    int u, v;
    int test;
    cin>>test;
    string s, str;
    int n;

    while(test--)
    {

        cin>>n;
        int success = 0, unsuccess = 0;
        for(int i=0;i<=n;i++)
        {
            graph[i].clear();
            visit[i] = 0;
        }

        getline(cin,str);

        while(getline(cin,str))
        {

            if(str.size()==0)
            {
                break;
            }

            stringstream s(str);
            char ch, c;
            int num, l = 0;
            int count = 0;

            s>>ch;
            c = ch;

            while (s >> num)
            {
                if(l == 0)
                {
                    u = num;
                    l++;
                }
                else
                {
                    v = num;
                }
            }

            if(c=='c')
            {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }

            if(c=='q')
            {
                 Clear(n);

                if(u!=v) dfs(u,v);
                else
                {
                    success++;
                    continue;
                }

                if(check==true) success++;
                else
                {
                    unsuccess++;
                }
            }

        }

        cout<<success<<","<<unsuccess<<endl;
        if(test!=0) cout<<endl;
    }
}
