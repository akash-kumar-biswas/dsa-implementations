#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int V, int u){
    queue<int> q;
    vector<int> shortest_path(V, INT_MAX);
    q.push(u);
    visited[u] = true;
    shortest_path[u] = 0;

    while(!q.empty()){
        u = q.front();

        for(auto neigh: adj[u]){
            if(!visited[neigh]){
                q.push(neigh);
                visited[neigh] = true;
                shortest_path[neigh] = shortest_path[u] + 1;
            }
        }
        q.pop();
    }
    return shortest_path;
}

int main(){
    unordered_map<int, vector<int>> adj;   

    int V, E;
    cin >> V >> E;

    for(int i = 0; i < E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(V, false);
    vector<int> shortest_path = bfs(adj, visited, V,  0);

    cout << "Shortest path from vertex 0 to -->\n";
    for(int i = 0; i < V; i++){
        cout << "vertex " << i << ": "<< shortest_path[i] << endl;
    }
    return 0;
}