#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    int n;
    int sum, rem, temp;

    cin>>test;
    while(test--)
    {
        sum = 0, temp = 0;
        cin>>n;

        for(int i=n-1;i>n-100;i--)
        {
            sum = 0;
            int x = i;
            while(x!=0)
            {
                rem = x%10;
                x/=10;
                sum+=rem;
            }

            //cout<<sum<<" "<<i<<endl;
            if((i+sum)==n) temp = i;
        }

        cout<<temp<<endl;
    }
}
