#include<iostream>
#include<vector>
using namespace std;
vector<int> LPS(string &str){
    vector<int> res(str.length());
    res[0] = 0;
    int len = 0;
    int i = 1;
    while(i<str.size()){
        if(str[i] == str[len]){
            len++;
            res[i] = len;
            i++;
        }
        else{
            if(len == 0){
                res[i] = 0;
                i++;
            }
            else{
                len = res[len-1];
            }
        }
    }
    return res;
}

int main(){
    string pat = "abaccabacabab";
    vector<int> lps = LPS(pat);
    for(int i:lps)cout<<i<<" ";
}