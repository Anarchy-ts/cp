#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1;
    getline(cin, str1);
    /* 
    A string input always stops as soon as a space is encountered.
    getline function can be used instead to get the exact input inclusive 
    of spaces.
    */

    cout<< "Input : " << str1 <<"\nString size : " << str1.size()<<endl;
    //str1.size() gives us the size of string

    //REVERSING A STRING :
    string str;
    cout<<"Enter a new string : \n";
    cin>> str ;
    string str_rev="";

    for(int i=str.size() - 1; i>=0; i--){
        //str_rev = str_rev + str[i];   <-- this process is not recommended as we are adding characters to a string here; also there will be an issue of time complexity 
        str_rev.push_back(str[i]);//using this function is preferred to that
    }
    cout<< str_rev;
}
