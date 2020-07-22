
#include <bits/stdc++.h>
using namespace std;

#define M_PI acos(-1)


struct node{
    long double lat, lon;
};

long double toRadians(const long double degree)
{
	long double one_deg = (M_PI) / 180;
	return (one_deg * degree);
}

long double distance(long double lat1, long double long1,
					long double lat2, long double long2)
{
	lat1 = toRadians(lat1);
	long1 = toRadians(long1);
	lat2 = toRadians(lat2);
	long2 = toRadians(long2);

	long double dlong = long2 - long1;
	long double dlat = lat2 - lat1;

	long double ans = pow(sin(dlat / 2), 2) +
						cos(lat1) * cos(lat2) *
						pow(sin(dlong / 2), 2);

	ans = 2 * asin(sqrt(ans));

	long double R = 6378;

	ans = ans * R;

	return ans;
}

int main()
{
    //freopen("535.txt", "w", stdout);
	long double lat1;
	long double long1;
	long double lat2;
	long double long2;

	string s, s1, s2;
	map<string, int>mp;
	vector<node>v;
	node arr[10005];

	int cnt = 1;

	v.push_back({0,0});
	while(cin>>s)
    {
        if(s=="#") break;

        cin>>lat1>>long1;
        v.push_back({lat1, long1});
        mp[s] = cnt++;
    }

    while(cin>>s1>>s2)
    {
        if(s1=="#") break;

        cout<<s1<<" - "<<s2<<endl;

        lat1 = v[mp[s1]].lat;
        long1 = v[mp[s1]].lon;

        lat2 = v[mp[s2]].lat;
        long2 = v[mp[s2]].lon;

        if(mp[s1]==0 or mp[s2]==0)
        {
            cout<<"Unknown"<<endl;
            continue;
        }

        cout << (int)round(distance(lat1, long1,
					lat2, long2)) << " km"<<endl;

    }

	return 0;
}
