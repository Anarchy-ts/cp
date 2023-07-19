#include<bits/stdc++.h>
using namespace std;

int main(){
    int x = 4;
    int *p_x = &x;
    cout << "Address of x : " << &x <<endl;
    cout << "Value of p_x : " << p_x << endl;
    cout <<"Value of *p_x :" << *p_x <<endl;
    
    *p_x = 5;
    cout<<"X :" << x <<endl;
    cout <<"p_x + 1 :"<<p_x + 1 <<endl;

    int **p_p_x = &p_x;
    cout<< "Address of p_x :"<<&p_x<<endl;
    cout<< "Value of p_p_x :"<<p_p_x<<endl;
    cout<<"Value of *p_p_x :"<< *p_p_x<<endl;
    cout<< "Value of **p_p_x :"<< **p_p_x <<endl;    
    return 0;
}