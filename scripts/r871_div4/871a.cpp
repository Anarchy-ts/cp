// Codeforces Round 871 Div 4. 

// Check number of mismatches between two words

#include<bits/stdc++.h>
using namespace std;

int main()
{   
    //cout<<"Enter number of test cases : ";
    int t;
    cin>>t;
    
    string check = "codeforces";
    for (int j=1; j<=t; j++)
    {   
        //cout<<"Enter string of length 10 : ";
        // char word[11];
        // for (int i=0; i<11; i++)
        //     cin>>word[i];

        // char check[11]={'c','o','d','e','f','o','r','c','e','s','\0'};

        string word;
        cin>>word;

        if (word.length() != 10)
        {
            //cout<<"Input can only be a 10 lettered word."<<endl;
            exit(0);
        }
        int c=0;
        for (int i=0; i<word.length(); i++)
        {
            if (word[i] != check[i])
                c++;
        }
        cout<<c<<endl;
        //cout<<"Number of mismatches : "<<c<<endl;
    }

    return 0;
}