#include<iostream>
using namespace std;


int pow(int x,int y){
    if(y == 0) return 1;
    int val = pow(x, y/2);
    if(y % 2 == 1) return val * val * x;
    return val * val;
}



int rabinKarpSearch(string &str,string &pat){
    return -1;
}

int main(){
    string str = "abaababaccabacabac";
    string pattern ="abcb";
    // cout << rabinKarpSearch(str,pattern);
    // cout << pow(2, 3);
}