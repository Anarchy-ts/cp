// Codeforces Div 3 round 883 . Question C - Rudolf and the Another Competition.
// This code needs work, as it is exceeding time limit on codeforces.
#include<bits/stdc++.h>
using namespace std;

void swap(long int* xp ,long int* yp) 
{
    int temp = *xp;
    *xp=*yp;
    *yp=temp;
}

void bubbleSort(long int arr[], int n)
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
                swapped=true;
            }
        }
        if (swapped == false)
            break;
    }
}

void bubbleSort2(long int arr[], long int ari[], int n)
{
    int i,j;
    bool swapped;
    for (i=0; i<n-1; i++)
    {
        swapped = false;
        for (j=0; j<n-i-1; j++)
        {
            if (arr[j] < arr[j+1])
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

int main()
{
    int test;
    long int h,n,m;
    //cout<<"Enter number of test cases : ";
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        //cout<<"Enter number of participants, problems and duration : ";
        cin>>n>>m>>h;
        long int time[m], penal[n]={0}, points[n]={0}, points2[n]={0}, penal2[n]={0};
        for (int j=0; j<n; j++)
        {
            for (long int l=0; l<m; l++)
            {
                cin>>time[l];
            }
            //cout<<endl;

            bubbleSort(time,m);
       
            long long int sum2[m];
            
            sum2[0]=time[0];
            for (long int l=1; l<m; l++)
            {
                sum2[l]=sum2[l-1]+time[l];
            }

            // for (long int l=0; l<m; l++)
            // {
            //     cout<<time[l]<<" ";
            // }
            // cout<<endl;
            // for (long int l=0; l<m; l++)
            // {
                
            //     cout<<sum2[l]<<" ";
            // }
            // cout<<endl;

            long long int sum=0,sum3 = 0, sumarr[m]={0};
            for (long int l=0; l<m; l++)
            {
                sum=sum+time[l];
            
                if(sum>h)
                    break;
                sum3=0;
                for (int p=0; p<=l; p++)
                {   
                    //cout<<"l: "<<l<<"; p : "<<p<<"; sum2[p]: "<<sum2[p]<<"; ";
                    sum3=sum3+sum2[p];
                    //cout<<"sum3: "<<sum3<<"\n";
                }    
                points[j] = l+1;
                if(l==0)
                    penal[j]=sum;
                else
                    penal[j] = sum3;
            }
        }     
        // cout<<"Results : \n";
        // for (int j=0; j<n ;j++)
        //     cout<<points[j]<<" "<<penal[j]<<endl;

        int rud_pt = points[0], rudpen=penal[0];
        bubbleSort2(points, penal, n);
        for (int k = 0; k < n - 1; k++) {
        for (int j = 0; j < n - k-1 ; j++) {
            if (points[j] == points[j + 1]) {
                if (penal[j] > penal[j + 1]) {
                    std::swap(penal[j], penal[j + 1]);
                }
            }
        }
    }
        // cout<<"Arranged score : "<<endl;
        // for (int j=0; j<n ;j++)
        // {
        //     cout<<points[j]<<" "<<penal[j]<<endl;
        // } 
        int pos=0;
        for (int j=0; j<n; j++)
        {
            if(points[j]==rud_pt && penal[j]==rudpen)
            {    
                pos=j+1;
                break;
            }
        }
        cout<<pos<<endl;;
    }
}