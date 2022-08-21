// You given two strings  s1 and s2
//now check if the s2 is subsequence of s1 or not.

#include<iostream>
using namespace std;
bool isSubsequence(string &s1,string &s2){
    int i=0,j=0;
    for(; i<s1.size() and j<s2.size();){
        if(s1[i] == s2[j]){
            i++;
            j++;
        }
        else i++;
    }

    return j == s2.size();
}

int main(){
    string s1 = "GEEKSFORGEEKS";
    string s2 = "KG";
    cout<<isSubsequence(s1,s2);
}