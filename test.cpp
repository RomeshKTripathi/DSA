#include <iostream>
using namespace std;

int func(string &str){
    int count = 0;
    int letters = 0;
    for(int i = 0;i<str.size();i++){
        if(str[i] >= '0' and str[i]<='9') 
        count += str[i]-'0';
        if((str[i] >= 'a' and str[i]<='z')  or (str[i] <='A' and str[i] >= 'Z') )
            letters++;
    }
    return count/letters;
}

int main(){
    string str = "Hello6 9World 2,Nic8e D7ay";
    cout << func(str);
}
