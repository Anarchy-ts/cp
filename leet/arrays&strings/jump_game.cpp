#include<bits/stdc++.h>
using namespace std;
// USE last=nums.size() for vector<int>

int main()
{
    int nums[]={3,2,1,0,4};
    int last=sizeof(nums) / sizeof(nums[0]),goal;
    goal = last-1;
    for(int i=last-1;i>=0;i--)
    {
        // cout<<i<<" "<<nums[i]<<endl;
        if(i+nums[i]>=goal)
            goal = i;
        // cout<<goal<<" , "<<nums[goal]<<endl;
    }
    if(goal==0){
        cout<<"true"<<endl;
        return true;
    }
    else{
        cout<<"false"<<endl;
        return false;
    }
}