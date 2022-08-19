#include<iostream>
#include<unordered_set>
using namespace std;

bool haveSubarrayWithGivenSum(int Arr[],int n,int sum){
    int prefix_sum = 0;
    unordered_set<int> s;
    for(int i = 0;i<n;i++){
        prefix_sum += Arr[i];
        if(s.find(prefix_sum - sum)!=s.end() or prefix_sum == sum) return true;
        s.insert(prefix_sum);
    }
    return false;
}

int main(){
    int arr[] = { 5,8,2,3,7,4,9,-4,5,-8,12};
    if(haveSubarrayWithGivenSum(arr,11,5)) cout<<"Yes";
    else cout<<" No" ;
}