#include<iostream>
#include<vector>
using namespace std;

vector<int> distinchPatternSearch(string &str,string &pattern){
    vector<int> res;
    for(int i = 0;i<= str.size()-pattern.size();i++){
        if(str[i] == pattern[0]){
            bool find = true;
            int temp_i = i;
            int temp_j = 0;
            for(;temp_j<pattern.size();temp_j++,temp_i++){
                if(str[temp_i] != pattern[temp_j]){
                find = false;
                break;
                }
            }
            if(find)
                res.push_back(i);
            i = temp_i - 1;
            
        }
    }
    return res;
}

int main(){
    string s = "abcdababcabcdd  ";
    string pat = "abcd";
    vector<int> res = distinchPatternSearch(s,pat);
    for(int s:res) cout<<s<<" ";
}