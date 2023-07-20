#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i=0;i <size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    cout<<"Enter array size : ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for (int i=0 ; i<n ; i++)
        cin>>arr[i];
    insertionSort(arr, n);
    cout<<"Sorted array : \n";
    printArray(arr,n);
    return 0;
}