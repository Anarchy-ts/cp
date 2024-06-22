#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '[' || s[i] == '{' || s[i] == '('){
                stk.push(s[i]);
            }
            else{
                if(!stk.empty()){
                    if((stk.top() == '(' && s[i] == ')') || (stk.top() == '[' && s[i] == ']') || (stk.top() == '{' && s[i] == '}' )) 
                        stk.pop();
                    else 
                        return false;
                }
                else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
int main(){
    cout<<Solution().isValid("(}");
    return 0;
}