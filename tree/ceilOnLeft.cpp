#include<iostream>
#include<set>
#include<vector>
using namespace std;
vector<int> ceilOnLeft(vector<int> &v){
    vector<int> res;
    set<int> s;
    for( auto val : v ){
        if(s.upper_bound(val) == s.end()){
            res.push_back(-1);
        }else{
            int x = *(s.upper_bound(val));
            res.push_back(x);
        }
        s.insert(val);
    }
    return res;
}

int main(){
    vector<int> values = {10,9,8,6,5,4};
    vector<int> res = ceilOnLeft(values);
    for(auto x : res) cout << x << "   ";
}