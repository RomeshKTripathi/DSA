#include<iostream>
#include<unordered_set>
using namespace std;

int longestConsecutiveSubsequence(int arr[],int n){
    unordered_set<int> s;
    for(int i = 0;i<n;i++){
        s.insert(arr[i]);
    }
    //insert all elements in set
    int sequence = 0;
    int curr_seq = 0;
    //now compute length of every consecutive subsequence

    for(int i = 0;i<n;i++){
        if(s.find(arr[i] - 1) == s.end()){ //checking if the sequence start from it or not.
            int temp = arr[i];
            while(true){                   //count length of subsequence starting from it.
                curr_seq++;
                temp++;
                if(s.find(temp) == s.end()) break; 
            }
            sequence = max(sequence,curr_seq); //update the main sequence length.
            curr_seq = 0;
        }
    }
    return sequence;
}

int main(){
    int arr[] = {1,9,3,4,2,10,13};
    cout<<longestConsecutiveSubsequence(arr,7);
}