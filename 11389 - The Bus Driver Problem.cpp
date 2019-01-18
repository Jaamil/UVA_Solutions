
#include<bits/stdc++.h>
using namespace std;



bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    //freopen("11389o.txt","w",stdout);
    int task, penalty = 0, tComplete = 0,d,r, arr1[100001], arr2[100001];
    while(cin>>task>>d>>r)
    {
        penalty = 0;
        if(task==0 and d==0 and r==0) break;

        for(int i=0;i<task;i++)
        {
            cin>>arr1[i];
        }
        for(int i=0;i<task;i++)
        {
            cin>>arr2[i];
        }

        sort(arr1, arr1+task);
        sort(arr2, arr2+task, cmp);

        for(int i=0;i<task;i++)
        {
            tComplete = arr1[i] + arr2[i];
            if(d<tComplete)
            {
                penalty+=tComplete-d;
            }
        }

        cout<<penalty*r<<endl;
    }
}
