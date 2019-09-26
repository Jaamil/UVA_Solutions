
#include<bits/stdc++.h>
using namespace std;


int createTempArr(string pattern)
{
    vector<int>lps(pattern.length());
    int idx = 0;

    for(int i=1;i<pattern.length();)
    {
        if(pattern[idx]==pattern[i]) {
            lps[i] = idx + 1;
            idx++, i++;
        }

        else{
            if(idx!=0) idx = lps[idx-1];
            else
                lps[i] = idx, i++;
        }

    }

    return lps[lps.size()-1];
}


int main()
{
    string s, rs, comString;

    while(cin>>s)
    {
        rs = "";
        for(int i=s.size()-1;i>=0;i--) rs+=s[i];

        comString = rs;
        comString+='#';

        comString+=s;

        int mxlps =  createTempArr(comString);

        cout<<s;
        for(int i=mxlps;i<s.size();i++) cout<<rs[i];
        cout<<endl;

    }

    return 0;
}
