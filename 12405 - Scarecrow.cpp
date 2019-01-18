#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test,n;
    char arr[1000];
    deque<char>deq;

    cin>>test;
    for(int k=1;k<=test;k++)
    {
        int cnt = 0;
        cin>>n;
        cin>>arr;
        for(int i=0;i<n;i++)
        {
            deq.push_back(arr[i]);
        }



        while(1)
        {
            if(deq.front()=='.')
            {
                cnt++;
                if(!deq.empty()) deq.pop_front();
                if(!deq.empty()) deq.pop_front();
                if(!deq.empty()) deq.pop_front();
            }

            else
                if(!deq.empty()) deq.pop_front();

            if(deq.empty()) break;

        }

        printf("Case %d: %d\n",k,cnt);
    }

    return 0;
}
