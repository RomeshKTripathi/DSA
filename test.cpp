#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

long long count_pairs(int N, vector<int> A, int X){
    unordered_map<int, int> mp;
    int count = 0;
    for(int i = 0;i<A.size();i++){
        if(mp.find(A[i]) == mp.end())
            mp[A[i]] = i;
        else{
            if(mp[A[i]] < i and ((mp[A[i]]+1)*(i+1))%X == 0)
                count++;           
        }
    }
}

int main(){
    cout<<count_pairs(3,{2,2,2},2);
}