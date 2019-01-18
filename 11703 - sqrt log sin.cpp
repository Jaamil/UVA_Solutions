
#include<bits/stdc++.h>

using namespace std;

int arr[1000015];

int main()
{
    int sum,n,a;



    arr[0] = 1;
    for(int i=1;i<1000015;i++)
    {
        arr[i] = arr[(int)floor(i-sqrt(i))]+arr[(int)floor(log(i))] + arr[(int)floor(i*(sin(i)*sin(i)))];
        arr[i] = arr[i]%1000000;
    }

    while(cin>>n)
    {
        if(n==-1) break;
        cout<<arr[n]<<endl;;
    }

}
