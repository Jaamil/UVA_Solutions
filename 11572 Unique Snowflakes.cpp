
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test, cnt, mx;

    long long a, x, b, c, n, m;
    vector<int>v;
    map<int, int>mp, pos;

    int T;

    cin>>T;
    while(T--)
    {
        cnt = 0, mx = 0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            v.push_back(x);
            mp[x]++;
            if(mp[x]==2)
            {
                mp.clear();
                mp[x] = 1;

                cnt = 1;

                for(int j=i-1;v[j]!=x;j--)
                {
                    mp[v[j]] = 1;
                    cnt++;
                    //cout<<i<<" "<<cnt<<endl;
                }

            }

            else
            {
                cnt++;
            }

            mx = max(mx, cnt);
        }

        cout<<mx<<endl;

        mp.clear(), v.clear();
    }


}
