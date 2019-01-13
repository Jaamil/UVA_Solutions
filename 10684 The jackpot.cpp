#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum, maxSum;
    int n, x;

    while(cin>>n and n)
    {
        sum = maxSum = 0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            sum+=x;
            if(sum<0) sum = 0;

            maxSum = max(maxSum, sum);
        }

        //cout<<maxSum<<endl;
        if(maxSum!=0) printf("The maximum winning streak is %d.\n",maxSum);
        else printf("Losing streak.\n");
    }
}
