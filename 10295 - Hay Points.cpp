



#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s;
    map<string, int>mp;
    int T, cnt = 0;

    int n, m, x, sum;

    cin>>m>>n;

    for(int i=0;i<m;i++)
    {
        cin>>s>>x;
        mp[s] = x;
    }

    for(int i=0;i<n;i++)
    {
        sum = 0;
        while(cin>>s)
        {
            if(s==".") break;
            sum+=mp[s];
        }

        cout<<sum<<endl;
    }

    return 0;
}

