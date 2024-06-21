#include<bits/stdc++.h>
using namespace std;
// USE last=nums.size() for vector<int>

int main()
{
    string s = "0P";
    
    int left=0,right=s.length()-1;
    char s2[right+1];
    // char test='9';
    // cout<<(int)test<<endl;
    for(int i=0;i<=right;i++)
    {
        if(s[i]!=' ')
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s2[left++]=s[i]+32;
            }
            if((s[i]>='a' && s[i]<='z')||(s[i]>=48&&s[i]<=57))
            {
                s2[left++]=s[i];
            }
        }
    }
    // cout<<s2<<endl;
    right=left-1;
    left = 0;
    for(int i=0;i<=right;i++)
        cout<<s2[i];
    cout<<endl;
    bool flag=true;
    while(left<=right)
    {
        // cout<<"left: "<<s2[left]<<" & right: "<<s2[right]<<endl;
        if(s2[left++]!=s2[right--])
        {
            flag = false;
            break;
        }
    }
    if(flag==true)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}