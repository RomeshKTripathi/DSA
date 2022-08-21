#include<iostream>
#include<vector>
using namespace std;

bool checkPatternFrom(string &s,string &pattern,int startIndex){
    for(int i = startIndex, j = 0;j<pattern.size();j++,i++){
        if(pattern[j]!=s[i]) return false;
    }
    return true;
}
vector<int> patternMatch(string &str,string &pattern){
    vector<int> res;
    for(int i =0;i<=str.size()-pattern.size();i++){
        if(str[i] == pattern[0]){
            if(checkPatternFrom(str,pattern,i))
                res.push_back(i);
        }
    }
    return res;
}

int main(){
    string s = "AAAAA";
    string pat = "AAA";
    vector<int> res = patternMatch(s,pat);
    for(int x:res) cout<<x<<" ";
}