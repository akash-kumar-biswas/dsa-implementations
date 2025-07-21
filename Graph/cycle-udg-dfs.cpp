#include<bits/stdc++.h>
using namespace std;

bool isCycleDfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u, int parent){
    visited[u] = true;
    for(auto neigh: adj[u]){
        if(neigh != parent && visited[neigh])
            return true;
        if(neigh == parent)
            continue;
        if(isCycleDfs(adj, visited, neigh, u))
            return true;
    }
    return false;
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
    for(int i = 0; i < V; i++){
        if(!visited[i] && isCycleDfs(adj, visited, i, -1)){
            cout << "Cycle Exists" << endl;
            return 0;
        }
    }
    cout << "Cycle doesn't exist" << endl;
    return 0;
}