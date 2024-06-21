#include<bits/stdc++.h>
using namespace std;
// USE last=nums.size() for vector<int>

int main()
{
    vector<int> numbers = {-1,0,1,2,-1,-4};
    int target=0;
    int left=0,right=numbers.size()-1;
    int first;
    sort(numbers.begin(),numbers.end());
    cout << "Sorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    for(int i=0;i<=right;i++)
    {
        if(i>0&&numbers[i]==numbers[i-1])
            continue;
        first = numbers[i];
        left = i+1;
        right = numbers.size()-1;
        while(left<right)
        {
            // cout<<first<<" & "<<numbers[left]<<" & "<<numbers[right]<<endl;
            // cout<<left<<" & "<<right<<";"<<endl;
            if(first+numbers[left]+numbers[right]>target)
                right--;
            else if(first+numbers[left]+numbers[right]<target)
                left++;
            else
            {
                cout<<"HI "<<first<<" & "<<numbers[left]<<" & "<<numbers[right]<<endl;
                left++;
                while(numbers[left]==numbers[left-1]&&left<right)
                    left++;
                // break;
            }
        }
    }
}