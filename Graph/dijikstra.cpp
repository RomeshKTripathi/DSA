#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

vector<int> dijikstra(vector<pair<int, int>> adj[], int V){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> distance(V, 1e6);
    distance[0] = 0;

    q.push({0, 0});

    while(!q.empty()){
        int dis = q.top().first;
        int node = q.top().second;
        q.pop();
        // now traverse all the neighbour nodes of the 'node'

        for(auto it : adj[node]){
            if((dis + it.first) < distance[it.second]){
                distance[it.second] = dis + it.first;
                q.push({(dis + it.first), it.second});
            }
        }
    }
    return distance;
}

int main(){

    vector<pair<int, int>> adj[7];

// Edges from vertex 0
adj[0].push_back({2, 1});
adj[0].push_back({5, 2});

// Edges from vertex 1
adj[1].push_back({3, 3});

// Edges from vertex 2
adj[2].push_back({1, 1});
adj[2].push_back({2, 3});
adj[2].push_back({6, 4});

// Edges from vertex 3
adj[3].push_back({1, 4});
adj[3].push_back({5, 5});

// Edges from vertex 4
adj[4].push_back({1, 1});
adj[4].push_back({3, 5});

// Edges from vertex 5
adj[5].push_back({2, 4});

// Edges from vertex 6
adj[6].push_back({4, 5});



    vector<int> distance = dijikstra(adj, 7);
    for(int i = 0; i < 7; i++) cout << i << "  ->  " << distance[i] << '\n';

}