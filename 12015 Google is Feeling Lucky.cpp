#include<bits/stdc++.h>
using namespace std;

int main()
{

    map<string, int>mp, visit;
    int T;
    int cnt, mx;
    string s;
    vector<string>v;

    cin>>T;
    for(int cs=1;cs<=T;cs++)
    {
        mx = 0;
        for(int i=0;i<10;i++)
        {
            cin>>s>>cnt;
            mp[s] = max(mp[s], cnt);
            mx = max(mx, cnt);
            v.push_back(s);
        }

        printf("Case #%d:\n", cs);

        for(auto x:v)
        {
            //cout<<x->first<<endl;
            if(mp[x]==mx and visit[x]==0)
            {
                cout<<x<<endl;
                //cout<<x->first<<endl;
                visit[x] = 1;
            }
        }

        mp.clear(), visit.clear();
    }

    return 0;
}
