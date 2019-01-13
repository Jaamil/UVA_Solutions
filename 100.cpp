#include<cstdio>
#include<cmath>

int main()

{
    int a,i,m,n,b,c,cycle,max_cycle;


    while(scanf("%d%d",&m,&n)==2)
    {
        b=m;
        c=n;

        if(m>n)
        {
            a=m;
            m=n;
            n=a;
        }
        max_cycle=0;

        for(i=m;i<=n;i++)
        {
            cycle=1;


            long long x=i;
            while(x!=1)
            {
                if(x%2==1) x=3*x+1;

                else x/=2;

                cycle++;
            }

            if(max_cycle<cycle) max_cycle=cycle;
        }
        printf("%d %d %d\n",b,c,max_cycle);
    }
}
