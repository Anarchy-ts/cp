#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        char input[8][8];
        //cout<<"Give input : \n";
        for (int j=0; j<8; j++)
        {
            for (int k=0; k<8; k++)
            {
                cin>>input[j][k];
            }
        }
        string word = "";
        for (int j=0; j<8; j++)
        {
            for (int k=0; k<8; k++)
            {
                if (input[k][j] != '.')
                {
                    word = word + input[k][j]; 
                }
            }
        }
        cout<<word<<endl;
    }
}