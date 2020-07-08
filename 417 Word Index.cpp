
#include<bits/stdc++.h>
using namespace std;

int main()
{
   // freopen("11650o.txt", "w", stdout);

    string s;
    vector<int>v;
    map<string, int>mp, visit;

    int idx = 1;

    for(char i='a';i<='z';i++)
    {
        s = i;
        //cout<<s<<" "<<idx<<endl;
        mp[s] = idx++;
    }

    for(char i='a';i<='z';i++)
    {
        for(char j=i+1;j<='z';j++){
            s = "";
            s += i;
            s+= (char) j;

            //cout<<s<<" "<<idx<<endl;
            mp[s] = idx++;
        }

    }

    for(char i='a';i<='z';i++)
    {
        for(char j=i+1;j<='z';j++){
            for(char k=j+1;k<='z';k++){
                s = "";
                s =+ i;
                s+= (char) j;
                s+= (char) k;
                //cout<<s<<" "<<idx<<endl;
                mp[s] = idx++;
            }
        }
    }

    for(char i='a';i<='z';i++)
    {
        for(char j=i+1;j<='z';j++){

            for(char k=j+1;k<='z';k++){

                for(char l=k+1;l<='z';l++){
                    s = "";
                    s =+ i;
                    s+= (char) j;
                    s+= (char) k;
                    s+= (char) l;
                    //cout<<s<<" "<<idx<<endl;
                    mp[s] = idx++;
                }
            }
        }
    }


    for(char i='a';i<='z';i++)
    {
        for(char j=i+1;j<='z';j++){

            for(char k=j+1;k<='z';k++){

                for(char l=k+1;l<='z';l++){

                    for(char m=l+1;m<='z';m++){
                        s = "";
                        s =+ i;
                        s+= (char) j;
                        s+= (char) k;
                        s+= (char) l;
                        s+= (char) m;
                        //cout<<s<<" "<<idx<<endl;
                        mp[s] = idx++;
                    }
                }
            }
        }
    }

    while(cin>>s)
    {
        cout<<mp[s]<<endl;
    }

    return 0;
}

