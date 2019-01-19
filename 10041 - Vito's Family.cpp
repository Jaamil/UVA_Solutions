#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,b,c,n,arr[100000];

    cin>>t;
    while(t--)
    {
        int sum = 0, b = 0,count=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        sort(arr,arr+n);

        for(int i=0;i<n/2;i++)
        {
            sum+= arr[n-i-1] - arr[i];
        }


        cout<<sum<<endl;
    }
    return 0;
}
