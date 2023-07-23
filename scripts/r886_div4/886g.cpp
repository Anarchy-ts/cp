#include<bits/stdc++.h>
using namespace std;

const double PI = 3.14159265358979323846;

int main()
{
    //cout<<"Enter number of test cases : ";
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        //cout<<"Enter number of points : ";
        int n;
        cin>>n;
        if (n<2 && n>2*(int)pow(10, 5))
        {
            //cout<<"n out of bounds \n";
            exit(0);
        }
        int x[n], y[n];
        for (int j=0; j<n; j++)
        {
            //cout<<"Enter x and y coords : ";
            cin>>x[j]>>y[j];
        }
        int c=0;
        for (int j=0; j<n; j++)
        {
            int a=x[j],b=y[j];

            for (int k=0; k<n; k++)
            {   
                // cout<<"a : "<<a<<" x : "<<x[k]<<endl;
                // cout<<"b : "<<b<<" y : "<<y[k]<<endl; 
                if (a==x[k] && b==y[k])
                {
                    //cout<<"skip"<<endl;
                    continue;
                }
                float tan_theta = float((y[k]-b))/float((x[k]-a));
                // cout<<y[k]<<" - "<<b<<" = "<<y[k]-b<<endl;
                // cout<<x[k]<<" - "<<a<<" = "<<x[k]-a<<endl;

                //cout<<"tan_theta : "<<tan_theta<<endl;
                // float rad = atan(tan_theta);
                // int deg = int(rad * (180.0 / PI));
                //cout<<"deg : "<<deg<<endl;
                if ( abs(tan_theta)==1.0 || isinf(abs(tan_theta)))
                    c++;
                //cout<<"c : "<<c<<endl;
            }
        }
        cout<<c<<endl;
    }
}