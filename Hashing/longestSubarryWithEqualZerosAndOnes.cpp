#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubarrayWithEqualZerosAndOnes(int Arr[],int n){
    for(int i = 0;i<n;i++){
        if(Arr[i] == 0) Arr[i] = -1;
    }
    int prefix_sum = 0;
    int current_length = 0;
    unordered_map<int,int> m;
    for(int i = 0;i<n;i++){
        prefix_sum += Arr[i];
        if(prefix_sum == 0) 
            current_length++;
        if(m.find(prefix_sum)!= m.end()){
            current_length = max(current_length,i-m[prefix_sum]);
        }
        else 
            m.insert({prefix_sum,i});
    }
    return current_length;
}

int main(){
    int arr[] = {1,0,1,1,1,0,0};
    cout<<longestSubarrayWithEqualZerosAndOnes(arr,7);
}