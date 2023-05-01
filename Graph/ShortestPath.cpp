#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class GraphFunctions{
    public:
    vector<int> shortestPaths(vector<int> adj[], int size){
        queue<int> q;
        q.push(0);
        vector<int> visited(size, 0);
        vector<int> dist(size, 0);
        visited[0] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : adj[u]){
                if(!visited[v]){
                    visited[v] = 1;
                    dist[v] = u+1;
                    q.push(v);
                }
            }
        }
        return dist;
    }



    bool hasCycle(vector<int> adj[], int V){
        vector<bool> vis(V, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }else return true;
            }
        }
        return false;

    }

    void printGraph(vector<int> adj[], int V){
        for(int i = 0; i < V; i++){
            cout << i << " -> ";
            for(int v : adj[i]){
                cout << v << ", ";
            }
            cout << "\n";
        }
    }
};

int main(){
    vector<int> adj[] = {
        {1, 2, 4},
        {0, 3},
        {0, 3, 4},
        {1, 2, 5},
        {0, 2, 5},
        {3, 4}
    };
    GraphFunctions obj;

    cout << (obj.hasCycle(adj, 6) == 1?"Has Cycle":"No cycle");
    // obj.printGraph(adj, 6);
}