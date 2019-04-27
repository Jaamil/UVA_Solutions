

#include<bits/stdc++.h>
using namespace std;


bool isVowel(char ch) {
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
         return true;
    else return false;
}

int main()
{
    string s;
    char ch;

    while(getline(cin, s))
    {

        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {
                if(isVowel(tolower(s[i])))
                {
                    while(isalpha(s[i]))
                    {
                        cout<<s[i];
                        if(!isalpha(s[i+1])) break;
                        i++;
                    }

                    cout<<"ay";
                }

                else
                {
                    ch = s[i];
                    if(isalpha(s[i+1]))
                    {
                        i++;
                        while(isalpha(s[i]))
                        {
                            cout<<s[i];
                            if(!isalpha(s[i+1])) break;
                            i++;
                        }
                    }

                    cout<<ch<<"ay";
                }
            }

            else
                cout<<s[i];
        }

        cout<<endl;

    }
}
