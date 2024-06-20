#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string s,s2=""; cin>>s;
    int n = s.length();
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='b')
        {
            s[i]='#';
            for(int j=i-1; j>=0; j--)
            {   
                // cout<<i<<","<<j<<","<<" "<<s[j]<<(int)s[j]<<endl;
                if((int)s[j]>=97 && (int)s[j]<=122)
                {
                    s[j]='#';
                    break;
                }
            }
        }
        if(s[i]=='B')
        {
            s[i]='#';
            for(int j=i-1; j>=0; j--)
            {
                if((int)s[j]>=65 && (int)s[j]<=90)
                {
                    s[j]='#';
                    break;
                }
            }
        }
    }
    // cout<<s<<endl;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]!='#')
            s2=s2+s[i];
    }
    cout<<s2<<endl;

}
int main()
{   
    ll tt;
    cin>>tt;
    while(tt--) solve();
    return 0;
}