#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100005];
    int n, price;

    while(cin>>n)
    {
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        cin>>price;

        sort(arr, arr+n);

        int mid = n/2;

        bool chk = 0;
        int mn1 = INT_MAX, mn2 = INT_MAX;

        int i1, j1, i2, j2;

        for(int i=n;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if((arr[i]+arr[j])==price){
                    chk = 1;
                    i1 = arr[i];
                    j1 = arr[j];
                    mn1 = arr[j] - arr[i];
                    break;
                }

                if((arr[i]+arr[j])>price) break;
            }

            if(chk==1) break;
        }

        printf("Peter should buy books whose prices are %d and %d.\n",i1, j1);
        cout<<endl;
    }
}
