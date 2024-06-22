#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "egg", t="add";
    unordered_map<char, char> mag,mag2;
    for(int i=0;i<s.length();i++){
        if(mag.find(s[i]) != mag.end() || mag2.find(t[i]) != mag2.end()){
            // cout<<"mag1: "<<mag[s[i]]<<" "<<t[i]<<endl;
            // cout<<"mag2: "<<mag[t[i]]<<" "<<s[i]<<endl;
            if(mag[s[i]]!=t[i] || mag2[t[i]]!=s[i]){
                cout<<"false"<<endl;
                return false;
            }
        }
        else{
            mag.insert({s[i],t[i]});
            mag2.insert({t[i],s[i]});
        }    
            
    }
    for(auto it = mag.begin(); it != mag.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }
    cout<<"true"<<endl;
    return true;
    
    
}