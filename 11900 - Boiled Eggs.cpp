

#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool check;
    int n,q,p,test, arr[100001], Case=0;
    cin>>test;
    while(test--)
    {
        int cnt = 0, sum = 0;
       cin>>n>>p>>q;
       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }

       int i;
       for(i=0;i<n;i++)
       {
           sum+=arr[i];
           if(sum>q) break;
           if(i+1>p) break;
       }

       printf("Case %d: %d\n",++Case,i);
       //cout<<i<<endl;
    }
}
