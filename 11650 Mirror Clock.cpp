


#include<bits/stdc++.h>
using namespace std;

int main()
{
   // freopen("11650o.txt", "w", stdout);
    int T;

    int h, m, mh, mm, cs;

    scanf("%d", &T);
    for(cs=1;cs<=T;cs++)
    {
        scanf("%d:%d", &h, &m);
        mm = (60 - m)%60;

        mh = 24 - h;
        if(mh>13 or (mh==13 and mm==0)) mh = mh % 12;
        if(mm>0) mh--;

        printf("%02d:%02d\n", mh, mm);
    }

    return 0;
}

