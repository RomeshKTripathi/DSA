//Merge two sorted arrays in O(1) space
#include<iostream>
#include<vector>
using namespace std;

 void merge(vector<int>& A,vector<int> &B){
    int i = 0;
    int j = 0;
    while(i<A.size() and j<B.size()){
        if(A[i] > B[j]){
            swap(A[i],B[j]);
            //insert the swapped element in its correct position.
            int temp = B[j];
            int k = j;

            while(k+1 < B.size() and B[k+1]<temp){
                B[k] = B[k+1];
                k++;
            }
            B[k] = temp;
        }
        //Increment only i because we want first element of B as next of 1's last.
        i++;
        
    }
 }

 int main(){
    vector<int> a = {1,5,6,8,9};
    vector<int> b = {2,4,7,10};
    merge(a,b);
    for(int x:a)cout<<x<<" ";
    for(int x:b)cout<<x<<" ";

 }