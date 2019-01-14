
#include "bits/stdc++.h"
using namespace std;

int main(){
    int Flag[130],n,rem,x,test;


    char s;
    cin>>test;
    while(test--)
    {
        for(int i=0; i<57; i++) Flag[i]=0;

        for(int i=1; i<=n; i++){
            x=i;
            while(x>0)
            {
                rem = x%10;
                x=x/10;
                s=rem+48;
                Flag[s]++;
            }
        }

        cout<<Flag[48];
        for(int i=49; i<=56; i++){

           printf(" %d",Flag[i]);

        }

        cout<<endl;
    }
        return 0;
}
