

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int flag,Min,i,j,m,n,h=0,a=0 , k=0,y;

    //freopen ("10189in", "r", stdin);
    //freopen ("10189out", "w", stdout);

    while(cin>>m>>n)
    {
        Min = INT_MAX;
        int x;
        k++;
        if(m==0&&n==0) break;
        for(int i=0;i<m;i++)
        {
            cin>>x;
            Min = min(Min,x);
        }

        for(int i=0;i<n;i++) cin>>y;

        if(m<=n)
        {
            printf("Case %d: 0\n",k);
        }
        else{

            printf("Case %d: %d %d\n",k,m-n, Min);

        }

    }
}
