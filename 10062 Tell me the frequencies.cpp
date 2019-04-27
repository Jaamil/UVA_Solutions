
#include<bits/stdc++.h>
using namespace std;

struct root
{
    int ascii, freq;
};

root arr[1005];

int fre[1005];

bool cmp(root a, root b)
{
    if(a.freq==b.freq) return a.ascii>b.ascii;
    return a.freq<b.freq;
}

int main()
{
    string s;

    char ch[100];
    set<int>st;

    int t = 0;

    while(getline(cin, s))
    {
        st.clear();
        for(int i=0;i<=1000;i++) fre[i] = 0;

        for(int i=0;i<s.size();i++)
        {
            int x = (int)s[i];
            fre[x]++;
            st.insert(x);
        }

        int k = 0;
        int sz = st.size();
        for(auto i=st.begin();i!=st.end();i++)
        {
            int x = *i;
            arr[k++] = {x,fre[x]};
        }

        sort(arr, arr+sz, cmp);

        if(t!=0) cout<<endl;

        for(int i=0;i<sz;i++)
        {
            cout<<arr[i].ascii<<" "<<arr[i].freq<<endl;
        }

        t++;
    }
}
