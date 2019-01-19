#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool check;
    int n,q, arr[100001], CASE=0;
    while(cin>>n>>q)
    {
        if(n==0 and q==0) break;
        check = false;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        sort(arr,arr+n);

        for(int i=0;i<q;i++)
        {
            check = false;
            int f;
            cin>>f;
            if(i==0) printf("CASE# %d:\n",++CASE);
            for(int j=0;j<n;j++)
            {
                if(f==arr[j])
                {
                    check = true;
                    printf("%d found at %d\n",f,j+1);
                    break;
                }

            }

            if(check==false) printf("%d not found\n",f);
        }
    }
}
