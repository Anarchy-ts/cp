#include<bits/stdc++.h>
using namespace std;

void swap(int* xp ,int* yp) 
{
    int temp = *xp;
    *xp=*yp;
    *yp=temp;
}

void bubbleSort(int arr[], int ari[], int n)
{
    int i,j;
    bool swapped;
    for (i=0; i<n-1; i++)
    {
        swapped = false;
        for (j=0; j<n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swap(&ari[j],&ari[j+1]);
                swapped=true;
            }
        }
        if (swapped == false)
            break;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0;i <size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int binarySearch(int arr[], int n, int target)
{
    int low=0, high=n-1, mid;
    while (low<=high)
    {
        mid = (low+high)/2;

        if (arr[mid] == target)
            return mid;
        
        else if (arr[mid] < target)
            low = mid+1;
        else
            high = mid-1;
    }

    return -1;
}

int main()
{
    cout<<"Enter Array Size : ";
    int N;
    cin>>N;
    int arr[N], ari[N];
    cout<<"Enter Array elements : ";
    for (int i=0; i<N; i++)
    {    
        cin>>arr[i];
        ari[i]=i;
    }
    
    bubbleSort(arr,ari,N);
    cout<<"Enter element to be located : ";
    int target;
    cin>>target;

    int index = binarySearch(arr,N,target);
    if (index != -1)
        cout<<target<<" is element number : "<<ari[index]+1<<" in the array"<<endl;
    else
        cout<<"Element is not present\n";
    return 0;
}