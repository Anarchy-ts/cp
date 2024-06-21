#include<bits/stdc++.h>
using namespace std;
// USE last=nums.size() for vector<int>

int main()
{
    int nums[]={1,1,2};
    int k=0, last=sizeof(nums) / sizeof(nums[0])-1,left=1,right=1;   
    while(left<=right && left<=last && right<=last)
    {
        if(nums[right]==nums[right-1])
        {
            right = right+1;
            
        }
        else
        {
            k++;
            nums[left] = nums[right];
        //    swap(nums[left],nums[right]); 
            left = left+1;
            right = right+1;
        }    
    } 
    // cout<<last<<endl;
    // cout<<k<<endl;
    // k = last-k;
    cout<<"nums : ";
    for(int i=0;i<=last;i++)
        cout<<nums[i]<<",";
    cout<<endl;

    // cout<<"k : "<<k+1<<endl;
    return k+1;
}

// //better way:
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int ans = 0;
//         int prev = nums[0];
//         int j = 0;
//         for(int i = 1;i < nums.size();i++){
//             if(nums[i] > prev){
//                 j++;
//                 swap(nums[i],nums[j]);
                
//                 prev = nums[j];
//             }  
//         }
//         return j+1;
//     }
// };