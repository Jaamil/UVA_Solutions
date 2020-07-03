#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("146o.txt", "w", stdout);
    string s;

    while(cin>>s and s!="#")
    {
        if(next_permutation(s.begin(), s.end()))
        {
            for(int i=0;i<s.size();i++) cout<<s[i];
            cout<<endl;
        }

        else

            cout<<"No Successor"<<endl;
    }

    return 0;
}
