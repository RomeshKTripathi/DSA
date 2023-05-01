#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class DiractedGraph{
private:
    vector<vector<int>> adj;
    void dfsPrint(int *vis, int node){
        vis[node] = 1;
        cout << node << " ";
        for(auto it : this->adj[node]){
            if(!vis[it])
            {
                dfsPrint(vis, it);
            }
        }

    }

    void bfsPrint(int *vis, int i){
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout << node << " ";
            for(auto it : this->adj[node]){
                if(vis[it] == 0)
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

    }
public:
    DiractedGraph(vector<vector<int>> adj){
        this->adj = adj;
    }
    void print(string type = ""){
        int V = adj.size();
        int vis[V] = {0};
        if(type == "dfs"){
            
            for(int i = 0; i < V; i++){
                if(!vis[i])
                    dfsPrint(vis, i);
            }
        }
        else{
           for(int i = 0; i < V; i++){
                if(!vis[i]){
                    bfsPrint(vis, i);
                }
           }
        }
    }
    
    
    bool detectCycle(){}
    vector<int> topologicalSort()
    {
        int V = this->adj.size();
        int indeg[V] = {0};

        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < V; i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it : adj[curr])
            {
                indeg[it]--;
                if(indeg[it] == 0)
                {
                    q.push(it);
                }
            }

        }

        if(ans.size() == V) return ans;
        return {};

    }
    vector<int> eventualSafeStates(){}


};


int main(){
    vector<vector<int>> graph = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}
    };
        
    DiractedGraph g = DiractedGraph(graph);

    // g.print("bfs");
    vector<int> topo = g.topologicalSort();
    for(auto it : topo) cout << it << " ";
}