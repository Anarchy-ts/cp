#include<bits/stdc++.h>
using namespace std;
// USE last=nums.size() for vector<int>

int main()
{
    int nums[]={1,2,4,2,5,7,2,4,9,0,9};
    int last=sizeof(nums) / sizeof(nums[0]);
    int l=0,r=1,diff,diff1=nums[r]-nums[l];
    while(r<last)
    {
        diff = nums[r]-nums[l];
        cout<<"nums[l]:"<<nums[l]<<" nums[r]:"<<nums[r]<<endl;
        cout<<"diff:"<<diff<<endl;
        if(diff>0){
            // cout<<"nums[r]:"<<nums[r]<<" nums[l]:"<<nums[l]<<endl;
            if(diff>diff1){
                diff1=diff;
                // cout<<"diff1:"<<diff1<<endl;
            }
        }
        else
        {
            l=r;
        }
        r++;
        // if(r==last){
        //     r=l+2;
        //     l++;
        // }
        cout<<l<<" "<<r<<endl;
        
    }
    if(diff1<0){
        cout<<0<<endl;
        return 0;
    }
    else{
        cout<<diff1<<endl;
        return diff1;
    }
    // // cout<<last<<endl;
    // int small = nums[0],small_pos=0;
    // bool decreaseflag = true;
    // for(int i=0;i<last-1;i++)
    // {
    //     if(nums[i+1]>nums[i])
    //     {
    //         // cout<<nums[i+1]<<" and "<<nums[i]<<endl;
    //         decreaseflag = false;
    //     }
    // }
    // // cout<<decreaseflag<<endl;
    // for(int i=1;i<last-1;i++)
    // {
    //     if(nums[i]<small)
    //     {
    //         small = nums[i];
    //         small_pos = i;
    //     }
    // }
    // cout<<"small : "<<small<<endl;
    // if(decreaseflag==true){
    //     cout<<0<<endl;
    //     return 0;
    // } 
    // else
    // {
    //     int large = nums[small_pos+1],large_pos = small_pos+1;
    //     for(int i=small_pos+1;i<last;i++)
    //     {
    //         if(nums[i]>large)
    //         {
    //             large = nums[i];
    //             large_pos = i;
    //         }
    //     }
    //     cout<<"large : "<<large<<endl;
    //     cout<<large-small<<endl;
    //     return (large-small);
    // }
}