#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int largestRectangle(const vector<int> &histogram){
    stack<int> s;
    int curr = 0;
    int res = 0;
    for(int i = 0;i<histogram.size();i++){
        while(s.size() and histogram[s.top()] >= histogram[i]){
            int tp = s.top();
            s.pop();
            curr = histogram[tp]*((s.size())?(i-s.top()-1):i);
            res = max(res,curr);
        }
            s.push(i);
    }
    while(s.size()){
        int tp = s.top();
        s.pop();
        curr = histogram[tp]*( (s.size())?histogram.size()-s.top()-1:histogram.size() );
        res = max(res,curr);
    }
    return res;
}

int largestSubmatrixWithAllOnes(vector<vector<int>> matrix){
    int res  = 0;
    for(int i = 0;i<matrix.size();i++){
        if(i>0){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        res = max(res,largestRectangle(matrix[i]));
    }
    return res;
}


int main(){
    vector<vector<int>> matrix = {
                                    {0,1,1,0},
                                    {1,1,1,1},
                                    {1,1,1,1},
                                    {1,1,1,0}        
                                 };
    cout<<largestSubmatrixWithAllOnes(matrix);
}