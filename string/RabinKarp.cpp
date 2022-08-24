#include<iostream>
using namespace std;
int pow(int x,int y){
    int res = 1;
    while(y--){
        res *=x;
        
    }
    return res;
}
int rabinKarpSearch(string &str,string &pat){
    int pat_hash = 0;//pattern hash 
    int w_hash = 0;//firsh window hash
    int d = 5;
    for(int i = 0;i<pat.size();i++){
        pat_hash += pat[i] * pow(d,pat.size()-i-1);
        w_hash += str[i] * pow(d,pat.size()-i-1);
    }
    for(int i = 0;i<=str.size()-pat.size();i++){
        if(pat_hash == w_hash){
            bool match = true;
            for(int j = i;j<i+pat.size();j++){
                if(pat[j-i] != str[j]) match = false;
            } 
            if(match) cout<<i<<" ";
        }
        w_hash = d * (w_hash - str[i]*pow(d,pat.size()-1))+str[i+pat.size()];
    }
}

int main(){
    string str ="abbbbbaabbaabaabbbaaaaabbabbbabbbbbaababaabbaabbbbbababaababbbbaaabbbbabaabaaaabbbbabbbaabbbaabbaaabaabaaaaaaaa";
    string pattern ="baba";
    rabinKarpSearch(str,pattern);
}