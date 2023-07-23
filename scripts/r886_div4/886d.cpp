#include<bits/stdc++.h>
using namespace std;

bool freq(long long int a, long long int arr[], long int n)
{   
    
    long int c=0;
        for(int j=0; j<n ; j++)
        {
            if (a==arr[j] && arr[j] != 0)
                c++;
        }
        if(c==2)
            return true;
        return false;
    
}

int main()
{
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        //cout<<"n and k : ";
        long int n,k;
        cin>>n>>k;
        
        long long int hard[n],hardcp[n], rm[n]={0}, rm2[n]={0};
        for(int j=0; j<n; j++)
        {
            cin>>hard[j];
            hardcp[j]=hard[j];
        }
        if (n==1)
        {
            cout<<0<<endl;
            continue;
        }
        long int c=0;
        for (int l=0; l<n-1; l++)
        {
            for (int j=0; j<n-l-1 ; j++)
            {
                if (abs(hard[j]-hard[j+1]) > k)
                {
                    if ( hard[j+1] > hard[j])
                    {    
                        rm[c++]=hard[j+1];
                        hard[j+1]=hard[j];
                    }
                    if(hard[j+1]<hard[j])
                    {
                        rm[c++]=hard[j];
                        hard[j]=hard[j+1];
                    }
                    // cout<<hard[j]<<" "<<hard[j+1]<<endl;
                
                }
            
            }
        }
        // cout<<"rm : "<<endl;
        // for (int l=0; l<c; l++)
        //     cout<<rm[l]<<" ";
        // cout<<endl;
        // bool check=false;
        // for (int j=0; j<c; j++)
        // {
        //     if
        // }
        //cout<<c<<endl;
        long int c2=0;
        for (int l=0; l<n-1; l++)
        {
            for (int j=0; j<n-l-1 ; j++)
            {
                if (abs(hardcp[j]-hardcp[j+1]) > k)
                {
                    if ( hardcp[j+1] < hardcp[j])
                    {    
                        rm2[c2++]=hardcp[j+1];
                        hardcp[j+1]=hardcp[j];
                    }
                    if(hardcp[j+1]>hardcp[j])
                    {
                        rm2[c2++]=hardcp[j];
                        hardcp[j]=hardcp[j+1];
                    }
                    // cout<<hard[j]<<" "<<hard[j+1]<<endl;
                
                }
            
            }
        }
        // cout<<"rm2 : "<<endl;
        // for (int l=0; l<c; l++)
        //     cout<<rm2[l]<<" ";
        // cout<<endl;

        if(c2>c)
            cout<<c<<endl;
        else
            cout<<c2<<endl;

    }
}