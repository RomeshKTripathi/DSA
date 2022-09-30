#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


vector<int> query_game(int N, vector<int> A, int Q, vector<vector<int>> P){
    vector<int> res;
    for(int i = 0;i<P.size();i++){
        if(P[i][0] == 1){ //Processing Type 1 query 
            reverse(A.begin(),A.end());
        }

        if(P[i][0] == 2)
        {
            swap(A[P[i][1]-1],A[P[i][2]-1]);
        }

        if(P[i][0] == 3){
            for(int k = 0;k<N;k++){ //Searching element x to output.
                if(A[k] == P[i][1]){
                    res.push_back(k+1);
                    break;
                }
            }
        }
        
    }
    return res;

}


void generateNumbers(int n){
    queue<string> q;
    string curr = "";
    q.push("5");
    q.push("6");
    while(n--){
        curr = q.front();
        q.pop();
        cout<<curr<<endl;
        q.push(curr+"5");
        q.push(curr+"6");
    }
    return ;
}



int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> query = {
        {2,1,2},
        {1,0,0},
        {3,2,0},
    };
    vector<int> res = query_game(3,arr,3,query);
    for(int x:res) 
        cout<<x<<" ";
}