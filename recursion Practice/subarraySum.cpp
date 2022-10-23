#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Kthlargest(int N, int K, vector<int> A){
   
    
    vector<int> ans; 
    int sum = 0;
    for(int i = 0; i<N; i++){
        sum = 0;
        for(int j = i; j<A.size(); j++){
            sum += A[j];
            ans.push_back(sum);
        } 
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    return ans[K-1];
}


int main(){
    vector<int> a = {5};
    cout << Kthlargest(1,1, a);
}