#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int rows = matrix.size(),cols = matrix[0].size();
    cout<<rows<<" X "<<cols<<" matrix"<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=i+1;j<cols;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    // cout<<"Step1 : "<<endl;
    // for(int i=0;i<rows;i++)
    // {
    //     for(int j=0;j<cols;j++)
    //     {
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols/2;j++)
        {
            swap(matrix[i][j],matrix[i][rows-j-1]);
        }
        
        
    }
    // cout<<"Step2 : "<<endl;
    // for(int i=0;i<rows;i++)
    // {
    //     for(int j=0;j<cols;j++)
    //     {
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}