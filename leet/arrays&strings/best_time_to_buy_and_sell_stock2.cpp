#include<bits/stdc++.h>
using namespace std;
// USE last=nums.size() for vector<int>

int main()
{
    int nums[]={1,2,4,2,5,7,2,4,9,0,9};
    int last=sizeof(nums) / sizeof(nums[0]);
    int profit = 0;
    for(int i=1;i<last;i++)
    {
        if(prices[i]>prices[i-1])
            profit += prices[i]-prices[i-1]

    }
    return profit;
}