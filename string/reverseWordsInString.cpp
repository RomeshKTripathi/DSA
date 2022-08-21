#include<iostream>
using namespace std;

void reverseString(string &str,int start,int end){
    while(start<end){
        swap(str[start],str[end]);
        start++;
        end--;
    }
}
void reverseWordsInString(string &str){
    int start = 0;//every word start from 0 index
    int end = 0; // assume end of first word
    for(int i = 0;i<str.size();i++){
        if(str[i+1] == ' ' or i+1 == str.size()){
            end = i; //update end of the word
            reverseString(str,start,end);
            start = end+2;//update start of new word after reversing previous word.
        }
    }
    reverseString(str,0,str.size()-1);

}

int main(){
    string s = "welcome to gfg";
    reverseWordsInString(s);
    cout<<s;
}