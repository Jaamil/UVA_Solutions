
#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long sum;
    int T;
    int a, b, c, n;
    cin>>T;
    for(int cs=1;cs<=T;cs++)
    {
        sum = 0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            sum+=(long long) a*c;
        }

        cout<<sum<<endl;
    }

    return 0;
}

