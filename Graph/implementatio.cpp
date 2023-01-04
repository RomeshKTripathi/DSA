#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector<int> adj[], int v){
    for(int i = 0; i< v; i++){
        for(auto x : adj[i]){
            cout << x << "->";
        }
        cout <<endl;
    }
}
void bfs(vector<int> adj[], int size, int head){
    vector<bool> visited(size, false);
    queue<int> q;
    q.push(head);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if( visited[curr]) continue;
        visited[curr] = true;
        cout << curr << ' ';
        for(int x : adj[curr]) q.push(x);
    }
    
}

void dfs(vector<int> adj[], int head, vector<bool> &visited){
    if(visited[head]) return;
    visited[head] = true;
    cout << head << " ";
    for(auto x : adj[head]){
        if(!visited[x])
            dfs(adj, x, visited);
    }
}
int main(){
    int v = 6;
    vector<bool> visited(6, false);
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 5);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    bfs(adj, 6, 0);    
    cout << "Work Done !";
    return 0;
}