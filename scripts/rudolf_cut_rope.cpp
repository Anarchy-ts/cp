// This is the code for Rudolf and Cut the Rope problem

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int t;
    int n,a,b, c=0;
    cin>>t; //enter number of text cases
    

    for(int i=1; i<=t; i++)
    {   
        c=0;
        cin>>n; // enter number of nails
        
        for(int j=1; j<=n; j++)
        {   
            cin >> a >> b; // enter each nail height(a) and rope length(b)
            
            if (b<a)
                c++;

        }
        cout << c << endl; // c is the number of ropes to be cut
    }
    
    return 0;
}