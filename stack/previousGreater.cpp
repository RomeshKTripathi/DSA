#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> previousGreater(vector<int> &v){
    stack<int> s;
    vector<int> res;
    for(int i = 0;i<v.size();i++){
        while(s.size() and s.top()<v[i])
            s.pop();
        if(s.size() == 0 ){
            res.push_back(-1);
            s.push(v[i]);
        }else{
            res.push_back(s.top());
            s.push(v[i]);
        }
    }
    return res;
}
int main(){
    vector<int> v = {5,4,3,2,1}; 
    vector<int> res = previousGreater(v);
    for(int x:res)cout<<x<<" ";
}