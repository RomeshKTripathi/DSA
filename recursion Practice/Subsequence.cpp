#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// All the subsequences of the sequence
class Sequence{

public:

    vector<vector<int>> ans;


    void clear(){
        this->ans.clear();
    }

    

    void subsequences(vector<int> &seq, int index = 0, vector<int> temp = {}){
        if(index == seq.size()) 
        {
            ans.push_back(temp);
            return ;   
        }

        // Consider the current element in my subsequence
        temp.push_back(seq[index]);

        subsequences(seq, index+1, temp);

        // Not consider the current element in my subsequence
        temp.pop_back();

        subsequences(seq, index+1, temp);
    }

    // Compute Subsequences of sum k

    void kSumSubsequences(vector<int> &seq, int k, int curr_sum = 0, vector<int> temp = {}, int index = 0){
        if(curr_sum == k){
            ans.push_back(temp);
            return;
        }
        if(index == seq.size()) return;


        // Consider the current element
        temp.push_back(seq[index]);
        kSumSubsequences(seq, k, curr_sum+seq[index], temp, index+1);
        // Not consider 
        temp.pop_back();
        kSumSubsequences(seq, k, curr_sum, temp, index+1);
    }

    int findGreatest(vector<int> &x){
        int index = 0;
        int size = x.size();
        for(int i = 0; i<size; i++){
            index = (x[i] > x[index])?i:index;
        }
        return index;
    }

    int guitar(int N, vector<int> &x){
        int ans = 0;
        sort(x.begin(), x.end());
        reverse(x.begin(), x.end());
        int j = 0;
        for(int i = 0; i<N; i++){
            ans += x[i] * (N-i);
        }
        return ans;
    }


};



int main(){
    Sequence *obj = new Sequence();
    vector<int> test = {9,2,5,10,6};
    cout << obj->guitar(5, test);

    }