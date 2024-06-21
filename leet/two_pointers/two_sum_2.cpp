#include<bits/stdc++.h>
using namespace std;
// USE last=nums.size() for vector<int>

int main()
{
    int numbers[]={2,7,11,15},target=9;
    int left=0,right=sizeof(numbers)/sizeof(numbers[0])-1;
    int pair[2];
    bool flag = false;
    while(left<right)
    {
        if(numbers[left]+numbers[right]>target)
            right--;
        if(numbers[left]+numbers[right]<target)
            left++;
        if(numbers[left]+numbers[right]==target)
        {
            flag = true;
            pair[0] = left;
            pair[1] = right;
            break;
        }
    }
    if(flag==true)
        cout<<pair[0]<<" & "<<pair[1]<<endl;
    else    
        cout<<"false"<<endl;
}