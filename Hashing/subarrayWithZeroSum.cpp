#include<iostream>
#include<unordered_set>
using namespace std;
bool haveSubarrayWithZeroSum(int Arr[],int n){
    unordered_set<int> s;
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum+=Arr[i];
        if(s.find(sum)!=s.end() or sum == 0) return true;
        s.insert(sum);
    }
    return false;
}

int main(){
    int arr[] = {7,6,-9,3,4,1,7,8};
    if(haveSubarrayWithZeroSum(arr,8))
        cout<<"Yes";
    else cout<<" No";
    return 0;
}