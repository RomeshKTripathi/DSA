#include<iostream>
using namespace std;
int permutationOfPattern(string &str,string &pat){
    int pat_hash =0;
    int arr[26] = {0};
    int pat_arr[26] = {0};
    int str_window_hash = 0;
    for(int i = 0;i<pat.size();i++){
        pat_hash += pat[i]-'a';
        str_window_hash += str[i] - 'a';
        arr[str[i]-'a']++;
        pat_arr[pat[i]-'a']++;
    }
    for(int i = pat.size();i<str.size();i++){
        if(pat_hash == str_window_hash){
            bool found = true;
            for(int j = 0;j<26;j++){
                if(pat_arr[j]!=arr[j])
                    found = !found;
            }
            if(found)cout<<i-pat.size()<<" ";
            
        }
        else{
            arr[str[i]-'a']++;
            arr[str[i-pat.size()]-'a']--;
            str_window_hash -= str[i-pat.size()]-'a';
            str_window_hash+= str[i]-'a';
        }
    }

}
int main(){
    string str = "abcbacaabadajalsdkfjldfjf";
    string pat = "jalsa";
    permutationOfPattern(str,pat);
}
