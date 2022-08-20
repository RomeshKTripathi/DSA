#include<iostream>
#include<unordered_map>

using namespace std;
int longestCommonSpan(int arr[],int arr1[],int n){
    for(int i = 0;i<n;i++){
        arr[i] = arr[i] - arr1[i];
    }
    unordered_map<int,int> m;
    int prefix = 0;
    int length = 0;
    for(int i = 0;i<n;i++){
       prefix+=arr[i];
       if(prefix == 0) length += 1;
       if(m.find(prefix) != m.end()){
        length = max(length,i-m[prefix]);
       }
       else m[prefix] = i;
    }
    return length;
}

int main(){
    int arr1[] = {0,1,0,0,0,0};
    int arr2[] = {1,0,1,0,0,1};
    cout<< longestCommonSpan(arr1,arr2,6);
}