#include<bits/stdc++.h>
using namespace std;

int sumb[100];
int sumg[100];
int sumc[100];

int main()
{
    int b1, b2, b3, c1, c2, c3, g1, g2, g3;

    while(cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3)
    {
        sumb[0] = b2+b3;
        sumb[1]  = b1+b3;
        sumb[2]  = b1+b2;


        sumg[0]  = g2+g3;
        sumg[1]  = g1+g3;
        sumg[2]  = g1+g2;

        sumc[0]  = c2+c3;
        sumc[1]  = c1+c3;
        sumc[2]  = c1+c2;

        long long mn = 10000000000000;

        int b, c, g;

        int cnt = 0;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    if(i==j or j==k or k==i)
                    {
                        continue;
                    }

                    if(mn>sumb[i] +sumc[j] +sumg[k] )
                    {
                        mn = sumb[i] +sumc[j] +sumg[k] ;
                        b = i;
                        c = j;
                        g = k;
                    }
                }
            }
        }

        if(b<=c and b<=g)
        {
            if(c<=g)
            {
                cout<<"BCG ";
            }

            else
            {
                cout<<"BGC ";
            }
        }

        else if(c<=g)
        {
            if(b<=g)
            {
                cout<<"CBG ";
            }

            else
            {
                cout<<"CGB ";
            }
        }

        else
        {
            if(b<=c)
            {
                cout<<"GBC ";
            }

            else
            {
                cout<<"GCB ";
            }
        }


        cout<<mn<<endl;
    }
}
