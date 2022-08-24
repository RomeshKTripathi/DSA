#include<iostream>
#include<vector>
using namespace std;

vector<int> LPS(string str){
    vector<int> res;
    for(int i = 0;i<str.size();i++){
        int subStr = i-1;
        bool LPS_found = false;
        int count = 0;
        for(subStr;subStr>=0;subStr--){
            if(LPS_found) break;
            int firstSubStr = subStr;
            int lastSubStr = i;
            count = 0;
            while(firstSubStr >= 0 and str[firstSubStr] == str[lastSubStr]){
                count++;
                lastSubStr--;
                firstSubStr--;
            }
            if(firstSubStr < 0){
                LPS_found = true;
            }
        }
        res.push_back(count);
    }
    return res;
}
int main(){
    string str = "ababcba";
    vector<int> res = LPS(str);
    for(int x:res)cout<<x<<" ";
}