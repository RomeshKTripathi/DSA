// Given an array of Integers find NEXT GREATER (POSITION-WISE) closest and in right of it for every element

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void nextGreaterElement(vector<int> &v){
    stack<int> s;
    for(int i = v.size()-1;i>=0;i--){
        while(s.size() and s.top()<v[i])
            s.pop();
        int ng = s.size()?s.top():-1;
        s.push(v[i]);
        cout<<ng<<' ';
    }
}

int main(){
    vector<int> v = {5,15,10,8,6,12,9,18};
    nextGreaterElement(v);
}