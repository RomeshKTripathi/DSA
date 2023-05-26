#include<iostream>
#include<vector>
using namespace std;

bool subsetSum(int arr[], int n, int sum){
    
    bool t[n+1][sum+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            //if no element in array then we can not achive sum.
            if(i == 0)t[i][j] = false;
            // if sum is zero than we can achive in all the cases.
            if(j == 0)t[i][j] = true;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            // if current value can be add to subset sum.
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main(){
    int arr[] = {2,3,7,8,10};
    cout << subsetSum(arr, 5, 6);
}