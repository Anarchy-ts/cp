// This code is for the rudolf tic tac toe problem.

#include<bits/stdc++.h>
using namespace std;

/*int main()
{
    long int t;
    char matrix[3][3],row,col, diag1, diag2;
    int f2=0, f1=0, f3=0, f4=0;
    cin>>t;
    for (int l=1; l<=t; l++)
    {
        for(int i=0 ; i<=2; i++)
        {
            for(int j=0; j<=2; j++)
            {
                cin>>matrix[i][j];
            }
        }
        f2=0; f1=0;f4=0;f3=0;
        for(int i=0; i<=2; i++)
        {   
            f2=0; f1=0;f4=0;
            // cout<<i<<endl<<endl;
            for(int j=0; j<=2; j++)
            {
                // cout<<j<<endl;
                if  (matrix[i][j] == matrix[i][0] && matrix[i][j] != '.')
                {
                    row = matrix[i][j];
                    f1++;
                }
                
                if (matrix[j][i] == matrix [0][i] && matrix[j][i] != '.')
                {
                    col = matrix[j][i];
                    f2++;
                }

                if (i+j == 2)
                {
                    
                    if (matrix[i][j] == matrix[0][2] && matrix[i][j] != '.')
                        f3++;
                    diag1 = matrix[i][j];
                } 
                
                if (matrix[j][j] == matrix[0][0] && matrix[i][j] != '.')
                {
                    diag2 = matrix[j][j];
                    f4++;
                }
                
                if (f1==3)
                {
                    cout<<row<<endl;
                    break;
                }
                if (f2==3)
                {
                    cout<<col<<endl;
                    break;
                }
                if (f3==3)
                {
                    cout<<diag1<<endl;
                    break;
                }
                if (f4==3)
                {
                    cout<<diag2<<endl;
                    break;
                }
                //cout<< "f1 : "<<f1<<"\nf2 : "<<f2<<"\nf3 : "<<f3<<"\nf4 : "<<f4<<endl;
            }

            
            if (f1==3 || f2 ==3 || f3==3 || f4==3)
                break;         
        }
        if (f1!=3 && f2 !=3 && f3!=3 && f4!=3)
            cout<<"DRAW"<<endl;
    }
} */

int main ()
{
    long int t;
    char matrix[3][3],row,col, diag1, diag2;
    int f2=0, f1=0, f3=0, f4=0,f5=0,f6=0,f7=0,f8=0,f9=0,f10=0,f11=0,f12=0;
    bool flag =false;
    cin>>t;
    for (int l=1; l<=t; l++)
    {
        for(int i=0 ; i<=2; i++)
        {
            for(int j=0; j<=2; j++)
            {
                cin>>matrix[i][j];
            }
        }
        f1=0;f2=0;f4=0;f3=0,f5=0,f6=0,f7=0,f8=0,f9=0,f10=0,f11=0,f12=0,flag=false;

        for(int i=0;i<3;i++)
        {
            f1=0;f2=0;f3=0;f4=0,f5=0,f6=0,f7=0,f8=0,f9=0,f10=0,f11=0,f12=0;
            for(int j=0;j<3;j++)
            {
                if (matrix[i][j] == 'X')
                    f1++;
                if (matrix[i][j] == '+')
                    f2++;
                if (matrix[i][j] == 'O')
                    f9++;
                if (matrix[j][i] == 'X')
                    f3++;
                if (matrix[j][i] == '+')
                    f4++;
                if (matrix[j][i] == 'O')
                    f10++;
                if (matrix[j][j]=='X')
                    f5++;
                if (matrix[j][j]=='+')
                    f6++;
                if (matrix[j][j]=='O')
                    f11++;
                if (i+j == 2)
                {
                    if (matrix[i][j]=='X')
                        f7++;
                    if(matrix[i][j] == '+')
                        f8++;
                    if(matrix[i][j] == 'O')
                        f12++;
                }
                
            }
            if (f1==3 || f3==3 || f5==3 || f7==3)
                {   
                    cout<<'X'<<endl;
                    flag = true;
                    break;
                }
            else if (f2==3 || f4==3 || f6==3 || f8==3)
                {   
                    cout<<'+'<<endl; 
                    flag = true;
                    break;
                }
            else if (f9==3 || f10==3 || f11==3 || f12==3)
                {   
                    cout<<'O'<<endl;
                    flag = true;
                    break;
                }
        }
        if (flag == false)
            cout<<"DRAW"<<endl;
    }
}