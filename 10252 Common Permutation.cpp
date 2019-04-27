#include<bits/stdc++.h>
using namespace std;


int main()
{
    //freopen("10252.txt","w",stdout);
    int visit[100005];
    string s1, s2;
    //char s1[1005], s2[1005];
    vector<char>vec;

    while(getline(cin, s1),  getline(cin, s2))
    {
        // getline(cin, s2);
        int sz1 = s1.size(), sz2 = s2.size();
        //int sz1 = strlen(s1), sz2 = strlen(s2);

        for(int i=0;i<sz2;i++)
        {
            visit[i] = 0;
        }

        for(int i=0;i<sz1;i++)
        {
            for(int j=0;j<sz2;j++)
            {
                if(s1[i]==s2[j] and visit[j]==0)
                {
                    visit[j] = 1;
                    vec.push_back(s1[i]);
                    break;
                }
            }
        }

        sort(vec.begin(), vec.end());

        for(int i=0;i<vec.size();i++)
        {
            cout<<vec[i];
        }

        cout<<endl;
        vec.clear();
    }
}
