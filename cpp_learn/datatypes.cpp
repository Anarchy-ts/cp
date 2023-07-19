#include<bits/stdc++.h>
using namespace std;

int main(){
    //char, int, float, double, bool
    // long int or long, long long int or long long 
    char c ='a';
    int a = 3;
    double b = 3.5;
    a = 4.5;
    bool d = 123; /*all numbers other than 0 are considered true
    in boolean. true = 1 ;  hence cout<<d gives 1 even if bool d =123.
    Only if bool d = 0; then only it will print 0;*/
    cout<<c<<" "<<a<<" "<< b << " " << d <<endl;
    return 0;
}