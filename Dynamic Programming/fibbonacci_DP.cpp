#include<iostream>
using namespace std;

class Solution{
    private:
    int dp[1000];
    public:
    Solution(){
        for(int i = 0; i<1000; i++) dp[i] = -1;
    }
    int fibbonacci(int n){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = fibbonacci(n-1)+ fibbonacci(n-2);
        return dp[n];
    }

    int nthFibbonacci(int n){
        if(n <= 1) return n;
        int first = 1;
        int second = 1;
        
        for(int i = 2; i<= n; i++){
            int current = first+ second;
            first = second;
            second = current;
        }
        return second;
    }
};

int main(){
    Solution *obj = new Solution();
    cout << obj->nthFibbonacci(2);
}