#include<bits/stdc++.h>

using namespace std;

int main()
{
    char a[100000],b[100000];

    while(scanf("%s%s",a,b)==2)
    {
        int count = 0,k=0;
        int len=strlen(a);
        int le=strlen(b);
        for(int i=0;i<len;i++)
        {
            for(int j=k;j<le;j++)

            {
                k++;
                if(a[i]==b[j])
                {
                    count++;
                    break;
                }
            }
        }

        if(count==len) cout<<"Yes\n";

        else cout<<"No\n";
    }
}
