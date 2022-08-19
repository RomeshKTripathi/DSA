#include<iostream>
#include<unordered_map>
using namespace std;
int longestSubarryWithGivenSum(int Arr[],int n,int sum){
    unordered_map<int,int> m;
    int prefix_sum = 0;
    int current_subarray_size = 0;
    for(int i = 0;i<n;i++){
        prefix_sum += Arr[i];
        if(prefix_sum == sum) current_subarray_size += 1;

        if(m.find(prefix_sum - sum)!=m.end())
            current_subarray_size = max(current_subarray_size,i - m[prefix_sum - sum]);
        else
            m.insert({prefix_sum,i});
    }
    return current_subarray_size;
}

int main(){
    int arr[] = {8,3,1,5,-6,8,2,2};
    cout<<longestSubarryWithGivenSum(arr,8,4);
}