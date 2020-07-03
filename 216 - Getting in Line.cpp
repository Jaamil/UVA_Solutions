
#include<bits/stdc++.h>

using namespace std;

struct node{
    int x, y;
};

double calDistance(node a, node b){
    double dist = (a.x - b.x) * (a.x - b.x) + (b.y - a.y) * (b.y - a.y);
    return sqrt(dist);
}

int main()
{
    //freopen("216.txt", "w", stdout);
    int n, tempx, tempy;
    vector<node>v;
    vector<int>numV, finalV;
    double sum, minSum;
    int cs = 1;

    while(cin>>n and n){

        sum = 0, minSum = 0;

        for(int i=0;i<n;i++){
            cin>>tempx>>tempy;
            v.push_back({tempx, tempy});
            numV.push_back(i);
        }

        finalV = numV;

        for(int i=0;i<n-1;i++){
            minSum+= calDistance(v[i], v[i+1]);
        }

        while(next_permutation(numV.begin(), numV.end()))
        {
            sum = 0;
            for(int i=0;i<n-1;i++){
                sum+= calDistance(v[numV[i]], v[numV[i+1]]);
            }

            if(sum<minSum)
            {
                minSum = sum;
                finalV = numV;
            }
        }

        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<cs++<<endl;

        for(int i=0;i<n-1;i++)
        {
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n"
                   , v[finalV[i]].x, v[finalV[i]].y, v[finalV[i+1]].x, v[finalV[i+1]].y
                   , calDistance(v[finalV[i]], v[finalV[i+1]])+16);
        }

        cout<<"Number of feet of cable required is "<<fixed<<setprecision(2)
            <<minSum+(n-1)*16<<"."<<endl;

        v.clear(), finalV.clear(), numV.clear();
    }

    return 0;
}
