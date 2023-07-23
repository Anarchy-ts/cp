#include<bits/stdc++.h>
using namespace std;

void swap1(long int* xp ,long int* yp) 
{
    int temp = *xp;
    *xp=*yp;
    *yp=temp;
}

void swap2(int* xp ,int* yp) 
{
    int temp = *xp;
    *xp=*yp;
    *yp=temp;
}

void bubbleSort(long int arr[], int ari[],long int n)
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
                swap1(&arr[j],&arr[j+1]);
                swap2(&ari[j],&ari[j+1]);
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

int main()
{
    cout<<"Enter number of test cases : ";
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        cout<<"Enter the number of books : ";
        long int n;
        cin>>n;
        long int time[n];
        int skill[n];
        for (int j=0; j<n; j++)
        {
            cout<<"Enter time and skill numbers : ";
            cin>>time[j]>>skill[j];
        }

        bubbleSort(time,skill,n);
        long int sumtim=0, sumski=0;
        for (int j=0; j<n; j++)
        {   
            if (skill[j]==0)
                continue;
            sumtim=sumtim+time[j];
        }    
    }
}