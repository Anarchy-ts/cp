#include <bits/stdc++.h>
using namespace std;

int main() {
    string ransomNote = "bb", magazine="aabb";
    // unordered_map<char, int> mag;
    // for(char c : magazine){
    //     if(mag.find(c) != mag.end())
    //         mag[c] = mag[c] + 1;
    //     else    
    //         mag.insert({c,1});
    // }
    // // for(auto it = mag.begin(); it != mag.end(); it++) {
    // //     cout << it->first << " : " << it->second << endl;
    // // }
    // for(char c : ransomNote){
    //     if(mag.find(c) == mag.end()){
    //         cout<<"false"<<endl;
    //         return false;
    //     }
    //     if(mag[c]==0){
    //         cout<<"false"<<endl;
    //         return false;
    //     }
    //     mag[c] = mag[c]-1;
    // }
    // cout<<"true"<<endl;
    // return true;

    std::vector<int> alphabet(26, 0);
    for (char c : ransomNote) {
        cout<<"c: "<<c<<" "<<alphabet[c - 'a']<<endl;
            size_t i = magazine.find(c, alphabet[c - 'a']);
            cout<<"i : "<<i<<endl;
            if (i == std::string::npos){
                cout<<"false"<<endl;
                return false;
            }
            alphabet[c - 'a'] = i + 1;
        }
        cout<<"true"<<endl;
        return true;
}