#include<iostream>
using namespace std;
bool isAnagram(string &s1,string &s2){
    int arr[26] = {0};
    for(int i = 0;i<s1.size();i++){
        arr[s1[i] -'a']++;
    }
    for(int i = 0;i<s2.size();i++){
        arr[s2[i]-'a']--;
    }
    for(int i = 0;i<26;i++){
        if(arr[i]!=0) return false;
    }
    return true;

}
    // if(s2.size() != s1.size()) return false;
    // int ar1[26] = {0};
    // int ar2[26] = {0};
    // for(int i = 0;i<s2.size();i++){
    //     ar1[s1[i]-'a']++;
    //     ar2[s2[i]-'a']++;
        
    // }
    // for(int i = 0;i<26;i++){
    //     if(ar1[i] != ar2[i]) return false;
    // }
    // return true;
// }

int main(){
    string s1 = "romesh";
    string s2 = "shmero";
    cout<<isAnagram(s2,s1);
}