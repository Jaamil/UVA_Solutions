#include<bits/stdc++.h>
using namespace std;

bool queued[1010];
queue<int>teams;
queue<int>team_queue[1010];

int main()
{
    int n, k, idx, temp, x, cs = 0;
    string s;

    map<int, int>team;

    while(cin>>n and n)
    {

        printf("Scenario #%d\n", ++cs);

        idx = 0;
        for(int i=0;i<n;i++)
        {
            cin>>k;
            for(int j=0;j<k;j++)
            {
                cin>>x;
                team[x] = i;
            }
        }

        while(cin>>s and s!="STOP")
        {
            if(s=="ENQUEUE")
            {
                cin>>x;
                int tm = team[x];
                if(queued[tm]==false)
                {
                    teams.push(tm);
                    queued[tm] = true;
                }

                team_queue[tm].push(x);
            }

            else{

                int tm = teams.front();

                cout<<team_queue[tm].front()<<endl;
                team_queue[tm].pop();

                if(team_queue[tm].empty())
                {
                    teams.pop();
                    queued[tm] = false;
                }
            }
        }

        team.clear(), teams = queue<int>();

        for(int i=0;i<n;i++)
        {
            queued[i] = false;
            team_queue[i] = queue<int>();

        }

        cout<<endl;
    }

    return 0;
}
