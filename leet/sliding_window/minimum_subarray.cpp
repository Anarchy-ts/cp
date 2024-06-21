#include<bits/stdc++.h>
using namespace std;
// USE last=nums.size() for vector<int>

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    int target=7;
    int left=0,right=0,length=nums.size();
    int sub=length,sum=0,flag=0;
    while(right<length)
        {
            
            if(nums[left]==target)
            {
                sub=1;
                break;
            }

            sum = sum+nums[right];
            // cout<<nums[left]<<" & "<<nums[right]<<" sum: "<<sum<<endl;
            while(sum>=target)
            {
                flag = 1;
                // cout<<nums[left]<<" & "<<nums[right]<<endl;
                if(right-left+1<sub)
                {
                    sub = right-left+1;
                    // cout<<"Yes"<<endl;
                    // cout<<left<<" and "<<right<<endl;
                }
                sum -= nums[left];
                // cout<<"SUM: "<<sum<<endl;
                left++;
                
            }
            right++;
        }
        if(flag==0)
            cout<<0<<endl;
        else
            cout<<sub<<endl;
}