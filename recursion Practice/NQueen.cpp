#include <iostream>
#include <vector>
using namespace std;

class Solution{
    vector<int> upper_left;
    vector<int> upper;
    vector<int> upper_right;
public:
    bool solve(vector<string> &board, int n, int row = 0){
        if(row == n){
            // we found the first solution
            return true;
        }
        for(int col = 0; col < n; col ++){
            int danger = 0;
            danger += upper_left[(n-row-1) + col];
            danger += upper[col];
            danger += upper_right[row+col];

            if(danger == 0){

                board[row][col] = 'Q';
                upper_left[(n-row-1) + col] = 1;
                upper[col] = 1;
                upper_right[row+col] = 1;
                if(solve(board, n, row+1)){
                    return true;
                }
                upper_left[(n-row-1) + col] = 0;
                upper[col] = 0;
                upper_right[row+col] = 0;
                board[row][col] = '.';
            }
        }
        return false;
    }

    vector<string> NQueen(int n){
        upper_left.resize(n*2 -1);
        upper_right.resize(n*2 - 1);
        upper.resize(n);
        string row = "" ;
        vector<string> board;
        for(int i = 0; i<n; i++) row += '.';
        for(int i = 0; i<n; i++) board.push_back(row);

        solve(board, n);
        return board;
    }

};

int main(){
    vector<string> board;
    Solution *obj = new Solution();

    board = obj->NQueen(5);
    for(auto row : board)
        {
            for(auto col : row){
                cout << col << ' ';
            }
            cout << endl;
        }
}