#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    while(cin>>s)
    {
        if(s==".") break;
        int sz = s.size();
        int ans = sz;

        for(int i=1;i<(sz/2)+1;i++)
        {
            bool chk = 1;
            if(sz%i!=0) continue;
            int x = i;
            for(int j=x;j<sz;j++)
            {
                if(s[j]!=s[j%x])
                {
                    chk = 0;
                    break;
                }
            }

            if(chk == 1)
            {
                ans = i;
                break;
            }
        }

        cout<<sz/ans<<endl;
    }
}
