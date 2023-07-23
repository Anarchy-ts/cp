#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        //cout<<"enter no. of frogs : ";
        long int n;
        cin>>n;
        long int size[n], sum[n]={0}, freq[n]={0};
        for (int j=0; j<n; j++)
        {
            cin>>size[j];
        }
        long int c=0,count=0;
        long int large[n]={0};
        for(int l=1; l<=n; l++)
        {   c=0;
            for(int p=0; p<n; p++)
            {
                for (int j=0; j<n; j++)
                {
                    
                    sum[j]=(j+1)*size[p];
                    //cout<<"sum : "<<sum[j]<<" l : "<<l<<" j :"<<j<<endl;
                    if(l==sum[j])
                        c++;
                }
            }

            freq[l-1]=c;            
            //cout<<"l : "<<l<<" freq: "<<freq[l-1]<<endl;
        }
        // for (int j=0; j<n; j++)
        //     cout<<"freq: "<<freq[j]<<" ";
        // cout<<endl;
        long int lg=freq[0];
        for ( int j=0; j<n; j++)
            {
                if(freq[j]>lg)
                    lg=freq[j];

            }
        cout<<lg<<endl;
    }
}