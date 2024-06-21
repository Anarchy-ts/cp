#include<bits/stdc++.h>
using namespace std;
// USE last=nums.size() for vector<int>

int main()
{
    int nums[]={2,3,0,1,4};
    int last=sizeof(nums) / sizeof(nums[0]),goal;
    goal = last-1;
    int count = 0;
    for(int i=0;i<goal;i++)
    {
        // cout<<"i: "<<i<<" & nums[i]: "<<nums[i]<<" goal:"<<nums[goal]<<endl;
        if(i+nums[i]>=goal)
        {
            
            goal = i;
            // cout<<"i : "<<i<<" goal:"<<goal<<endl;
            i=-1;
            cout<<i<<endl;
            count++;
        }
        // cout<<"i2 : "<<i<<" goal:"<<goal<<endl;
        if(goal==0)
            break;
    }
    cout<<count<<endl;

}