

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector<string>v;
    map<string, int>mp, visit;
    int T, cnt;

    cin>>T;
    getline(cin, s);
    getline(cin, s);
    while(T--)
    {
        cnt = 0, mp.clear(), v.clear();
        while(1)
        {
            getline(cin, s);
            if(s=="") break;

            mp[s]++;
            cnt++;
        }

        for(auto x:mp)
        {
            double temp = x.second;
            cout<<x.first<<" ";
            printf("%.4f\n", (temp*1.0/cnt) * 100);
        }

        if(T) cout<<endl;
    }

    return 0;
}

