#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int target)
{
    for (int i=0; i<n; i++)
        if (arr[i] == target)
            return i;

    return -1;
}

int main()
{
    cout<<"Enter Array Size : ";
    int N;
    cin>>N;
    int arr[N];
    cout<<"Enter Array elements : ";
    for (int i=0; i<N; i++)
        cin>>arr[i];
    
    cout<<"Enter element to be located : ";
    int target;
    cin>>target;

    int index = linearSearch(arr,N,target);
    if (index != -1)
        cout<<target<<" is element number : "<<index+1<<" in the array"<<endl;
    else
        cout<<"Element is not present\n";
    return 0;
}