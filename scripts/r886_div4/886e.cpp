#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        //cout<<"n and c :";
        long long int n, c;
        cin>>n>>c;
        long int arr[n]; 
        for (long long int j=0; j<n; j++)
        {
            cin>>arr[j];
        }

        long long int sum=0,w=0;
        for(w=0; w>-1; w++)
        {   
            sum=0;
            for (long long int j=0; j<n; j++)
            {
                sum = sum + (arr[j]+2*w) * (arr[j]+2*w);
            }
            if(sum == c)
                break;
        }

        cout<<w<<endl;

    }
}