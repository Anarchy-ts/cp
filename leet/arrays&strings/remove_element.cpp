#include<bits/stdc++.h>
using namespace std;
// USE last=nums.size() for vector<int>
// This method is O(N);
int main()
{
    int nums[]={0,1,2,2,3,0,4,2}, val = 2;
    int k=0, last=sizeof(nums) / sizeof(nums[0]);
        for(int i=0;i<last;)
        {
            // cout<<last-1<<endl;
            if(nums[last-1]==val)
            {
                // cout<<"HI1"<<endl;
                last = last-1;
            }
            else
            {
                // cout<<"HI2"<<endl;
                if(nums[i]==val)
                {
                    // k++;
                    nums[i]=nums[last-1];
                    nums[last-1]=val;
                    
                }
                if(nums[i]!=val)
                {
                   k++;
                //    cout<<"nums[i] : "<<nums[i]<<endl;
                }
                i++;
            }
        }
        // last=sizeof(nums) / sizeof(nums[0]);
        // cout<<"nums : ";
        // for(int i=0;i<last;i++)
        //     cout<<nums[i]<<",";
        // cout<<endl;

        cout<<"k : "<<k<<endl;
        return k;
        
    
}

// Better way : 
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int k = nums.size()-1;
//         int count = 0;
//         int i = 0;

//         while(i <= k){
//             if(nums[i] == val){
//                 count++;
//                 swap(nums[i], nums[k--]);
//             }
//             else{
//                 i++;
//             }
//         }

//         return (nums.size()-count);
//     }
// };