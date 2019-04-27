
#include<bits/stdc++.h>
using namespace std;


 bool isPrime(int n)
 {

     if( n <= 1)
        return false;
     else if(n <= 3)
        return true;
     else if (n % 2 == 0 or n % 3 == 0)
        return false;

     int i = 5;

     while (i * i <= n)
     {
        if (n % i == 0 or n % (i + 2) == 0)
            return false;
        i = i + 6;
     }

    return true;
 }



int main()
{
    string s;

    char ch[100];
    map<char,int>mp;
    int test = 0;

    cin>>test;
    getline(cin, s);
    for(int t=1;t<=test;t++)
    {
        mp.clear();
        bool chk = 0;
        getline(cin, s);

        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }

        printf("Case %d: ",t);
        for(char i='0';i<='9';i++)
        {
            if(isPrime(mp[i]))
            {
                cout<<i;
                chk = 1;
            }
        }

        for(char i='A';i<='Z';i++)
        {
            if(isPrime(mp[i]))
            {
                cout<<i;
                chk = 1;
            }
        }

        for(char i='a';i<='z';i++)
        {
            if(isPrime(mp[i]))
            {
                cout<<i;
                chk = 1;
            }
        }

        if(chk==0) cout<<"empty";
        cout<<endl;
    }
}
