
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int first, sec;
};

int main()
{
    node arr[100005];

    int T;
    int cnt, x, y, n;
    cin>>T;
    for(int cs=1;cs<=T;cs++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            cnt = abs(x-y);
            arr[i].first = x;
            arr[i].sec = y;

        }

        bool chk = 1;

        for(int i=0;i<n;i++)
        {
            if(abs(arr[i].first-arr[i].sec)!=cnt)
            {
                chk = 0;
                cout<<"no"<<endl;
                break;
            }
        }

        if(chk) cout<<"yes"<<endl;

        if(cs!=T) cout<<endl;
    }

    return 0;
}
