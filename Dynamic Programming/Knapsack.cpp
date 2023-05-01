#include<iostream>
#include<algorithm>
using namespace std;


int dp[5][9];

int knapsackTD(int wt[], int val[], int W, int n){
    // int dp[n+1][W+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 0;
            }
        }
    }
    // calculation of the table.

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            {
                if(wt[i-1] <= j){
                    dp[i][j] = max(
                                    val[i-1] + dp[i - 1][j - wt[i - 1]],
                                    dp[i-1][j]
                                );
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    return dp[n][W];



}

int knapsack(int wt[], int val[], int W, int n)
{
    if(n == 0 || W == 0)
    {
        // if we have no elements to choose OR knapsack has no space.
        return 0;
    }

    if(dp[n][W] != -1) return dp[n][W];

    if(W >= wt[n-1])
    {
        // if the item wait is feasiable
        return dp[n][W] = max(
            val[n-1] + knapsack(wt, val, W - wt[n-1], n - 1),
            knapsack(wt, val, W, n-1)
        );
    }
    else return dp[n][W] = knapsack(wt, val, W, n-1);
}

void print(){

    cout << endl << endl;
    for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 9; j++) cout << dp[i][j] << "  ";
        cout << endl;
    }
}

int main(){

    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 8;
    for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 9; j++)
        if(i == 0 || j == 0)
            dp[i][j] = 0;
    }

    print();
    cout << endl << endl;

    cout << knapsackTD(wt, val, W, 4);

    print();
   

 }