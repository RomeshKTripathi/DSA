#include<iostream>
using namespace std;

int leftmostRepeatingCharacter(string &s){
    int arr[26] = {0};
    for(int i = 0;i<s.size();i++){
        if(arr[s[i]-'a'] != 0) return i;
        else arr[s[i]-'a']++;
    }
    return -1;//if no repeating character exists.
}


int main(){
    string s = "abcbc";
    cout<<leftmostRepeatingCharacter(s);
}