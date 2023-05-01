#include<iostream>
#include<vector>
using namespace std;

void printTable(vector<vector<bool>> arr, int rows, int cols){
    cout <<"\n\n\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout  << (arr[i][j]?'T':'0' )<< "  ";
        }
        cout << endl;
    }

    cout <<"\n\n\n";
}


int subsetsum(int arr[], int n, int sum){
    vector<vector<bool>> t(n+1, vector<bool>(sum+1));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j<= sum; j++){
            if(i == 0) t[i][j] = false;
            if(j == 0) t[i][j] = true;
        }
    }
    printTable(t, n+1, sum+1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i - 1] <= j){
                t[i][j] = t[i - 1][j - arr[i-1]] || t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    printTable(t, n+1, sum+1);
    return t[n][sum];

}

int main(){
    int arr[] = {2, 3, 7, 8, 10};
    cout << subsetsum(arr, 5, 11);
}