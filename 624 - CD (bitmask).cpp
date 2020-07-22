#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, sum, mxSum, mask;
    vector<int>v;

    while(cin>>m)
    {
        mxSum = 0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }

        for(int i=1;i<(1<<n);i++)
        {
            sum = 0;
            for(int j=0;j<n;j++)
            {
                if(i& (1<<j))
                {
                    sum+=v[j];
                }
            }

            if(sum>mxSum and sum<=m)
            {
                mxSum = sum;
                mask = i;
            }

        }

        for(int i=0;i<n;i++)
        {
            if(mask& (1<<i)) cout<<v[i]<<" ";
        }

        cout<<"sum:"<<mxSum<<endl;
        v.clear();
    }

    return 0;
}
