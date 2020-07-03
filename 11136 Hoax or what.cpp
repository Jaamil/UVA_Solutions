#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test, sum;

    long long a, x, b, c, n, m, k;

    multiset<int>st;

    int T;

    while(cin>>n and n)
    {
        sum = 0;

        for(int i=0;i<n;i++)
        {
            cin>>k;
            for(int j=0;j<k;j++)
            {
                cin>>x;
                st.insert(x);
            }

            auto mn = st.begin();
            auto mx = (--st.end());

            sum+= (long long)(*mx - *mn);

            st.erase(mn);
            st.erase(mx);

        }

        cout<<sum<<endl;

        st.clear();
    }

}
