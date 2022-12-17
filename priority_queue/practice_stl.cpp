#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<int> data = {3,7,2,8,9,5,6,1};
    // Create MIN Heap...!
    priority_queue<int, vector<int>, greater<int>> pq(data.begin(), data.end());
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    
    return 0;
}