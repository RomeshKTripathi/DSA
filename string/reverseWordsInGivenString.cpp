#include<iostream>
using namespace std;

void reverse(string &str, int start, int end){
    while(start < end){
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

void reverseWords(string &str){
    int start = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            reverse(str, start, i-1);
            start = i+1;
        }
    }
    reverse(str, start, str.length()-1);
    reverse(str, 0, str.length()-1);
}



int main(){
    string str = "Hello my name is romesh Kumar tripathi";
    reverseWords(str);
    cout << str;
}