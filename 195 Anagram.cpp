

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    vector<int>v;
    string s;
    map<char, int>chmp1;
    map<int, char>chmp2;
    map<string, int>smp;

    int idx = 0;

    for(char i='A';i<='Z';i++)
    {
        chmp2[idx] = i, chmp1[i] = idx++;
        chmp2[idx] = tolower(i), chmp1[tolower(i)] = idx++;

    }

    cin>>T;
    for(int cs=1;cs<=T;cs++)
    {
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            v.push_back(chmp1[s[i]]);
        }

        sort(v.begin(), v.end());

        s = "";
        for(int i=0;i<v.size();i++)
        {
           s+= chmp2[v[i]];
        }

        smp[s] = 1;
        cout<<s<<endl;

        while(next_permutation(v.begin(), v.end()))
        {
            s = "";
            for(int i=0;i<v.size();i++)
            {
               s+= chmp2[v[i]];
            }

            if(smp[s]==0)
            {
                cout<<s<<endl;
                smp[s] = 1;
            }
        }

        v.clear(), smp.clear();
    }

    return 0;
}

