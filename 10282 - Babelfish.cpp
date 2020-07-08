


#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s;
    vector<string>v;
    map<string, string>mp, visit;
    int T, cnt;

    while(getline(cin, s))
    {
        if(s=="") break;
        stringstream ss(s);

        ss >> s1;
        ss >> s2;

        mp[s2] = s1;
    }

    while(getline(cin, s))
    {
        if(s=="") break;
        if(mp[s]=="") cout<<"eh"<<endl;
        else
            cout<<mp[s]<<endl;
    }

    return 0;
}

