#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[101][101];

    int row, col, a, b;

    while(cin>>row>>col>>a>>b)
    {
        if(a==0 and b==0) break;
        if(row==a and col==b)
            cout<<"0"<<endl;
        else if(abs(row-a)==abs(col-b))
            cout<<"1"<<endl;
        else if(row==a or col==b)
            cout<<1<<endl;
        else
            cout<<"2"<<endl;
    }
}
