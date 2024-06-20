#include<bits/stdc++.h>
using namespace std;
// USE last=nums.size() for vector<int>

int main()
{
    int nums[]={1,2,3,4,5,6,7};
    int k=3, last=sizeof(nums) / sizeof(nums[0]);
    // cout<<last<<endl;
    int l=0,r=last-1;
    k = k%(last);
    while(l<r)
    {
        swap(nums[l++],nums[r--]);
    }
    cout<<k<<endl;
    l=0;
    r=k-1;
    while(l<r)
    {
        swap(nums[l++],nums[r--]);
    }
    l=k;
    r=last-1;
    while(l<r)
    {
        swap(nums[l++],nums[r--]);
    }
    
    // cout<<"nums : ";
    // for(int i=0;i<last;i++)
    //     cout<<nums[i]<<" ";
    // cout<<endl;

    return 0;
}