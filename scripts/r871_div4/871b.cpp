// Codeforces Round 871 Div 4.

// Input : Binary array; Zeroes are spaces; Print largest number of spaces.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    //cout<<"Enter number of test cases : ";
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        //cout<<"Enter array size : ";
        int n;
        cin>>n;
        int arr[n+1];
        //cout<<"Enter array elements : \n";
        for(int j=0; j<n; j++)
            cin>>arr[j];
        arr[n]=1;
        int large=0,c=0;
        for(int j=0; j<=n; j++)
        {   
            if(arr[j] == 0)
            {
                c++;
                //cout<<"c : "<<c<<" arr[j]: "<<arr[j]<<endl;
            }
            if (arr[j]==1)
            {   
                if(c > large)
                {
                    large=c;
                    //cout<<"large : "<<large<<endl;
                }
                c=0;
            }
        }
        cout<<large<<endl;
        //cout<<"Largest number of spaces : "<<large<<endl;
        
    }
    return 0;
}