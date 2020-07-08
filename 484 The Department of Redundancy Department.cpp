
#include<bits/stdc++.h>
using namespace std;

int main()
{
   // freopen("484o.txt", "w", stdout);

    string s;
    vector<int>v;
    map<int, int>mp, visit;
    int n;

    while(cin>>n){

        if(mp[n]==0)
        {
            mp[n] = 1;
            v.push_back(n);
        }

        else{
            mp[n]++;
        }
    }


    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" "<<mp[v[i]]<<endl;

    return 0;
}

