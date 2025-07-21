#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int u){
    if(visited[u])
        return;
    cout << u << endl;
    visited[u] = true;

    for(auto v: adj[u]){
        if(!visited[v]){
            dfs(adj, visited, v);
        }
    }
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
    dfs(adj, visited, 0);
    return 0;
}