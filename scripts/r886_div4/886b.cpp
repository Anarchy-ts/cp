#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        //cout<<"Number of responses : ";
        int n;
        cin>>n;

        int words[n],qual[n];
        for(int j=0; j<n; j++)
        {
            //cout<<"Words and qual input : ";
            cin>>words[j]>>qual[j];
        }
        int index=0,large=qual[0];
        for (int j=0; j<n; j++)
        {
            if (words[j] <= 10)
            {
                if(qual[j] > large)
                {
                    large=qual[j];
                    index=j;
                }
            }
        }
        cout<<index+1<<endl;
    }
}