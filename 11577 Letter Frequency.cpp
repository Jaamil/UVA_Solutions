

#include<bits/stdc++.h>
using namespace std;


int fre[1005];

int main()
{
    string s;

    char ch[100];
    set<int>st;
    map<char,int>mp;
    int t = 0;

    cin>>t;
    getline(cin, s);
    while(t--)
    {
        mp.clear();
        int mx = 0;
        getline(cin, s);

        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {
                s[i] = tolower(s[i]);
                mp[s[i]]++;
                mx = max(mx, mp[s[i]]);
            }
        }

        for(char i='a';i<='z';i++)
        {
            if(mp[i]==mx) cout<<i;
        }

        cout<<endl;
    }
}
